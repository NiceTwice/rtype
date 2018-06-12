//
// SFMLImage.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 16:00:01 2016 Adrien Vasseur
// Last update Fri Dec  9 13:53:40 2016 Adrien Vasseur
//

#include		"gui/sfml/SFMLImage.hpp"
#include		"gui/MainWindow.hpp"

SFMLImage::SFMLImage()
{
  this->_alpha = 1.0f;
}

SFMLImage::~SFMLImage()
{

}

bool		SFMLImage::loadFromTexture(const SFMLTexture &texture, const Vector2f &pos, const Vector2f &size)
{
  this->_image.setTexture(texture.getHandler());
  this->_image.setTextureRect(sf::IntRect((int) pos.getX(), (int) pos.getY(), (int) size.getX(), (int) size.getY()));
  return (true);
}

void		SFMLImage::setPosition(const Vector2f &pos)
{
  this->_pos = pos;
}

void		SFMLImage::setAlpha(float alpha)
{
  this->_alpha = alpha;
  this->_image.setColor(sf::Color(255, 255, 255, (sf::Uint8) (alpha * 255)));
}

void		SFMLImage::display()
{
  this->_image.setPosition(this->_pos.getX() * MainWindow::getInstance().getWindow().getScale(), this->_pos.getY() * MainWindow::getInstance().getWindow().getScale());
  this->_image.setScale(MainWindow::getInstance().getWindow().getScale(), MainWindow::getInstance().getWindow().getScale());
  MainWindow::getInstance().getWindow().getHandler().draw(this->_image);
}

float       SFMLImage::getAlpha() const
{
  return (this->_alpha);
}

const Vector2f	SFMLImage::getSize() const
{
  return (Vector2f(this->_image.getLocalBounds().width, this->_image.getLocalBounds().height));
}
