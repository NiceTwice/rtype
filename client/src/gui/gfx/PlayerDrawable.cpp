//
// PlayerDrawable.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 17:54:04 2016 Adrien Vasseur
// Last update Wed Dec 28 17:54:04 2016 Adrien Vasseur
//

#include <tools/Chrono.hpp>
#include <gui/MainWindow.hpp>
#include    "gui/gfx/PlayerDrawable.hpp"
#include    "gui/res/ResPool.hpp"


PlayerDrawable::PlayerDrawable(MovableEntity *entity) : ADrawable(entity)
{

}

PlayerDrawable::PlayerDrawable() : ADrawable(nullptr)
{

}

PlayerDrawable::~PlayerDrawable()
{

}

bool        PlayerDrawable::create()
{
  if (ResPool::getInstance().getImage("ship-0x" + std::to_string(this->_entity->getSprite())) != NULL &&
      ResPool::getInstance().getImage("ship-1x" + std::to_string(this->_entity->getSprite())) != NULL &&
      ResPool::getInstance().getImage("ship-2x" + std::to_string(this->_entity->getSprite())) != NULL &&
      ResPool::getInstance().getImage("ship-3x" + std::to_string(this->_entity->getSprite())) != NULL &&
      ResPool::getInstance().getImage("ship-4x" + std::to_string(this->_entity->getSprite())) != NULL &&
      ResPool::getInstance().getImage("explosion-0x0") != NULL &&
      ResPool::getInstance().getImage("explosion-1x0") != NULL &&
      ResPool::getInstance().getImage("explosion-2x0") != NULL &&
      ResPool::getInstance().getImage("explosion-3x0") != NULL &&
      ResPool::getInstance().getImage("explosion-4x0") != NULL &&
      ResPool::getInstance().getImage("explosion-5x0") != NULL &&
      ResPool::getInstance().getImage("explosion-6x0") != NULL)
  {
    this->_downAnimation.addFrame(ResPool::getInstance().getImage("ship-2x" + std::to_string(this->_entity->getSprite())));
    this->_downAnimation.addFrame(ResPool::getInstance().getImage("ship-1x" + std::to_string(this->_entity->getSprite())));
    this->_downAnimation.addFrame(ResPool::getInstance().getImage("ship-0x" + std::to_string(this->_entity->getSprite())));
    this->_downAnimation.setRepeated(false);
    this->_downAnimation.setInterval(200);
    this->_upAnimation.addFrame(ResPool::getInstance().getImage("ship-2x" + std::to_string(this->_entity->getSprite())));
    this->_upAnimation.addFrame(ResPool::getInstance().getImage("ship-3x" + std::to_string(this->_entity->getSprite())));
    this->_upAnimation.addFrame(ResPool::getInstance().getImage("ship-4x" + std::to_string(this->_entity->getSprite())));
    this->_upAnimation.setRepeated(false);
    this->_upAnimation.setInterval(200);
    this->_aliveAnimation.setImage(ResPool::getInstance().getImage("ship-2x" + std::to_string(this->_entity->getSprite())));
    this->_aliveAnimation.setInterval(500);
    this->_aliveAnimation.setRepeated(true);
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-0x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-1x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-2x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-3x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-4x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-5x0"));
    this->_deadAnimation.addFrame(ResPool::getInstance().getImage("explosion-6x0"));
    this->_deadAnimation.setRepeated(false);
    this->_deadAnimation.setInterval(100);
    this->_normalMode = ResPool::getInstance().getImage("ship-2x" + std::to_string(this->_entity->getSprite()));
  }
  this->_creationDate = Chrono::getCurrentTime();
  return (true);
}

void        PlayerDrawable::viewportCollision(Vector2f &vec) const
{
  if (vec.getX() < 0)
    vec.setX(0);
  if (vec.getY() < 0)
    vec.setY(0);
  if (vec.getX() > MainWindow::getInstance().getWidth() - this->_normalMode->getSize().getX())
    vec.setX(MainWindow::getInstance().getWidth() - this->_normalMode->getSize().getX());
  if (vec.getY() > MainWindow::getInstance().getHeight() - this->_normalMode->getSize().getY())
    vec.setY(MainWindow::getInstance().getHeight() - this->_normalMode->getSize().getY());
}

void        PlayerDrawable::display()
{
  Vector2f  newPos;

  if (Chrono::getDiffTime(this->_entity->getLastUpdate()) < DEATH_TIMEOUT)
  {
    newPos = this->_entity->getPosition() + this->_entity->getDir() * this->_entity->getVelocity() * Chrono::getDiffTime(this->_entity->getLastUpdate());
    viewportCollision(newPos);
    if (Chrono::getDiffTime(this->_creationDate) < 3000)
    {
      if (!this->_aliveAnimation.isRunning())
        this->_aliveAnimation.start();
      this->_aliveAnimation.setPosition(newPos);
      this->_aliveAnimation.display();
    }
    else if (this->_entity->getDir().getY() < 0.0f)
    {
      if (!this->_upAnimation.isRunning())
        this->_upAnimation.start();
      this->_upAnimation.setPosition(newPos);
      this->_upAnimation.display();
      this->_downAnimation.stop();
    }
    else if (this->_entity->getDir().getY() > 0.0f)
    {
      if (!this->_downAnimation.isRunning())
        this->_downAnimation.start();
      this->_downAnimation.setPosition(newPos);
      this->_downAnimation.display();
      this->_upAnimation.stop();
    }
    else
    {
      this->_normalMode->setPosition(newPos);
      this->_normalMode->display();
      this->_upAnimation.stop();
      this->_downAnimation.stop();
    }
  }
  else if (Chrono::getDiffTime(this->_entity->getLastUpdate()) < DEATH_TIMEOUT + 650)
  {
    if (!this->_deadAnimation.isRunning())
      this->_deadAnimation.start();
    this->_deadAnimation.setPosition(this->_entity->getPosition() + this->_entity->getDir() * this->_entity->getVelocity() * DEATH_TIMEOUT);
    this->_deadAnimation.display();
  }
  else
    this->_entity->setDeleted(true);
}

void        PlayerDrawable::destroy()
{
}

ADrawable   *PlayerDrawable::clone(MovableEntity *entity)
{
  return (new PlayerDrawable(entity));
}