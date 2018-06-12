//
// Converter.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Mon Dec 19 18:00:46 2016 Quentin Guerin
// Last update Mon Dec 19 18:00:47 2016 Quentin Guerin
//

#include "Converter.hpp"

Converter::Converter(): m_client(nullptr)
{
}

Converter::~Converter()
{
  if (this->m_client != nullptr)
    delete this->m_client;
}

Player &Converter::getPlayer(void)
{
  return (this->m_player);
}

Player const& Converter::getPlayer(void) const
{
  return (this->m_player);
}

ANetClient<ATCPSocket, AUDPSocket> *Converter::getClient(void) const
{
  return (this->m_client);
}

void Converter::setPlayerEntity(Entity *entity)
{
  this->m_player.setEntity(entity);
}

void Converter::setClient(ANetClient<ATCPSocket, AUDPSocket> *client)
{
  this->m_client = client;
}

void Converter::lock()
{
  this->_mutex.lock();
}

void Converter::unlock()
{
  this->_mutex.unlock();
}