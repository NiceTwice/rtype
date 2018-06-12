//
// SFMLText.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:42:52 2017 Adrien Vasseur
// Last update Sun Jan 01 18:42:52 2017 Adrien Vasseur
//

#pragma   once

#include  <SFML/Graphics/Text.hpp>
#include  "gui/sfml/SFMLFont.hpp"
#include  "game/Vector2f.hpp"

class     SFMLText
{
public:
  SFMLText();
  ~SFMLText();

  void    setFont(SFMLFont * const);
  void    setString(const std::string &);
  void    setSize(unsigned int);
  void    setColor(unsigned char, unsigned char, unsigned char, unsigned char);
  void    setPosition(const Vector2f &);

  void    display();

private:
  sf::Text  _text;
  Vector2f      _pos;
  unsigned int  _size;
};