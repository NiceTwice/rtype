//
// SFMLRectangle.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 17:23:29 2016 Adrien Vasseur
// Last update Thu Dec 15 17:23:29 2016 Adrien Vasseur
//

#include    "gui/MainWindow.hpp"
#include    "gui/sfml/SFMLRectangle.hpp"

SFMLRectangle::SFMLRectangle()
{

}

SFMLRectangle::~SFMLRectangle()
{

}

void      SFMLRectangle::setSize(const Vector2f &size)
{
  this->_size = size;
}

void      SFMLRectangle::setPosition(const Vector2f &pos)
{
  this->_pos = pos;
}

void      SFMLRectangle::setColor(float r, float g, float b, float a)
{
  this->_rectangle.setFillColor(sf::Color((sf::Uint8) (r * 255), (sf::Uint8) (g * 255), (sf::Uint8) (b * 255), (sf::Uint8) (a * 255)));
}

void      SFMLRectangle::display()
{
  this->_rectangle.setPosition(this->_pos.getX() * MainWindow::getInstance().getWindow().getScale(), this->_pos.getY() * MainWindow::getInstance().getWindow().getScale());
  this->_rectangle.setSize(sf::Vector2f(this->_size.getX() * MainWindow::getInstance().getWindow().getScale(), this->_size.getY() * MainWindow::getInstance().getWindow().getScale()));
  MainWindow::getInstance().getWindow().getHandler().draw(this->_rectangle);
}

const Vector2f      &SFMLRectangle::getPosition() const
{
  return (this->_pos);
}