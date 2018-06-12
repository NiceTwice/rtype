//
// ServerSocket.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 18:26:48 2016 Quentin Guerin
// Last update Fri Dec 02 18:26:49 2016 Quentin Guerin
//

#include <iostream>
#include "net/TCPServerSocket.hpp"

TCPServerSocket::TCPServerSocket(): ATCPSocket()
{
}

/**
 * Destructor
 */

TCPServerSocket::~TCPServerSocket()
{
}

bool TCPServerSocket::run(void)
{
  this->_setRunning(this->_listen());
  return (this->isRunning());
}