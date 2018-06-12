//
// AUDPSocket.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 23 13:23:34 2016 Quentin Guerin
// Last update Fri Dec 23 13:23:35 2016 Quentin Guerin
//

#pragma once

# include "net/ASocket.hpp"

class AUDPSocket: public ASocket
{
public:
  AUDPSocket();
  virtual ~AUDPSocket();

public:
  virtual int64_t sendto(const void *, uint64_t, int, SocketAddress const&);
  virtual int64_t recvfrom(void *, uint64_t, int, SocketAddress&);

  bool setRecvBufferSize(int);
  bool setReuseAddress(bool);
  AUDPSocket& setTarget(SocketAddress const&);

  SocketAddress getPeerName() const;
  SocketAddress const& getTarget(void) const;

protected:
  virtual bool _bind(void);

  SOCKET& _getSocketRef(void);
  SocketAddress& _getSocketAddressRef(void);

private:
  SocketAddress m_target;
};