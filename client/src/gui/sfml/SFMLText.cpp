//
// SFMLText.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:46:03 2017 Adrien Vasseur
// Last update Sun Jan 01 18:46:03 2017 Adrien Vasseur
//

#include    "gui/sfml/SFMLText.hpp"
#include    "gui/MainWindow.hpp"

SFMLText::SFMLText()
{
  this->_size = 12;
}

SFMLText::~SFMLText()
{

}

void        SFMLText::setFont(SFMLFont * const font)
{
  this->_text.setFont(font->getHandler());
}

void        SFMLText::setString(const std::string &text)
{
  this->_text.setString(text);
}

void        SFMLText::setSize(unsigned int size)
{
  this->_size = size;
}

void        SFMLText::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
  this->_text.setFillColor(sf::Color(r, g, b, a));
}

void        SFMLText::setPosition(const Vector2f &pos)
{
  this->_pos = pos;
}

void        SFMLText::display()
{
  this->_text.setPosition(this->_pos.getX() * MainWindow::getInstance().getWindow().getScale(), this->_pos.getY() * MainWindow::getInstance().getWindow().getScale());
  this->_text.setCharacterSize(this->_size * (unsigned int) MainWindow::getInstance().getWindow().getScale());
  MainWindow::getInstance().getWindow().getHandler().draw(this->_text);
}