//
// SFMLFont.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:32:13 2017 Adrien Vasseur
// Last update Sun Jan 01 18:32:13 2017 Adrien Vasseur
//

#include    "gui/sfml/SFMLFont.hpp"

SFMLFont::SFMLFont()
{

}

SFMLFont::~SFMLFont()
{

}

bool      SFMLFont::loadFromFile(const std::string &filename)
{
  return (this->_font.loadFromFile(filename));
}

sf::Font  &SFMLFont::getHandler()
{
  return (this->_font);
}