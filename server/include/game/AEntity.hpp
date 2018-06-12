//
// AEntity.hpp for RTYPE - Shared in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/shared/include/game
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 10:57:31 2016 Quentin Guerin
// Last update Fri Dec 02 10:57:32 2016 Quentin Guerin
//

#pragma once

# include "game/Vector2f.hpp"

class AEntity
{
public:
  AEntity(void);
  ~AEntity(void);

public:
  unsigned int const& getId() const;
  Vector2f const& getPosition() const;
  Vector2f const& getDirection() const;

  void setId(unsigned int const&);
  void setPosition(Vector2f const&);
  void setDirection(Vector2f const&);

protected:
  Vector2f m_position;
  Vector2f m_direction;
  unsigned int m_id;
};