//
// GameCore.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/core/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 14:09:57 2016 Adrien Vasseur
// Last update Thu Dec  1 11:46:21 2016 Adrien Vasseur
//

#include	"core/GameCore.hpp"
#include  "net/Network.hpp"

template<> GameCore*	Singleton<GameCore>::INSTANCE = new GameCore();

GameCore::GameCore()
{
  this->_map = NULL;
  this->_mapOffset = 0;
  this->_firing = false;
  this->_netReady = false;
  this->_gameReady = false;
  this->_ready = false;
  this->_players = 0;
  this->_readyPlayers = 0;
  this->_life = 3;
  this->_end = 0;
}

GameCore::~GameCore()
{
  if (this->_map.load() != NULL)
    delete this->_map.load();
}

void 	  GameCore::setMap(Map *value)
{
  this->_map = value;
}

const Map *GameCore::getMap() const
{
  return (this->_map);
}

uint64_t  GameCore::getMapOffset() const
{
  return (this->_mapOffset);
}

void    GameCore::setMapOffset(uint64_t value)
{
  this->_mapOffset = value;
}

Player    &GameCore::getPlayer()
{
  return (this->_player);
}

std::map<uint64_t, MovableEntity *> *GameCore::getEntities()
{
  std::map<uint64_t, MovableEntity *> *entities;
  
  this->_mutex.lock();
  entities = new std::map<uint64_t, MovableEntity *>(this->_entities);
  this->_mutex.unlock();
  return (entities);
}

void GameCore::setEntities(const std::map<uint64_t, MovableEntity *> *value)
{
  this->_mutex.lock();
  this->_entities = *value;
  this->_mutex.unlock();
}

void 	  GameCore::setFiring(bool value)
{
  this->_firing = value;
}

bool GameCore::isFiring() const
{
  return (this->_firing);
}

void 	  GameCore::setPlayerDir(const Vector2f &value)
{
  this->_playerDir = value;
}

const Vector2f &GameCore::getPlayerDir() const
{
  return (this->_playerDir);
}

void    GameCore::setNetReady(bool value)
{
  this->_netReady = value;
}

bool GameCore::isNetReady() const
{
  return (this->_netReady);
}

void    GameCore::setGameReady(bool value)
{
  this->_gameReady = value;
}

bool GameCore::isGameReady() const
{
  return (this->_gameReady);
}

void    GameCore::setPlayers(uint16_t value)
{
  this->_players = value;
}

uint16_t GameCore::getPlayers() const
{
  return (this->_players);
}

void    GameCore::setReadyPlayers(uint16_t value)
{
  this->_readyPlayers = value;
}

uint16_t GameCore::getReadyPlayers() const
{
  return (this->_readyPlayers);
}

void    GameCore::setLife(uint32_t value)
{
  this->_life = value;
}

uint32_t GameCore::getLife() const
{
  return (this->_life);
}

void    GameCore::setEnd(uint8_t value)
{
  this->_end = value;
}

uint8_t GameCore::getEnd() const
{
  return (this->_end);
}

void GameCore::ready()
{
  this->_ready = !this->_ready;
  Network::getInstance().ready(this->_ready);
}

bool  GameCore::isReady() const
{
  return (this->_ready);
}