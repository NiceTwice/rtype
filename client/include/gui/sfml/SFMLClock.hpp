//
// SFMLClock.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/sfml/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 22:13:14 2016 Adrien Vasseur
// Last update Thu Dec  1 22:21:35 2016 Adrien Vasseur
//

#pragma		once

#include	<SFML/System.hpp>

class		SFMLClock
{
public:
  SFMLClock();
  ~SFMLClock();

  unsigned int	getElapsedTime() const;
  void			restart();

private:
  sf::Clock		_clock;
};
