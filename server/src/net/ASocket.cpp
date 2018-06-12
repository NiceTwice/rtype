//
// ASocket.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 22 14:35:28 2016 Quentin Guerin
// Last update Thu Dec 22 14:35:29 2016 Quentin Guerin
//

#include "net/ASocket.hpp"

ASocket::ASocket(void): m_running(false), m_sock(INVALID_SOCKET)
{
}

ASocket::~ASocket(void)
{
  this->stop();
}

/**
 * @return bool Success of operation
 *
 * Initializer
 */

bool ASocket::init(void)
{
  return (this->_bind());
}

/**
 * @return bool Success of operation
 *
 * Start
 */

bool ASocket::run(void)
{
  this->m_running = true;
  return (this->m_running);
}

/**
 * @return bool Success of operation
 *
 * Stop the socket (close)
 */

bool ASocket::stop(void)
{
  this->_close();
  this->m_running = false;
  return (true);
}

/**
 * @return int number of byte received
 * @param void* data Buffer in which to receive
 * @param uint64_t size Number of bytes to receive
 * @param int flags Flags
 *
 * Binding for recv
 */

int64_t ASocket::recv(void *data, uint64_t size, int flags)
{
  return (::recv(this->m_sock, reinterpret_cast<char *>(data), size, flags));
}

/**
 * @return int number of byte sent
 * @param void* data Buffer containing the data to be send
 * @param uint64_t size Number of bytes to send
 * @param int flags Flags
 *
 * Binding for send
 */

int64_t ASocket::send(const void *data, uint64_t size, int flags)
{
  std::cerr << "[SEND] Sending " << size << " bytes" << std::endl;
  return (::send(this->m_sock, reinterpret_cast<const char *>(data), size, flags));
}

ASocket& ASocket::findSocketAddress(void)
{
  SOCKADDR_IN saddr;
  SOCKLEN_T addrlen = sizeof(SOCKADDR_IN);

  if (::getsockname(this->getSocket(), reinterpret_cast<SOCKADDR *>(&saddr), &addrlen) == 0)
    this->m_saddr = SocketAddress(saddr);
  return (*this);
}

ASocket& ASocket::setPort(uint16_t port)
{
  this->m_saddr.setPort(port);
  return (*this);
}

/**
 * Close the socket
 */

void ASocket::_close(void)
{
#ifdef __linux__
  ::close(this->m_sock);
#else
  ::closesocket(this->m_sock);
#endif
}

/**
 * @return SOCKET const& Socket
 *
 * Getter for socket
 */

SOCKET const& ASocket::getSocket(void) const
{
  return (this->m_sock);
}

/**
 * @return SocketAddress const& SocketAddress
 *
 * Getter for socketaddress
 */

SocketAddress const& ASocket::getSocketAddress(void) const
{
  return (this->m_saddr);
}

bool const& ASocket::isRunning(void) const
{
  return (this->m_running);
}

ASocket& ASocket::_setRunning(bool running)
{
  this->m_running = running;
  return (*this);
}