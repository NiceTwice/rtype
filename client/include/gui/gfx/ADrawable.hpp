//
// ADrawable.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 17:59:27 2016 Adrien Vasseur
// Last update Wed Dec 28 17:59:27 2016 Adrien Vasseur
//

#pragma   once

#include  <cstdint>
#include <game/map/MovableEntity.hpp>
#include  "gui/IView.hpp"

class     ADrawable : public IView
{
public:
  ADrawable(MovableEntity *);
  ~ADrawable();

  virtual ADrawable *clone(MovableEntity *);

protected:
  MovableEntity   *_entity;
};