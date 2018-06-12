//
// SFMLMusic.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 10:21:29 2016 Adrien Vasseur
// Last update Sat Dec 31 10:21:29 2016 Adrien Vasseur
//

#include    "gui/sfml/SFMLMusic.hpp"

SFMLMusic::SFMLMusic()
{

}

SFMLMusic::~SFMLMusic()
{

}

bool      SFMLMusic::loadFromFile(const std::string &filename)
{
  return (this->_music.openFromFile(filename));
}

bool      SFMLMusic::isRunning() const
{
  return (this->_music.getStatus() == sf::SoundSource::Playing);
}

void      SFMLMusic::setLoop(bool loop)
{
  this->_music.setLoop(loop);
}

void      SFMLMusic::start()
{
  this->_music.play();
}

void      SFMLMusic::stop()
{
  this->_music.stop();
}