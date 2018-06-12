//
// MobDrawable.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 17:26:48 2016 Adrien Vasseur
// Last update Sat Dec 31 17:26:48 2016 Adrien Vasseur
//

#pragma   once

#include <game/map/MovableEntity.hpp>
#include <gui/anim/FrameAnimation.hpp>
#include "ADrawable.hpp"

class     MobDrawable : public ADrawable
{
public:
  MobDrawable(unsigned int, MovableEntity *);
  MobDrawable(unsigned int);
  ~MobDrawable();

  bool    create();
  void    display();
  void    destroy();

  ADrawable *clone(MovableEntity *);

private:
  FrameAnimation  _lifeAnimation;
  FrameAnimation  _deadAnimation;

  std::int64_t    _dieOffset;
  Vector2f        _diePos;

  unsigned int    _spriteRef;
};