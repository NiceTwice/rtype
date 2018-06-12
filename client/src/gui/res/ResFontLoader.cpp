//
// ResFontLoader.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:26:48 2017 Adrien Vasseur
// Last update Sun Jan 01 18:26:48 2017 Adrien Vasseur
//

#include    <iostream>
#include    "gui/res/ResFontLoader.hpp"
#include    "gui/sfml/SFMLFont.hpp"
#include    "gui/res/ResPool.hpp"

ResFontLoader::ResFontLoader(const std::string &name, const std::string &filename) : _name(name), _filename(filename)
{

}

ResFontLoader::~ResFontLoader()
{

}

void        ResFontLoader::process()
{
  SFMLFont  *font = new SFMLFont();

  if (font->loadFromFile(this->_filename))
  {
    ResPool::getInstance().addFont(this->_name, font);
    std::cout << "[INFO] [ASSET] Font loaded: " << this->_name << std::endl;
  }
  else
  {
    ResPool::getInstance().getLoader().setError(true);
    std::cerr << "[ERROR] [ASSET] Unable to load font file: " << this->_filename << std::endl;
  }
}