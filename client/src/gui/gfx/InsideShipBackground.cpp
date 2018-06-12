//
// InsideShipBackground.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 10:31:07 2016 Adrien Vasseur
// Last update Wed Dec 28 10:31:07 2016 Adrien Vasseur
//

#include    "gui/gfx/InsideShipBackground.hpp"
#include    "gui/res/ResPool.hpp"
#include    "gui/MainWindow.hpp"

InsideShipBackground::InsideShipBackground()
{
  this->_img = NULL;
}

InsideShipBackground::~InsideShipBackground()
{

}

bool	    InsideShipBackground::create()
{
  return ((this->_img = ResPool::getInstance().getImage("background-1-0x0")) != NULL);
}

void	    InsideShipBackground::display()
{
  if (this->_img)
  {
    Vector2f pos;

    for (pos.setX(this->_offset); pos.getX() < this->_offset + this->_width; pos.setX(pos.getX() + this->_img->getSize().getX()))
    {
      for (pos.setY(0); pos.getY() < MainWindow::getInstance().getHeight(); pos.setY(pos.getY() + this->_img->getSize().getY()))
      {
        this->_img->setPosition(pos);
        this->_img->display();
      }
    }
  }
}

void	    InsideShipBackground::destroy()
{
  this->_img = NULL;
}