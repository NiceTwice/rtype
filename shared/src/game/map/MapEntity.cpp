//
// MapEntity.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 22:35:40 2016 Adrien Vasseur
// Last update Mon Dec 26 22:35:40 2016 Adrien Vasseur
//

#include    "game/map/MapEntity.hpp"

MapEntity::MapEntity()
{

}

MapEntity::~MapEntity()
{

}

void        MapEntity::setSprite(std::uint16_t sprite)
{
  this->_sprite = sprite;
}

void        MapEntity::setPosition(const Vector2f &pos)
{
  this->_position = pos;
}

void        MapEntity::setSize(const Vector2f &size)
{
  if (size.getX() < 1 || size.getY() < 1)
    throw std::invalid_argument("Map entity size be less than 1x1");
  this->_size = size;
}

std::uint16_t MapEntity::getSprite() const
{
  return (this->_sprite);
}

const Vector2f  &MapEntity::getPosition() const
{
  return (this->_position);
}

const Vector2f  &MapEntity::getSize() const
{
  return (this->_size);
}