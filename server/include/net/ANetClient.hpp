//
// ANetClient.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 22 10:32:26 2016 Quentin Guerin
// Last update Thu Dec 22 10:32:28 2016 Quentin Guerin
//

#pragma once

# include <cstdlib>
# include <string>
# include <cstdint>
# include "net/INetClient.hpp"
# include "net/Poll.hpp"
# include "exceptions/SocketException.hpp"
# include "exceptions/NetClientException.hpp"
# include "net/SocketAddress.hpp"

enum NetworkCommunicationType {
  TCP,
  UDP
};

template <typename TCP, typename UDP>
class ANetClient: public INetClient
{
public:

  /**
   * @param T* sock Client socket
   *
   * Constructor of class ANetClient
   *   If sock not nullptr
   *     Initialize and start it
   */

  ANetClient(TCP *sock): m_sockTCP(sock), m_sockUDP(nullptr), m_pollfdTCP(nullptr), m_pollfdUDP(nullptr), m_serverPoll(nullptr)
  {
    if (this->m_sockTCP != nullptr)
      {
	if (this->m_sockTCP->init() == false ||
	    this->m_sockTCP->run() == false)
	  throw SocketException("Failed to init/run in NetClient");
      }
    else
      throw NetClientException("invalid socket");
  }

  /**
   * Destructor of class ANetClient
   * Delete socket
   */

  virtual ~ANetClient()
  {
    this->disconnect();
    if (this->m_sockTCP != nullptr) {
      this->disconnect();
      delete this->m_sockTCP;
    }
    if (this->m_sockUDP != nullptr) {
      delete this->m_sockUDP;
    }
  }

  /**
   * @return bool Success of operation (ALWAYS true)
   * @param std::string const& ip Ip to connect
   * @param unsigned short const& port Port to connect
   *
   * Binding for connect (fake, already connected here)
   */

  bool connect(const std::string &ip = "", unsigned short const& port = 0) final
  {
    (void)ip;
    (void)port;
    return (true);
  }

  /**
   * Stop socket
   */

  void disconnect(void) final
  {
    if (this->m_sockTCP != nullptr)
      this->m_sockTCP->stop();
    if (this->m_sockUDP != nullptr)
      this->m_sockUDP->stop();
  }

  bool buildUDP(SocketAddress targetTCP, uint16_t port)
  {
    bool success = false;
    SocketAddress targetUDP;
    WSAPOLLFD *fd;

    std::cerr << "[INFO] TCP (IP) = " << targetTCP.getIp() << std::endl;
    targetUDP.setHost(targetTCP.getIp(), port);
    std::cerr << "[INFO] UDP (IP) = " << targetUDP.getIp() << std::endl;
    this->m_sockUDP = new UDP();
    this->m_sockUDP->setPort(0u);
    this->m_sockUDP->setTarget(targetUDP);
    success = this->m_sockUDP->init();
    try {
      fd = new WSAPOLLFD();
    }
    catch (std::exception const& e) {
      std::cerr << "[ERROR] " << e.what() << std::endl;
      return (false);
    }
    fd->fd = this->getSocketUDP()->getSocket();
    fd->events = POLLIN;
    fd->revents = 0;
    this->linkPollFd(NetworkCommunicationType::UDP, fd);
    this->m_serverPoll->addFd(fd);
    return (success);
  }

  ANetClient<TCP, UDP>& setServerPoll(Poll *poll)
  {
    this->m_serverPoll = poll;
    return (*this);
  }

  ANetClient<TCP, UDP>& resetServerPoll(void)
  {
    this->m_serverPoll = nullptr;
    return (*this);
  }

  TCP *getSocketTCP(void) const
  {
    return (this->m_sockTCP);
  }

  void resetSocketUDP(void)
  {
    if (this->hasUDP()) {
      delete this->m_sockUDP;
      this->m_sockUDP = nullptr;
    }
  }

  UDP *getSocketUDP(void) const
  {
    return (this->m_sockUDP);
  }

  void linkPollFd(const NetworkCommunicationType type, struct pollfd *pollfd)
  {
    if (type == NetworkCommunicationType::TCP)
      this->m_pollfdTCP = pollfd;
    else
      this->m_pollfdUDP = pollfd;
  }

  WSAPOLLFD *getPollFd(const NetworkCommunicationType type)
  {
    if (type == NetworkCommunicationType::TCP)
      return (this->m_pollfdTCP);
    else
      return (this->m_pollfdUDP);
  }

  /**
   * @return int number of byte received
   * @param const NetworkCommunicationType type Type of communication
   * @param void* data Buffer in which to receive
   * @param uint64_t size Number of bytes to receive
   * @param int flags Flags
   *
   * Recv method to call internal recv (from socket)
   */

  int recv(const NetworkCommunicationType type, void *data, uint64_t size, int flags)
  {
    SocketAddress saddr;

    if (type == NetworkCommunicationType::TCP)
      return (this->m_sockTCP->recv(data, size, flags));
    else if (this->m_sockUDP != nullptr) {
      int ret = this->m_sockUDP->recvfrom(data, size, flags, saddr);
      if (saddr == this->m_sockUDP->getTarget())
	throw NetClientException("Invalid sender");
      return (ret);
    }
    else
      throw NetClientException("UDP not initialized");
  }

  /**
   * @return int number of byte sent
   * @param const NetworkCommunicationType type Type of communication
   * @param void* data Buffer containing the data to be send
   * @param uint64_t size Number of bytes to send
   * @param int flags Flags
   *
   * Send method to call internal send (from socket)
   */

  int send(const NetworkCommunicationType type, const void *data, uint64_t size, int flags)
  {
    if (type == NetworkCommunicationType::TCP)
      return (this->m_sockTCP->send(data, size, flags));
    else if (this->m_sockUDP != nullptr)
      return (this->m_sockUDP->sendto(data, size, flags, this->m_sockUDP->getTarget()));
    else
      throw NetClientException("UDP not initialized");
  }

  bool hasServerPollPtr(void)
  {
    return (this->m_serverPoll != nullptr);
  }

  bool hasUDP(void) const
  {
    return (this->m_sockUDP != nullptr);
  }

  virtual int64_t send(const NetworkCommunicationType) = 0;
  virtual int64_t recv(const NetworkCommunicationType) = 0;

  virtual const char *retrieve(const NetworkCommunicationType, uint64_t&, bool = true) = 0;

  virtual void bufferize(const NetworkCommunicationType, const char *, uint64_t) = 0;
  virtual void bufferize(const NetworkCommunicationType, std::string const&) = 0;

  virtual bool hasDataBufferized(const NetworkCommunicationType) const = 0;

private:
  TCP *m_sockTCP;
  UDP *m_sockUDP;

protected:
  WSAPOLLFD *m_pollfdTCP;
  WSAPOLLFD *m_pollfdUDP;
  Poll *m_serverPoll;
};