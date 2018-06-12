//
// SFMLImage.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:46:20 2016 Adrien Vasseur
// Last update Fri Dec  9 13:54:05 2016 Adrien Vasseur
//

#pragma		once

#include	<SFML/Graphics.hpp>
#include	"gui/sfml/SFMLWindow.hpp"
#include	"gui/sfml/SFMLTexture.hpp"
#include	"game/Vector2f.hpp"

class		SFMLImage
{
public:
  SFMLImage();
  ~SFMLImage();

  bool		loadFromTexture(const SFMLTexture &, const Vector2f &, const Vector2f &);

  void		setPosition(const Vector2f &);
  void		setAlpha(float);
  void		display();

  float     getAlpha() const;
  const Vector2f	getSize() const;

private:
  Vector2f		_pos;
  float         _alpha;
  sf::Sprite	_image;
};
