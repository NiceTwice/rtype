//
// InsideMineBackground.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Fri Dec 30 14:57:52 2016 Adrien Vasseur
// Last update Fri Dec 30 14:57:52 2016 Adrien Vasseur
//

#include    "gui/gfx/InsideMineBackground.hpp"
#include    "gui/res/ResPool.hpp"

InsideMineBackground::InsideMineBackground()
{
  this->_img = nullptr;
}

InsideMineBackground::~InsideMineBackground()
{

}

bool        InsideMineBackground::create()
{
  return ((this->_img = ResPool::getInstance().getImage("background-2-0x0")) != NULL);
}

void        InsideMineBackground::display()
{
  if (this->_img)
  {
    Vector2f pos;

    for (pos.setX(this->_offset); pos.getX() < this->_offset + this->_width; pos.setX(pos.getX() + this->_img->getSize().getX()))
    {
      this->_img->setPosition(pos);
      this->_img->display();
    }
  }
}

void        InsideMineBackground::destroy()
{
  this->_img = NULL;
}