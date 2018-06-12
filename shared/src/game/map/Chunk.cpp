//
// Chunk.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 20:03:05 2016 Adrien Vasseur
// Last update Mon Dec 26 20:03:05 2016 Adrien Vasseur
//

#include    <stdexcept>
#include    "game/map/Chunk.hpp"

Chunk::Chunk()
{

}

Chunk::~Chunk()
{
  for (std::size_t ite = 0; ite < this->_entities.size(); ite++)
    delete this->_entities.at(ite);
}

void        Chunk::addEntity(const MapEntity *entity)
{
  this->_entities.push_back(entity);
}

void        Chunk::setBackground(std::uint8_t background)
{
  this->_background = background;
}

void        Chunk::setWidth(std::uint32_t width)
{
  if (width < 100)
    throw std::invalid_argument("Chunk width cannot be less than 100 pixels");
  this->_width = width;
}

void        Chunk::setType(const std::string &type)
{
  this->_type = type;
}

const std::vector<const MapEntity *>  &Chunk::getEntities() const
{
	return (this->_entities);
}

std::uint8_t Chunk::getBackground() const
{
	return (this->_background);
}

std::uint32_t Chunk::getWidth() const
{
	return (this->_width);
}

const std::string   &Chunk::getType() const
{
  return (this->_type);
}