//
// SFMLTexture.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:49:50 2016 Adrien Vasseur
// Last update Fri Dec  2 00:20:29 2016 Adrien Vasseur
//

#include	"gui/sfml/SFMLTexture.hpp"

SFMLTexture::SFMLTexture()
{
  this->_texture.setSmooth(false);
}

SFMLTexture::~SFMLTexture()
{

}

bool	SFMLTexture::loadFromFile(const std::string &filename)
{
  return (this->_texture.loadFromFile(filename));
}

const Vector2f	SFMLTexture::getSize() const
{
  return (Vector2f((float) this->_texture.getSize().x, (float) this->_texture.getSize().y));
}

const sf::Texture	&SFMLTexture::getHandler() const
{
  return (this->_texture);
}
