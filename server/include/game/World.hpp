#pragma once

#include <map>
#include	<chrono>
#include	"game/Entity.hpp"
#include	"game/EntityFactory.hpp"
#include	"game/system/ASystem.hpp"
#include	"game/system/SystemManager.hpp"
#include	"game/map/Map.hpp"
#include  "thread/StdMutex.hpp"
#include  "Converter.hpp"
#include "IMob.hpp"
#include  "game/MobSpawner.hpp"
#include  "loader/LoadManager.hpp"

# define RESPAWN_DELAY 3
# define INVINCIBILITY_DURATION 3

class Map;

class ASystem;

class World
{
public:
	World(uint16_t);
	~World();

  void      addEntity(Entity* entity);
  void    respawn(Converter *player);
  void		destroyEntity(Entity* entity);
  bool    createPlayer(Converter* player);
  const std::vector<Converter *> &getPlayerList() const;
  unsigned int	getPlayerCount() const;
  unsigned int  getPlayerReady();
  bool		isRunning() const;
  void		run();
  void		update();
	void    disconnectPlayer(Converter *player);
  const Map *getMap() const;

  EntityFactory     &getFactory();
  uint16_t getNextSpriteId() const;
  bool    inUpdate();
	uint64_t	getOffset();
  bool full(void) const;
  bool empty(void) const;

  void lock();
  void unlock();

private:
  void spawnHandling(std::chrono::steady_clock::time_point const&);
  bool endGame(void);
  void insertEntity(PacketSerializer &, Entity *);

private:
  std::chrono::steady_clock::time_point	_clock;
  StdMutex _mutex;
  uint16_t m_playerLimit;
  EntityFactory			_factory;
  SystemManager     _systemManager;
  MobSpawner        _spawner;
  std::vector<Entity *>	_entityList;
  std::vector<Converter *> _playerList;
  unsigned int		_player_count;
  std::atomic<bool>						_running;
	unsigned int		_offset;
  std::atomic<bool> _update;
  std::atomic<bool> _ended;

  const Map                *_map;
};
