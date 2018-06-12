//
// NetClient.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 17:43:18 2016 Quentin Guerin
// Last update Fri Dec 02 17:43:19 2016 Quentin Guerin
//

#pragma once

# include "net/ATCPSocket.hpp"
# include "net/AUDPSocket.hpp"
# include "net/ANetClient.hpp"
# include "net/RingBuffer.hpp"

# define BUFFER_SIZE 128

class NetClient: public ANetClient<ATCPSocket, AUDPSocket>
{
public:
  NetClient(ATCPSocket *);
  ~NetClient();

public:
  int64_t send(const NetworkCommunicationType) final;
  int64_t recv(const NetworkCommunicationType) final;

  const char *retrieve(const NetworkCommunicationType, uint64_t&, bool = true) final;

  void bufferize(const NetworkCommunicationType, const char *, uint64_t) final;
  void bufferize(const NetworkCommunicationType, std::string const&) final;

  bool hasDataBufferized(const NetworkCommunicationType) const final;

private:
  RingBuffer m_receivedTCP;
  RingBuffer m_sendingTCP;
  RingBuffer m_receivedUDP;
  RingBuffer m_sendingUDP;
};