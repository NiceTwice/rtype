//
// Map.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 19:51:40 2016 Adrien Vasseur
// Last update Mon Dec 26 19:51:40 2016 Adrien Vasseur
//

#pragma   once

#include  <cstddef>
#include  <vector>
#include  "game/map/Chunk.hpp"

class     World;

class     Map
{
public:
  Map(const std::string &);
  ~Map();

  void    addChunk(const Chunk *);

  void    setViewport(const Vector2f &);

  const Vector2f &getViewport() const;
  const std::vector<const Chunk *>  &getChunks() const;

private:
  std::string _name;
  std::vector<const Chunk *>  _chunks;
  Vector2f    _viewport;
};