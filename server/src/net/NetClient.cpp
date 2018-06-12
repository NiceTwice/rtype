//
// NetClient.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 19:43:20 2016 Quentin Guerin
// Last update Fri Dec 02 19:43:21 2016 Quentin Guerin
//

#include <iostream>
#include <string.h>
#include "exceptions/SocketException.hpp"
#include "net/NetClient.hpp"
#include "net/Poll.hpp"

/**
 * @param ASocket* sock Client socket
 *
 * Constructor of class NetClient
 *   If sock not nullptr
 *     Initialize and start it
 */

NetClient::NetClient(ATCPSocket *sock): ANetClient(sock)
{
}

/**
 * Destructor of class NetClient
 */

NetClient::~NetClient()
{
}

/**
 * @param const NetworkCommunicationType type Type of communication
 * @return int64_t Length of sent data
 *
 * Send method to call internal send
 */

int64_t NetClient::send(const NetworkCommunicationType type)
{
  uint64_t size = 0;
  const char *data = nullptr;

  if (type == NetworkCommunicationType::TCP)
    data = this->m_sendingTCP.retrieveOneLine(size);
  else
    data = this->m_sendingUDP.retrieveOneLine(size);

  if (size > 0 && data != nullptr) {
#if (defined _WIN32) || (defined WIN32)
    size = this->ANetClient::send(type, data, size, 0);
#else
    size = this->ANetClient::send(type, data, size, MSG_NOSIGNAL);
#endif
    delete [] data;
  }
  else
    size = 0;
  if (type == NetworkCommunicationType::TCP) {
    if (this->hasDataBufferized(NetworkCommunicationType::TCP) == false && this->m_pollfdTCP != nullptr &&
        (this->m_pollfdTCP->events & POLLOUT))
      this->m_pollfdTCP->events ^= POLLOUT;
  }
  else {
    if (this->hasDataBufferized(NetworkCommunicationType::UDP) == false && this->m_pollfdUDP != nullptr &&
        (this->m_pollfdUDP->events & POLLOUT))
      this->m_pollfdUDP->events ^= POLLOUT;
  }
  return (static_cast<int64_t>(size));
}

/**
 * @param const NetworkCommunicationType type Type of communication
 * @return int64_t Length of received data
 *
 * Recv method to call internal recv
 */

int64_t NetClient::recv(const NetworkCommunicationType type)
{
  void *data = nullptr;
  int64_t size = BUFFER_SIZE;

  try {
    data = new char[BUFFER_SIZE];
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    return (-1);
  }
  memset(data, 0, size);
  size = this->ANetClient::recv(type, data, size, 0);
  if (size > 0) {
    if (type == NetworkCommunicationType::TCP)
      this->m_receivedTCP.insert((const char *)data, size);
    else {
      this->m_receivedUDP.insert((const char *)data, size);
    }
  }
  else
    delete [] reinterpret_cast<char *>(data);
  return (size);
}

/**
 * @param const NetworkCommunicationType type Type of communication
 * @return const char* Size bytes received (or less)
 * @param uint64_t& size Number of bytes to retrieve
 *
 * Retrieve data from ring buffer
 */

const char *NetClient::retrieve(const NetworkCommunicationType type, uint64_t& size, bool consume)
{
  if (type == NetworkCommunicationType::TCP)
    return (this->m_receivedTCP.retrieve(size, consume));
  else
    return (this->m_receivedUDP.retrieve(size, consume));
}

/**
 * @param const NetworkCommunicationType type Type of communication
 * @param const void* data Data to bufferize
 * @param uint64_t size Number of bytes to bufferize
 *
 * Insert data in ringbuffer
 */

void NetClient::bufferize(const NetworkCommunicationType type, const char *data, uint64_t size)
{
  if (type == NetworkCommunicationType::TCP) {
    this->m_sendingTCP.insert(data, size);
    if (this->m_pollfdTCP != nullptr)
      this->m_pollfdTCP->events |= POLLOUT;
  }
  else {
    this->m_sendingUDP.insert(data, size);
    if (this->m_pollfdUDP != nullptr)
      this->m_pollfdUDP->events |= POLLOUT;
  }
}

/**
 * @param const NetworkCommunicationType type Type of communication
 * @param std::string const& data Data to bufferize
 *
 * Insert data in ringbuffer
 */

void NetClient::bufferize(const NetworkCommunicationType type, std::string const& data)
{
  if (type == NetworkCommunicationType::TCP) {
    this->m_sendingTCP.insert(data);
    if (this->m_pollfdTCP != nullptr)
      this->m_pollfdTCP->events |= POLLOUT;
  }
  else {
    this->m_sendingUDP.insert(data);
    if (this->m_pollfdUDP != nullptr)
      this->m_pollfdUDP->events |= POLLOUT;
  }
}

bool NetClient::hasDataBufferized(const NetworkCommunicationType type) const
{
  if (type == NetworkCommunicationType::TCP)
    return (this->m_sendingTCP.hasData());
  else
    return (this->m_sendingUDP.hasData());
}