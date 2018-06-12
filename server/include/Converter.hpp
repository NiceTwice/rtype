//
// Converter.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Mon Dec 19 17:30:53 2016 Quentin Guerin
// Last update Mon Dec 19 17:30:56 2016 Quentin Guerin
//

#pragma once

# include "net/ATCPSocket.hpp"
# include "net/AUDPSocket.hpp"
# include "net/ANetClient.hpp"
# include "thread/StdMutex.hpp"
# include "game/Player.hpp"
# include "game/Entity.hpp"

class Converter
{
public:
  Converter(void);
  ~Converter(void);

public:
  Player &getPlayer(void);
  Player const& getPlayer(void) const;
  ANetClient<ATCPSocket, AUDPSocket> *getClient(void) const;

  void setPlayerEntity(Entity *);
  void setClient(ANetClient<ATCPSocket, AUDPSocket> *);

  void lock();
  void unlock();

private:
  StdMutex _mutex;
  Player m_player;
  ANetClient<ATCPSocket, AUDPSocket> *m_client;
};