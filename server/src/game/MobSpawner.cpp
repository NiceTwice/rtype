#include  <map>
#include  "game/MobSpawner.hpp"
#include  "game/World.hpp"
#include "loader/LoadManager.hpp"
#include "exceptions/LoadManagerException.hpp"

MobSpawner::MobSpawner(World& world) : _world(world)
{
    this->_cd = 500;
    try {
      std::map<uint64_t, IMob *>::const_iterator it;
      this->m_builders = LoadManager::getInstance().update().getBuilders();

      for (it = this->m_builders.begin(); it != this->m_builders.end(); ++it) {
        std::cerr << "[LOADED MOB] UID[" << it->first << "] -> pointer = " << (void *)(it->second) << std::endl;
      }
    }
    catch (LoadManagerException const& e) {
      std::cerr << "[ERROR] Failed to get loaded libraries: " << e.what() << std::endl;
      throw e;
    }
}

MobSpawner::~MobSpawner()
{

}

void      MobSpawner::spawnMob(unsigned int offset, double elapsed_time)
{
  const Chunk* chunk = this->getChunk(offset);

  this->_cd -= elapsed_time;
  if (this->_cd <= 0)
  {
    if (chunk == NULL)
      return;
    for (auto it = this->m_builders.begin(); it != this->m_builders.end(); ++it) {
      if (it->second->getType() == chunk->getType())
        this->_world.getFactory().createMob(this->_world, it->second);
    }
    this->_cd = 500;
  }
}

const Chunk*    MobSpawner::getChunk(unsigned int offset)
{
  unsigned int  chunk_count = 0;

  for (auto& chunk : this->_world.getMap()->getChunks())
  {
    chunk_count += chunk->getWidth();
    if (offset < chunk_count)
      return (chunk);
  }
  return (NULL);
}