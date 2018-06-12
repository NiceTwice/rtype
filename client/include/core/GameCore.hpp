//
// GameCore.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/core/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 14:08:56 2016 Adrien Vasseur
// Last update Wed Nov 30 15:43:29 2016 Adrien Vasseur
//

#pragma		once

#include	<map>
#include    <atomic>
#include	"tools/Singleton.hpp"
#include	"thread/StdMutex.hpp"
#include    "game/Vector2f.hpp"
#include    "game/Player.hpp"
#include    "game/map/Map.hpp"
#include    "game/map/MovableEntity.hpp"


class		GameCore : public Singleton<GameCore>
{
public:
  GameCore();
  ~GameCore();

public:
  void      setMap(Map *);
  const Map *getMap() const;
  void      setMapOffset(uint64_t);
  uint64_t  getMapOffset() const;
  Player    &getPlayer();
  std::map<uint64_t, MovableEntity *> *getEntities();
  void      setEntities(const std::map<uint64_t, MovableEntity *> *);
  void      setFiring(bool);
  bool      isFiring() const;
  void      setPlayerDir(const Vector2f &);
  const Vector2f &getPlayerDir() const;
  void      setNetReady(bool);
  bool      isNetReady() const;
  void      setGameReady(bool);
  bool      isGameReady() const;
  void      setPlayers(uint16_t);
  uint16_t  getPlayers() const;
  void      setReadyPlayers(uint16_t);
  uint16_t  getReadyPlayers() const;
  void      setLife(uint32_t);
  uint32_t  getLife() const;
  void      setEnd(uint8_t);
  uint8_t  getEnd() const;
  void      ready();
  bool      isReady() const;

private:
  StdMutex			  _mutex;
  Player              _player;
  std::map<uint64_t, MovableEntity *> _entities;
  std::atomic<Map *>  _map;
  std::atomic<uint64_t>    _mapOffset;
  std::atomic<bool>	  _firing;
  Vector2f _playerDir;
  std::atomic<bool>   _netReady;
  std::atomic<bool>   _gameReady;
  std::atomic<uint16_t>   _players;
  std::atomic<uint16_t>   _readyPlayers;
  std::atomic<uint32_t>   _life;
  std::atomic<uint32_t>   _end;
  bool _ready;
};
