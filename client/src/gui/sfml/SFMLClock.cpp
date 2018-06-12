//
// SFMLClock.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/sfml/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 22:16:11 2016 Adrien Vasseur
// Last update Thu Dec  1 22:19:11 2016 Adrien Vasseur
//

#include	"gui/sfml/SFMLClock.hpp"

SFMLClock::SFMLClock()
{
  this->_clock.restart();
}

SFMLClock::~SFMLClock()
{

}

unsigned int	SFMLClock::getElapsedTime() const
{
  sf::Time	elapsed;

  elapsed = this->_clock.getElapsedTime();
  return (((unsigned int) elapsed.asMilliseconds()));
}

void		SFMLClock::restart()
{
  this->_clock.restart();
}
