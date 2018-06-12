//
// SFMLSound.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 11:42:43 2016 Adrien Vasseur
// Last update Sat Dec 31 11:42:43 2016 Adrien Vasseur
//

#pragma   once

#include  <queue>
#include  <SFML/Audio.hpp>
#include  "gui/IMusic.hpp"

class     SFMLSound : public IMusic
{
public:
  SFMLSound();
  ~SFMLSound();

  bool    loadFromFile(const std::string &);
  bool    isRunning() const;
  void    setLoop(bool);

  void    start();
  void    stop();

private:
  sf::SoundBuffer _buffer;
  std::queue<sf::Sound *>  _sounds;
};