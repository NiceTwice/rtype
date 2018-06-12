//
// TCPServerSocket.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 18:15:24 2016 Quentin Guerin
// Last update Fri Dec 02 18:15:25 2016 Quentin Guerin
//

#pragma once

# include "net/ATCPSocket.hpp"

class TCPServerSocket: public ATCPSocket
{
public:
  TCPServerSocket();
  ~TCPServerSocket();

public:

  bool run(void);
};