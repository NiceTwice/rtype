//
// BlueStarsBackground.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 17:43:38 2016 Adrien Vasseur
// Last update Thu Dec 15 17:43:38 2016 Adrien Vasseur
//

#include <iostream>
#include    "tools/Random.hpp"
#include    "gui/MainWindow.hpp"
#include    "gui/gfx/BlueStarsBackground.hpp"
#include    "core/GameCore.hpp"

BlueStarsBackground::BlueStarsBackground()
{
  this->_lastWidth = 0;
  this->_lastHeight = 0;
}

BlueStarsBackground::~BlueStarsBackground()
{
  destroy();
}

bool	  BlueStarsBackground::create()
{
  unsigned int  blueMax = (unsigned int) (MainWindow::getInstance().getWidth() * RATIO_BLUE_STARS) + 1;
  unsigned int  whiteMax = (unsigned int) (MainWindow::getInstance().getWidth() * RATIO_WHITE_STARS) + 1;

  this->_lastWidth = MainWindow::getInstance().getWidth();
  this->_lastHeight = MainWindow::getInstance().getHeight();
  destroy();
  for (unsigned int i = 0; i < blueMax; i++)
  {
    SFMLRectangle *tmp = new SFMLRectangle();

    tmp->setSize(Vector2f(1, 1));
    tmp->setPosition(Vector2f(Random::getNextInteger(0, MainWindow::getInstance().getWidth()), Random::getNextInteger(0, MainWindow::getInstance().getHeight())));
    tmp->setColor(0, 0.27, 0.82, 1.0);
    this->_stars.push_back(tmp);
  }

  for (unsigned int i = 0; i < whiteMax; i++)
  {
    SFMLRectangle *tmp = new SFMLRectangle();

    tmp->setSize(Vector2f(1, 1));
    tmp->setPosition(Vector2f(Random::getNextInteger(0, MainWindow::getInstance().getWidth()), Random::getNextInteger(0, MainWindow::getInstance().getHeight())));
    tmp->setColor(1.0, 1.0, 1.0, 1.0);
    this->_stars.push_back(tmp);
  }
  return (true);
}

void	  BlueStarsBackground::display()
{
  if (MainWindow::getInstance().getWidth() != this->_lastWidth ||
          MainWindow::getInstance().getHeight() != this->_lastHeight)
    this->create();
  for (unsigned int i = 0; i < this->_stars.size(); i++)
  {
    Vector2f tmp = this->_stars.at(i)->getPosition();
    Vector2f newPos = tmp;

    newPos.setX(tmp.getX() + this->_offset);
    while (newPos.getX() < 0)
      newPos.setX(newPos.getX() + MainWindow::getInstance().getWidth());
    if (newPos.getX() < this->_offset + this->_width)
    {
      this->_stars.at(i)->setPosition(newPos);
      this->_stars.at(i)->display();
      this->_stars.at(i)->setPosition(tmp);
    }
  }
}

void	  BlueStarsBackground::destroy()
{
  for (std::vector<SFMLRectangle *>::iterator ite = this->_stars.begin(); ite != this->_stars.end(); ite++)
    delete *ite;
  this->_stars.clear();
}