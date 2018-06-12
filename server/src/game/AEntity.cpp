//
// AEntity.cpp for RTYPE - Shared in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/shared/src/game
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 11:04:55 2016 Quentin Guerin
// Last update Fri Dec 02 11:04:56 2016 Quentin Guerin
//

#include "game/AEntity.hpp"

AEntity::AEntity(void): m_position(0, 0), m_direction(0, 0), m_id(0)
{
}

AEntity::~AEntity(void)
{
}

Vector2f const& AEntity::getPosition(void) const
{
  return (this->m_position);
}

Vector2f const& AEntity::getDirection(void) const
{
  return (this->m_direction);
}

unsigned int const& AEntity::getId(void) const
{
  return (this->m_id);
}

void AEntity::setPosition(Vector2f const& pos)
{
  this->m_position = pos;
}

void AEntity::setDirection(Vector2f const& dir)
{
  this->m_direction = dir;
}

void AEntity::setId(unsigned int const& id)
{
  this->m_id = id;
}