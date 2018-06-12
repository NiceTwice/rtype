//
// SFMLTexture.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:47:55 2016 Adrien Vasseur
// Last update Thu Dec  1 17:03:47 2016 Adrien Vasseur
//

#pragma		once

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"game/Vector2f.hpp"

class		SFMLTexture
{
public:
  SFMLTexture();
  ~SFMLTexture();

  bool		loadFromFile(const std::string &);

  const Vector2f	getSize() const;

  const sf::Texture	&getHandler() const;

private:
  sf::Texture	_texture;
};
