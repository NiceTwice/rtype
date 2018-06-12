//
// ResMusicLoader.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 10:26:23 2016 Adrien Vasseur
// Last update Sat Dec 31 10:26:23 2016 Adrien Vasseur
//

#include    <iostream>
#include    "gui/sfml/SFMLMusic.hpp"
#include    "gui/res/ResMusicLoader.hpp"
#include    "gui/res/ResPool.hpp"

ResMusicLoader::ResMusicLoader(const std::string &name, const std::string &filename) : _name(name), _filename(filename)
{

}

ResMusicLoader::~ResMusicLoader()
{

}

void        ResMusicLoader::process()
{
  SFMLMusic *music = new SFMLMusic();

  if (music->loadFromFile(this->_filename))
  {
    ResPool::getInstance().addMusic(this->_name, music);
    std::cout << "[INFO] [ASSET] Music loaded: " << this->_name << std::endl;
  }
  else
  {
    ResPool::getInstance().getLoader().setError(true);
    std::cerr << "[ERROR] [ASSET] Unable to load music file: " << this->_filename << std::endl;
  }
}