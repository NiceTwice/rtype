//
// SFMLRectangle.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 17:20:12 2016 Adrien Vasseur
// Last update Thu Dec 15 17:20:12 2016 Adrien Vasseur
//

#pragma     once

#include	<SFML/Graphics.hpp>
#include	"game/Vector2f.hpp"

class       SFMLRectangle
{
public:
  SFMLRectangle();
  ~SFMLRectangle();

  void      setSize(const Vector2f &);
  void		setPosition(const Vector2f &);
  void      setColor(float, float, float, float);
  void      display();

  const Vector2f      &getPosition() const;

private:
  Vector2f            _size;
  Vector2f            _pos;
  sf::RectangleShape  _rectangle;
};