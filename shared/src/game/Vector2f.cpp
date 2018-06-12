//
// Vector2f.cpp for rtype in /home/lanquemar/rendu/rtype/shared/src/game/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 12:16:47 2016 Adrien Vasseur
// Last update Thu Dec  1 22:55:47 2016 Adrien Vasseur
//

#include    <cmath>
#include	"game/Vector2f.hpp"

Vector2f::Vector2f()
{
  this->_x = 0;
  this->_y = 0;
}

Vector2f::Vector2f(float x, float y)
{
  this->_x = x;
  this->_y = y;
}

Vector2f::Vector2f(const Vector2f &copy)
{
  this->_x = copy.getX();
  this->_y = copy.getY();
}

Vector2f	&Vector2f::operator=(const Vector2f &a)
{
  this->setX(a.getX());
  this->setY(a.getY());
  return (*this);
}

Vector2f	&Vector2f::operator=(const float a)
{
  this->setX(a);
  this->setY(a);
  return (*this);
}

Vector2f	&Vector2f::operator+=(const Vector2f &a)
{
  this->setX(this->getX() + a.getX());
  this->setY(this->getY() + a.getY());
  return (*this);
}

Vector2f	&Vector2f::operator+=(const float a)
{
  this->setX(this->getX() + a);
  this->setY(this->getY() + a);
  return (*this);
}

Vector2f	&Vector2f::operator-=(const Vector2f &a)
{
  this->setX(this->getX() - a.getX());
  this->setY(this->getY() - a.getY());
  return (*this);
}

Vector2f	&Vector2f::operator-=(const float a)
{
  this->setX(this->getX() - a);
  this->setY(this->getY() - a);
  return (*this);
}

Vector2f	&Vector2f::operator*=(const Vector2f &a)
{
  this->setX(this->getX() * a.getX());
  this->setY(this->getY() * a.getY());
  return (*this);
}

Vector2f	&Vector2f::operator*=(const float a)
{
  this->setX(this->getX() * a);
  this->setY(this->getY() * a);
  return (*this);
}

Vector2f	&Vector2f::operator/=(const Vector2f &a)
{
  this->setX(this->getX() / a.getX());
  this->setY(this->getY() / a.getY());
  return (*this);
}

Vector2f	&Vector2f::operator/=(const float a)
{
  this->setX(this->getX() / a);
  this->setY(this->getY() / a);
  return (*this);
}

void		Vector2f::setX(float x)
{
  this->_x = x;
}

void		Vector2f::setY(float y)
{
  this->_y = y;
}

float		Vector2f::getX() const
{
  return (this->_x);
}

float		Vector2f::getY() const
{
  return (this->_y);
}

void        Vector2f::normalize()
{
  float     lenght;

  lenght = std::sqrt(this->_x * this->_x + this->_y * this->_y);
  if (lenght != 0)
  {
    this->_x = this->_x / lenght;
    this->_y = this->_y / lenght;
  }
}

Vector2f	operator+(const Vector2f &a, const Vector2f &b)
{
  return (Vector2f(a.getX() + b.getX(), a.getY() + b.getY()));
}

Vector2f	operator+(const Vector2f &a, const float b)
{
  return (Vector2f(a.getX() + b, a.getY() + b));
}

Vector2f	operator-(const Vector2f &a, const Vector2f &b)
{
  return (Vector2f(a.getX() - b.getX(), a.getY() - b.getY()));
}

Vector2f	operator-(const Vector2f &a, const float b)
{
  return (Vector2f(a.getX() - b, a.getY() - b));
}

Vector2f	operator*(const Vector2f &a, const Vector2f &b)
{
  return (Vector2f(a.getX() * b.getX(), a.getY() * b.getY()));
}

Vector2f	operator*(const Vector2f &a, const float b)
{
  return (Vector2f(a.getX() * b, a.getY() * b));
}

Vector2f	operator/(const Vector2f &a, const Vector2f &b)
{
  return (Vector2f(a.getX() / b.getX(), a.getY() / b.getY()));
}

Vector2f	operator/(const Vector2f &a, const float b)
{
  return (Vector2f(a.getX() / b, a.getY() / b));
}

bool		operator==(const Vector2f &a, const Vector2f &b)
{
  return (a.getX() == b.getX() && a.getY() == b.getY());
}

bool		operator==(const Vector2f &a, const float b)
{
  return (a.getX() == b && a.getY() == b);
}

bool		operator!=(const Vector2f &a, const Vector2f &b)
{
  return (!(a == b));
}

bool		operator!=(const Vector2f &a, const float b)
{
  return (!(a == b));
}

std::ostream	&operator<<(std::ostream &os, const Vector2f &data)
{
  os << "Vector2f(" << data.getX() << ", " << data.getY() << ")";
  return (os);
}
