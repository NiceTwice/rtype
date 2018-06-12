//
// ATCPSocket.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 23 13:23:34 2016 Quentin Guerin
// Last update Fri Dec 23 13:23:35 2016 Quentin Guerin
//

#pragma once

# include "net/ASocket.hpp"
# include "net/AUDPSocket.hpp"
# include "net/ANetClient.hpp"

class ATCPSocket: public ASocket
{
public:
  ATCPSocket();
  virtual ~ATCPSocket();

public:
  virtual ANetClient<ATCPSocket, AUDPSocket> *accept(void);

protected:
  virtual bool _bind(void);
  virtual bool _listen(void);

  SOCKET& _getSocketRef(void);
  SocketAddress& _getSocketAddressRef(void);
};