//
// MovableEntity.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 13:41:49 2016 Adrien Vasseur
// Last update Wed Dec 28 13:41:49 2016 Adrien Vasseur
//

#pragma   once

#include  "game/map/MapEntity.hpp"

class     MovableEntity : public MapEntity
{
public:
  MovableEntity();
  ~MovableEntity();

  void    setVelocity(float);
  void    setDir(const Vector2f &);
  void	  setLastUpdate(uint64_t);
  void    setDeleted(bool);

  float   getVelocity() const;
  const Vector2f  &getDir() const;
  uint64_t getLastUpdate() const;
  bool    getDeleted() const;

private:
  float   _velocity;
  Vector2f  _dir;
  std::atomic<uint64_t>	_lastUpdate;
  std::atomic<bool> _deleted;
};