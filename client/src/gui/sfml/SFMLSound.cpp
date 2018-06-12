//
// SFMLSound.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 11:42:43 2016 Adrien Vasseur
// Last update Sat Dec 31 11:45:10 2016 Adrien Vasseur
//

#include  "gui/sfml/SFMLSound.hpp"

SFMLSound::SFMLSound()
{

}

SFMLSound::~SFMLSound()
{
  this->stop();
}

bool      SFMLSound::loadFromFile(const std::string &filename)
{
  return (this->_buffer.loadFromFile(filename));
}

bool      SFMLSound::isRunning() const
{
  return (this->_sounds.size() > 0);
}

void      SFMLSound::setLoop(bool)
{

}

void      SFMLSound::start()
{
  sf::Sound *sound = new sf::Sound(this->_buffer);

  while (this->_sounds.size() > 0 && this->_sounds.front()->getStatus() != sf::SoundSource::Playing)
  {
    delete this->_sounds.front();
    this->_sounds.pop();
  }
  sound->play();
  this->_sounds.push(sound);
}

void      SFMLSound::stop()
{
  while (this->_sounds.size() > 0)
  {
    delete this->_sounds.front();
    this->_sounds.pop();
  }
}