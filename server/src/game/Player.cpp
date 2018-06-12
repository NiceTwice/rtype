//
// Player.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/game
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Sun Jan 01 15:05:44 2017 Quentin Guerin
// Last update Sun Jan 01 15:05:46 2017 Quentin Guerin
//

#include "game/Player.hpp"

Player::Player(uint32_t life): m_life(life), m_entity(nullptr), m_world(nullptr), m_ready(false)
{
}

Player::~Player(void)
{
}

Player &Player::removeLife(uint32_t life)
{
  this->m_mutex.lock();
  this->m_life = (this->m_life > life ? this->m_life - life : 0);
  this->m_deadTime = std::chrono::steady_clock::now();
  this->m_mutex.unlock();
  return (*this);
}

Player &Player::setEntity(Entity *entity)
{
  this->m_mutex.lock();
  this->m_entity = entity;
  if (entity != nullptr)
    this->m_spawnTime = std::chrono::steady_clock::now();
  this->m_mutex.unlock();
  return (*this);
}

Player &Player::setWorld(World *world)
{
  this->m_mutex.lock();
  this->m_world = world;
  this->m_mutex.unlock();
  return (*this);
}

Player &Player::setReady(bool ready)
{
  this->m_mutex.lock();
  this->m_ready = ready;
  this->m_mutex.unlock();
  return (*this);
}

Entity *Player::getEntity(void)
{
  Entity *entity = nullptr;

  this->m_mutex.lock();
  entity = this->m_entity;
  this->m_mutex.unlock();
  return (entity);
}

uint32_t Player::getLife(void)
{
  uint32_t life = 0;

  this->m_mutex.lock();
  life = this->m_life;
  this->m_mutex.unlock();
  return (life);
}

World *Player::getWorld(void)
{
  World *world = nullptr;

  this->m_mutex.lock();
  world = this->m_world;
  this->m_mutex.unlock();
  return (world);
}

bool Player::isReady(void)
{
  bool ready = false;

  this->m_mutex.lock();
  ready = this->m_ready;
  this->m_mutex.unlock();
  return (ready);
}

const std::chrono::steady_clock::time_point Player::getDeadTime(void)
{
  std::chrono::steady_clock::time_point time;

  this->m_mutex.lock();
  time = this->m_deadTime;
  this->m_mutex.unlock();
  return (time);
}

const std::chrono::steady_clock::time_point Player::getSpawnTime(void)
{
  std::chrono::steady_clock::time_point time;

  this->m_mutex.lock();
  time = this->m_spawnTime;
  this->m_mutex.unlock();
  return (time);
}