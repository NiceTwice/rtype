//
// MobDrawable.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 17:28:10 2016 Adrien Vasseur
// Last update Sat Dec 31 17:28:10 2016 Adrien Vasseur
//

#include <tools/Chrono.hpp>
#include <gui/gfx/PlayerDrawable.hpp>
#include    "gui/gfx/MobDrawable.hpp"
#include    "gui/res/ResPool.hpp"
#include    "core/GameCore.hpp"

MobDrawable::MobDrawable(unsigned int spriteRef, MovableEntity *entity) : ADrawable(entity), _spriteRef(spriteRef)
{
  this->_dieOffset = 0;
}

MobDrawable::MobDrawable(unsigned int spriteRef) : ADrawable(nullptr), _spriteRef(spriteRef)
{
  this->_dieOffset = 0;
}

MobDrawable::~MobDrawable()
{

}

bool        MobDrawable::create()
{
  if (ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-0x0") != NULL &&
      ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-1x0") != NULL &&
      ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-2x0") != NULL &&
      ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-3x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-0x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-1x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-2x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-3x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-4x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2-5x0") != NULL)
  {
    this->_lifeAnimation.addFrame(ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-0x0"));
    this->_lifeAnimation.addFrame(ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-1x0"));
    this->_lifeAnimation.addFrame(ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-2x0"));
    this->_lifeAnimation.addFrame(ResPool::getInstance().getImage("mob-" + std::to_string(this->_spriteRef) + "-3x0"));
    this->_lifeAnimation.setRepeated(true);
    this->_lifeAnimation.setInterval(200);
    this->_lifeAnimation.start();
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-0x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-1x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-2x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-3x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-4x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2-5x0"));
    this->_deadAnimation.setRepeated(false);
    this->_deadAnimation.setInterval(100);
  }
  return (true);
}

void        MobDrawable::display()
{
  Vector2f  newPos;

  if (Chrono::getDiffTime(this->_entity->getLastUpdate()) < DEATH_TIMEOUT)
  {
    newPos = this->_entity->getPosition() + this->_entity->getDir() * this->_entity->getVelocity() * Chrono::getDiffTime(this->_entity->getLastUpdate());
    this->_lifeAnimation.setPosition(newPos);
    this->_lifeAnimation.display();
  }
  else if (Chrono::getDiffTime(this->_entity->getLastUpdate()) < DEATH_TIMEOUT + 650)
  {
    if (this->_dieOffset == 0)
    {
      this->_diePos = this->_entity->getPosition() + this->_entity->getDir() * this->_entity->getVelocity() * DEATH_TIMEOUT;
      this->_dieOffset = GameCore::getInstance().getMapOffset();
      this->_deadAnimation.start();
    }
    newPos = this->_diePos;
    newPos.setX(newPos.getX() + (float) (this->_dieOffset - (std::int64_t) GameCore::getInstance().getMapOffset()));
    this->_deadAnimation.setPosition(newPos);
    this->_deadAnimation.display();
  }
  else
    this->_entity->setDeleted(true);
}

void        MobDrawable::destroy()
{
}

ADrawable   *MobDrawable::clone(MovableEntity *entity)
{
  return (new MobDrawable(this->_spriteRef, entity));
}