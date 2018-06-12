#pragma once

#include  "game/map/Chunk.hpp"
#include  "IMob.hpp"

class World;

class MobSpawner
{
public:
  MobSpawner(World& world);
  ~MobSpawner();

  void    spawnMob(unsigned int offset, double elapsed_time);

private:
  const Chunk*  getChunk(unsigned int offset);
  World&    _world;
  std::map<uint64_t, IMob *> m_builders;
  double    _cd;
};