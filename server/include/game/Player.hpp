//
// Player.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/game
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Sun Jan 01 15:05:29 2017 Quentin Guerin
// Last update Sun Jan 01 15:05:30 2017 Quentin Guerin
//

#pragma once

# include "thread/StdMutex.hpp"
# include "game/Entity.hpp"

class Player
{
public:
  Player(uint32_t = 3);
  ~Player(void);

  Player &removeLife(uint32_t = 1);
  Player &setEntity(Entity *);
  Player &setWorld(World *);
  Player &setReady(bool = true);

  bool isReady(void);
  Entity *getEntity(void);
  uint32_t getLife(void);
  World *getWorld(void);
  const std::chrono::steady_clock::time_point getDeadTime(void);
  const std::chrono::steady_clock::time_point getSpawnTime(void);

private:
  StdMutex m_mutex;
  uint32_t m_life;
  Entity *m_entity;
  World *m_world;
  std::atomic<bool> m_ready;
  std::chrono::steady_clock::time_point m_deadTime;
  std::chrono::steady_clock::time_point m_spawnTime;
};