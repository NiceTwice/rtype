//
// SFMLFont.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:30:02 2017 Adrien Vasseur
// Last update Sun Jan 01 18:30:02 2017 Adrien Vasseur
//

#pragma   once

#include  <string>
#include  <SFML/Graphics/Font.hpp>

class     SFMLFont
{
public:
  SFMLFont();
  ~SFMLFont();

  bool    loadFromFile(const std::string &);

  sf::Font  &getHandler();

private:
  sf::Font  _font;
};