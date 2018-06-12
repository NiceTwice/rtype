//
// MapEntity.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 22:34:38 2016 Adrien Vasseur
// Last update Mon Dec 26 22:34:38 2016 Adrien Vasseur
//

#pragma   once

#include  <cstddef>
#include  "game/Vector2f.hpp"

class     MapEntity
{
public:
  MapEntity();
  ~MapEntity();

  void    setSprite(std::uint16_t);
  void    setPosition(const Vector2f &);
  void    setSize(const Vector2f &);

  std::uint16_t   getSprite() const;
  const Vector2f  &getPosition() const;
  const Vector2f  &getSize() const;

private:
  std::uint16_t   _sprite;
  Vector2f  _position;
  Vector2f  _size;
};