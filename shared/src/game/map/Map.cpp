//
// Map.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 19:52:12 2016 Adrien Vasseur
// Last update Mon Dec 26 19:52:12 2016 Adrien Vasseur
//

#include    "game/map/Map.hpp"

Map::Map(const std::string &name) : _name(name)
{

}

Map::~Map()
{
  for (std::size_t ite = 0; ite < this->_chunks.size(); ite++)
    delete this->_chunks.at(ite);
}

void        Map::addChunk(const Chunk *chunk)
{
  this->_chunks.push_back(chunk);
}

void        Map::setViewport(const Vector2f &viewport)
{
  if (viewport.getX() < 100 || viewport.getY() < 100)
    throw std::invalid_argument("Map viewport cannot be less than 100x100");
  this->_viewport = viewport;
}

const Vector2f &Map::getViewport() const
{
	return (this->_viewport);
}

const std::vector<const Chunk *>  &Map::getChunks() const
{
	return (this->_chunks);
}