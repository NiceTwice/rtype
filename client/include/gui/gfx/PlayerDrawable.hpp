//
// PlayerDrawable.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 17:52:37 2016 Adrien Vasseur
// Last update Wed Dec 28 17:52:37 2016 Adrien Vasseur
//

#pragma   once

#include <game/map/MovableEntity.hpp>
#include <gui/anim/FadeAnimation.hpp>
#include  "gui/gfx/ADrawable.hpp"
#include  "gui/anim/FrameAnimation.hpp"

#define   DEATH_TIMEOUT 150

class     PlayerDrawable : public ADrawable
{
public:
  PlayerDrawable(MovableEntity *);
  PlayerDrawable();
  ~PlayerDrawable();

  bool    create();
  void    display();
  void    destroy();

  ADrawable *clone(MovableEntity *);

private:
  FrameAnimation  _upAnimation;
  FrameAnimation  _downAnimation;
  FrameAnimation  _deadAnimation;
  FadeAnimation   _aliveAnimation;
  SFMLImage       *_normalMode;

  std::uint64_t    _creationDate;

  void            viewportCollision(Vector2f &) const;
};