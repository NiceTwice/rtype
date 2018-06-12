//
// SFMLMusic.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 10:20:58 2016 Adrien Vasseur
// Last update Sat Dec 31 10:20:58 2016 Adrien Vasseur
//

#pragma   once

#include  <string>
#include  <SFML/Audio.hpp>
#include  "gui/IMusic.hpp"

class     SFMLMusic : public IMusic
{
public:
  SFMLMusic();
  ~SFMLMusic();

  bool    loadFromFile(const std::string &);
  bool    isRunning() const;
  void    setLoop(bool);

  void    start();
  void    stop();

private:
  sf::Music _music;
};