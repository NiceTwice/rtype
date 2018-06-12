//
// ImageDrawable.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 29 17:59:36 2016 Adrien Vasseur
// Last update Thu Dec 29 17:59:36 2016 Adrien Vasseur
//

#include <tools/Chrono.hpp>
#include    "gui/gfx/ImageDrawable.hpp"
#include    "gui/res/ResPool.hpp"

ImageDrawable::ImageDrawable(const std::string &name, MovableEntity *entity) : ADrawable(entity), _name(name)
{

}

ImageDrawable::ImageDrawable(const std::string &name, const std::string &cloneMusicName) : ADrawable(nullptr), _name(name), _cloneMusicName(cloneMusicName)
{

}

ImageDrawable::~ImageDrawable()
{

}

bool        ImageDrawable::create()
{
  return (true);
}

void        ImageDrawable::display()
{
  SFMLImage *img;

  if ((img = ResPool::getInstance().getImage(this->_name)) != NULL)
  {
    img->setPosition(this->_entity->getPosition() + this->_entity->getDir() * this->_entity->getVelocity() * Chrono::getDiffTime(this->_entity->getLastUpdate()));
    img->display();
  }
  if (Chrono::getDiffTime(this->_entity->getLastUpdate()) > 100)
    this->_entity->setDeleted(true);
}

void        ImageDrawable::destroy()
{

}

ADrawable   *ImageDrawable::clone(MovableEntity *entity)
{
  if (this->_cloneMusicName.size() > 0 && ResPool::getInstance().getMusic(this->_cloneMusicName) != NULL)
    ResPool::getInstance().getMusic(this->_cloneMusicName)->start();
  return (new ImageDrawable(this->_name, entity));
}

const std::string &ImageDrawable::getName() const
{
  return (this->_name);
}