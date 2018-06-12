//
// Chunk.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 19:57:54 2016 Adrien Vasseur
// Last update Mon Dec 26 19:57:54 2016 Adrien Vasseur
//

#pragma   once

#include  <cstddef>
#include  <vector>
#include  "game/map/MapEntity.hpp"

class     Chunk
{
public:
  Chunk();
  ~Chunk();

  void    addEntity(const MapEntity *);

  void    setBackground(std::uint8_t);
  void    setWidth(std::uint32_t);
  void    setType(const std::string &);

  const std::vector<const MapEntity *>  &getEntities() const;
  std::uint8_t 	  getBackground() const;
  std::uint32_t   getWidth() const;
  const std::string &getType() const;

private:
  std::vector<const MapEntity *>  _entities;
  std::uint8_t                    _background;
  std::uint32_t                   _width;
  std::string                     _type;
};