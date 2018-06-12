//
// ADrawable.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 18:00:18 2016 Adrien Vasseur
// Last update Wed Dec 28 18:00:18 2016 Adrien Vasseur
//

#include    "gui/gfx/ADrawable.hpp"

ADrawable::ADrawable(MovableEntity *entity) : _entity(entity)
{

}

ADrawable::~ADrawable()
{

}

ADrawable *ADrawable::clone(MovableEntity *)
{
  return (nullptr);
}