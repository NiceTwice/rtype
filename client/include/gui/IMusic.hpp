//
// IMusic.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 10:41:11 2016 Adrien Vasseur
// Last update Sat Dec 31 10:41:11 2016 Adrien Vasseur
//

#pragma   once

#include  <string>

class     IMusic
{
public:
  virtual ~IMusic() {}

  virtual bool    loadFromFile(const std::string &) = 0;
  virtual bool    isRunning() const = 0;
  virtual void    setLoop(bool) = 0;

  virtual void    start() = 0;
  virtual void    stop() = 0;
};