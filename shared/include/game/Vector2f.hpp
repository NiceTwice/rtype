//
// Vector2f.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/game/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 12:06:45 2016 Adrien Vasseur
// Last update Thu Dec  1 22:56:42 2016 Adrien Vasseur
//

#pragma		once

#include <atomic>
#include	<ostream>

class		Vector2f
{
public:
  Vector2f();
  Vector2f(float, float);
  Vector2f(const Vector2f &);

  Vector2f	&operator=(const Vector2f &);
  Vector2f	&operator=(const float);
  Vector2f	&operator+=(const Vector2f &);
  Vector2f	&operator+=(const float);
  Vector2f	&operator-=(const Vector2f &);
  Vector2f	&operator-=(const float);
  Vector2f	&operator*=(const Vector2f &);
  Vector2f	&operator*=(const float);
  Vector2f	&operator/=(const Vector2f &);
  Vector2f	&operator/=(const float);

  void		setX(float);
  void		setY(float);
  float 	getX() const;
  float	    getY() const;

  void      normalize();

private:
  std::atomic<float> _x;
  std::atomic<float> _y;
};

Vector2f	operator+(const Vector2f &, const Vector2f &);
Vector2f	operator+(const Vector2f &, const float);
Vector2f	operator-(const Vector2f &, const Vector2f &);
Vector2f	operator-(const Vector2f &, const float);
Vector2f	operator*(const Vector2f &, const Vector2f &);
Vector2f	operator*(const Vector2f &, const float);
Vector2f	operator/(const Vector2f &, const Vector2f &);
Vector2f	operator/(const Vector2f &, const float);
bool		operator==(const Vector2f &, const Vector2f &);
bool		operator==(const Vector2f &, const float);
bool		operator!=(const Vector2f &, const Vector2f &);
bool		operator!=(const Vector2f &, const float);
std::ostream &operator<<(std::ostream &, const Vector2f &);
