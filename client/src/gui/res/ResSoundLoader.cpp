//
// ResSoundLoader.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 11:50:04 2016 Adrien Vasseur
// Last update Sat Dec 31 11:50:04 2016 Adrien Vasseur
//


#include    <iostream>
#include    "gui/res/ResSoundLoader.hpp"
#include    "gui/res/ResPool.hpp"

ResSoundLoader::ResSoundLoader(const std::string &name, const std::string &filename) : _name(name), _filename(filename)
{

}

ResSoundLoader::~ResSoundLoader()
{

}

void        ResSoundLoader::process()
{
  SFMLSound *sound = new SFMLSound();

  if (sound->loadFromFile(this->_filename))
  {
    ResPool::getInstance().addMusic(this->_name, sound);
    std::cout << "[INFO] [ASSET] Sound loaded: " << this->_name << std::endl;
  }
  else
  {
    ResPool::getInstance().getLoader().setError(true);
    std::cerr << "[ERROR] [ASSET] Unable to load sound file: " << this->_filename << std::endl;
  }
}