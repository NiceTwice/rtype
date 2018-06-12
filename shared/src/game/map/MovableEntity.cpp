//
// MovableEntity.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 13:44:26 2016 Adrien Vasseur
// Last update Wed Dec 28 13:44:26 2016 Adrien Vasseur
//

#include    "game/map/MovableEntity.hpp"

MovableEntity::MovableEntity()
{
  this->_deleted = false;
}

MovableEntity::~MovableEntity()
{

}

void        MovableEntity::setVelocity(float velocity)
{
  this->_velocity = velocity;
}

void        MovableEntity::setDir(const Vector2f &dir)
{
  this->_dir = dir;
}

void        MovableEntity::setLastUpdate(uint64_t lastUpdate)
{
  this->_lastUpdate = lastUpdate;
}

void        MovableEntity::setDeleted(bool deleted)
{
  this->_deleted = deleted;
}

float       MovableEntity::getVelocity() const
{
  return (this->_velocity);
}

const Vector2f  &MovableEntity::getDir() const
{
  return (this->_dir);
}

uint64_t       MovableEntity::getLastUpdate() const
{
  return (this->_lastUpdate);
}

bool           MovableEntity::getDeleted() const
{
  return (this->_deleted);
}
