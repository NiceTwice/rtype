//
// TCPClientSocket.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 18:26:59 2016 Quentin Guerin
// Last update Fri Dec 02 18:27:00 2016 Quentin Guerin
//

#include "net/TCPClientSocket.hpp"

TCPClientSocket::TCPClientSocket(void): ATCPSocket()
{
}

/**
 * @param SOCKET const& sock Socket
 *
 * Constructor from SOCKET and SOCKADDR_IN (result of accept)
 */

TCPClientSocket::TCPClientSocket(SOCKET const& sock, SOCKADDR_IN *saddr): ATCPSocket()
{
  SOCKET &internalSock = this->_getSocketRef();
  SocketAddress &internalSocketAddress = this->_getSocketAddressRef();

  internalSock = sock;
  internalSocketAddress = SocketAddress(*saddr);
}

/**
 * Destructor
 */

TCPClientSocket::~TCPClientSocket()
{
}

/**
 * @return bool Success of operation
 *
 * Initializer
 */

bool TCPClientSocket::init(void)
{
  return (true);
}