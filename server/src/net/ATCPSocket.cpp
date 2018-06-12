//
// ATCPSocket.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 23 13:35:38 2016 Quentin Guerin
// Last update Fri Dec 23 13:35:39 2016 Quentin Guerin
//

#include "net/ATCPSocket.hpp"
#include "net/TCPClientSocket.hpp"
#include "net/NetClient.hpp"

ATCPSocket::ATCPSocket()
{
}

/**
 * Destructor
 */

ATCPSocket::~ATCPSocket()
{
}

/**
 * @return ANetClient<ASocket>* Client accepted
 *
 * Binding for accept
 *   On client connection, build a new TCPClientSocket and link it to a TCPClient under ANetClient<ASocket>*
 *   On error returns nullptr
 */

ANetClient<ATCPSocket, AUDPSocket> *ATCPSocket::accept(void)
{
  SOCKADDR_IN sin;
  SOCKLEN_T len = 0;
  SOCKET sock = INVALID_SOCKET;
  ANetClient<ATCPSocket, AUDPSocket> *client = nullptr;

  len = sizeof(SOCKADDR_IN);
  memset(&sin, 0, sizeof(sin));
  if ((sock = ::accept(this->m_sock, (SOCKADDR *)&sin, &len)) == INVALID_SOCKET)
    throw SocketException("Unable to accept new connection");

  try {
    client = new NetClient(new TCPClientSocket(sock, &sin));
  }
  catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
    return (nullptr);
  }

  return (client);
}

/**
 * @return bool Success of operation
 *
 * Binding for bind
 */

bool ATCPSocket::_bind(void)
{
  SOCKET sock;

  this->_close();
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    throw SocketException("Unable to create socket");
  else
    this->m_sock = sock;
  if (::bind(this->m_sock, (SOCKADDR *)&(this->m_saddr.getAddressInfo()),
       sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    throw SocketException("Unable to bind socket on this port.");
  return (true);
}

/**
 * @return bool Success of operation
 *
 * Binding for listen
 */

bool ATCPSocket::_listen(void)
{
  if (::listen(this->m_sock, SOMAXCONN) == SOCKET_ERROR)
    throw SocketException("Unable to listen on this port.");
  return (true);
}

SOCKET& ATCPSocket::_getSocketRef(void)
{
  return (this->m_sock);
}

SocketAddress& ATCPSocket::_getSocketAddressRef(void)
{
  return (this->m_saddr);
}