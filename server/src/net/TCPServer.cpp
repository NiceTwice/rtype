//
// TCPServer.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/srcs
//
// Made by Tom CZAYKA
// Login	<tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#define	_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <errno.h>
#include "net/TCPServer.hpp"
#include "net/TCPServerSocket.hpp"

TCPServer::TCPServer(ACore *parent) throw(TCPServerException): m_parent(parent), m_sock(nullptr)
{
#if (defined _WIN32) || (defined WIN32)
  WSADATA wsa;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    throw TCPServerException("Unable to startup WSA");
#endif
}

/**
 * Destructor (stop the socket)
 */

TCPServer::~TCPServer()
{
  if (this->m_sock != nullptr)
    delete this->m_sock;
  while (this->m_clients.size() > 0) {
    delete (*(this->m_clients.begin()));
    this->m_clients.erase(this->m_clients.begin());
  }
#if (defined _WIN32) || (defined WIN32)
  WSACleanup();
#endif
}

/**
 * @return bool Success of operation
 * @param unsigned short const& port Port to bind
 *
 * Initializer
 */

bool  TCPServer::bind(unsigned short port, int timeout)
{
  bool ret;
  WSAPOLLFD *fd = new WSAPOLLFD;

  memset(fd, 0, sizeof(WSAPOLLFD));
  try
  {
    this->m_sock = new TCPServerSocket();
    this->m_sock->setPort(port);
    ret = this->m_sock->init();
    if (ret == false)
      return (false);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return (false);
  }
  fd->fd = this->m_sock->getSocket();
  fd->events = POLLIN;
  this->m_poll.setTimeout(timeout);
  this->m_poll.addFd(fd);
  if (this->m_sock == nullptr ||
      this->m_sock->run() == false) {
    return (false);
  }
  return (true);
}

bool TCPServer::init()
{
  return (true);
}

bool TCPServer::_poll(void)
{
  int ret;

  if ((ret = this->m_poll.poll()) > 0) {
    std::vector<WSAPOLLFD *> fds;
    std::vector<WSAPOLLFD *>::iterator it;

    fds = this->m_poll.getFds();
    for (it = fds.begin(); it != fds.end(); ++it) {
      if ((*it)->fd == this->m_sock->getSocket()) {
	if ((*it)->revents & POLLIN) {
	  ANetClient<ATCPSocket, AUDPSocket> *newClient;

	  if ((newClient = this->m_sock->accept()) != nullptr) {
	    if (this->_addNewClient(newClient) == false)
	    return (false);
	  }
	}
      }
      else {
	if ((*it)->revents & POLLHUP) {
	  (void)this->_disconnect((*it));
	  return (true);
	}
	else if ((*it)->revents & POLLIN) {
	  int64_t size;

	  if ((size = this->_inputReceived(*it)) == 0) {
	    (void)this->_disconnect((*it));
	    return (true);
	  }
	  else if (size < 0) {
	    std::cerr << "[ERROR] _inputReceived returned: " << strerror(errno) << std::endl;
	    return (false);
	  }
	}
	else if ((*it)->revents & POLLOUT) {
	  if (this->_outputOpen(*it) == false) {
	    std::cerr << "[ERROR] _outputOpen returned: " << strerror(errno) << std::endl;
	    return (false);
	  }
	}
      }
    }
  }
  if (ret == INVALID_SOCKET)
    std::cerr << "[ERROR] Poll returned error: " << strerror(errno) << std::endl;
  return (ret != INVALID_SOCKET);
}


bool  TCPServer::listen()
{
  return (this->_poll());
}

void  TCPServer::cancel()
{
  this->stop();
}

/**
 * @return void
 *
 * Start the server
 */

void TCPServer::run()
{
  (void)this->listen();
}

/**
 * @return bool Success of operation
 * @param ANetClient<ASocket>* newClient New connecting client
 *
 * Handle a new network client
 */

bool TCPServer::_addNewClient(ANetClient<ATCPSocket, AUDPSocket> *newClient)
{
  WSAPOLLFD *fd = new WSAPOLLFD();
  Converter *converter = new Converter();

  newClient->setServerPoll(&(this->m_poll));
  fd->fd = newClient->getSocketTCP()->getSocket();
  fd->events = POLLIN;
  fd->revents = 0;
  newClient->linkPollFd(NetworkCommunicationType::TCP, fd);
  converter->setClient(newClient);
  this->m_poll.addFd(fd);
  this->m_clients.push_front(converter);
  this->m_parent->clientConnected(converter);
  return (true);
}

int TCPServer::_disconnect(WSAPOLLFD *tcpFd)
{
  int success;
  WSAPOLLFD *udpFd = nullptr;
  std::list<Converter *>::iterator itClients;

  success = 0;
  for (itClients = this->m_clients.begin(); itClients != this->m_clients.end(); ++itClients) {
    if ((*itClients)->getClient()->getSocketTCP()->getSocket() == tcpFd->fd) {
      udpFd = (*itClients)->getClient()->getPollFd(NetworkCommunicationType::UDP);
      this->m_parent->clientDisconnected(*(itClients));
      delete (*itClients);
      this->m_clients.erase(itClients);
      success = 1;
      break;
    }
  }
  if (success == 1) {
    this->m_poll.erase(tcpFd);
    delete tcpFd;
    if (udpFd != nullptr) {
      this->m_poll.erase(udpFd);
      delete udpFd;
      success = 2;
    }
    std::cerr << "[DISCONNECTION] Client disconnected [" << success << "]" << std::endl;
  }
  return (success);
}

/**
 * @return int64_t Size of data received
 * @param WSAPOLLFD* fd Structure pollfd of inputed user
 *
 * Call _inputReceived for the right client
 */

int64_t TCPServer::_inputReceived(WSAPOLLFD *fd) const
{
  std::list<Converter *>::const_iterator itClients;

  for (itClients = this->m_clients.begin(); itClients != this->m_clients.end(); ++itClients) {
    if ((*itClients)->getClient()->getSocketTCP()->getSocket() == fd->fd) {
      return (this->_inputReceived(NetworkCommunicationType::TCP, *itClients));
    }
    else if ((*itClients)->getClient()->getSocketUDP() != nullptr &&
	     (*itClients)->getClient()->getSocketUDP()->getSocket() == fd->fd) {
      return (this->_inputReceived(NetworkCommunicationType::UDP, *itClients));
    }
  }
  return (0);
}

/**
 * @return bool Success of operation
 * @param WSAPOLLFD* fd Structure pollfd of outputable user
 *
 * Call _outputOpen for the right client
 */

bool TCPServer::_outputOpen(WSAPOLLFD *fd) const
{
  std::list<Converter *>::const_iterator itClients;

  for (itClients = this->m_clients.begin(); itClients != this->m_clients.end(); ++itClients) {
    if ((*itClients)->getClient()->getSocketTCP()->getSocket() == fd->fd) {
      return (this->_outputOpen(NetworkCommunicationType::TCP, *itClients));

    }
    else if ((*itClients)->getClient()->getSocketUDP() != nullptr &&
	     (*itClients)->getClient()->getSocketUDP()->getSocket() == fd->fd)
      return (this->_outputOpen(NetworkCommunicationType::UDP, *itClients));
  }
  return (false);
}

/**
 * @return int64_t Size of data received
 * @param Converter* client Client
 *
 * Read input and put it in client circular buffer
 */

int64_t TCPServer::_inputReceived(const NetworkCommunicationType type, Converter *client) const
{
  int64_t size;

  size = client->getClient()->recv(type);
  if (this->m_parent != nullptr && size > 0)
    this->m_parent->dataReceived(type, client);
  return (size);
}

/**
 * @return bool Success of operation
 * @param Converter* client Client
 *
 * Send data in circular buffer
 */

bool TCPServer::_outputOpen(const NetworkCommunicationType type, Converter *client) const
{
  int64_t size;

  size = client->getClient()->send(type);
  return (size >= 0);
}