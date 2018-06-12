//
// TCPClientSocket.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 18:15:11 2016 Quentin Guerin
// Last update Fri Dec 02 18:15:12 2016 Quentin Guerin
//

#pragma once

# include "net/ATCPSocket.hpp"

class TCPClientSocket: public ATCPSocket
{
public:
  TCPClientSocket(void);
  TCPClientSocket(SOCKET const&, SOCKADDR_IN *);
  ~TCPClientSocket();

public:
  bool init(void);
};
