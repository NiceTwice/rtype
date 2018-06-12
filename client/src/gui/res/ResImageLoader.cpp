//
// ResImageLoader.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:39:34 2016 Adrien Vasseur
// Last update Fri Dec  9 13:55:10 2016 Adrien Vasseur
//

#include	<iostream>
#include	"gui/res/ResImageLoader.hpp"
#include	"gui/res/ResPool.hpp"
#include	"gui/sfml/SFMLTexture.hpp"

ResImageLoader::ResImageLoader(const std::string &name, const std::string &filename, unsigned int width, unsigned int height)
{
  this->_name = name;
  this->_filename = filename;
  this->_width = width;
  this->_height = height;
}

ResImageLoader::~ResImageLoader()
{

}

void		ResImageLoader::process()
{
  SFMLTexture	*texture = new SFMLTexture();
  SFMLImage		*img;
  Vector2f		tileSize;

  if (texture->loadFromFile(this->_filename))
    {
      ResPool::getInstance().addTexture(this->_name, texture);
      std::cout << "[INFO] [ASSET] Texture loaded: " << this->_name << std::endl;
      tileSize.setX(texture->getSize().getX() / this->_width);
      tileSize.setY(texture->getSize().getY() / this->_height);
      for (unsigned int x = 0; x < this->_width; x++)
		{
	  	  for (unsigned int y = 0; y < this->_height; y++)
	    	{
	      	  img = new SFMLImage();
	      	  img->loadFromTexture(*texture, Vector2f(x * tileSize.getX(), y * tileSize.getY()), tileSize);
              ResPool::getInstance().addImage(this->_name + "-" + std::to_string(x) + "x" + std::to_string(y), img);
              std::cout << "[INFO] [ASSET] Image loaded: " << this->_name + "-" + std::to_string(x) + "x" + std::to_string(y) << std::endl;
	    	}
		}
    }
  else
    {
      ResPool::getInstance().getLoader().setError(true);
      std::cerr << "[ERROR] [ASSET] Unable to load texture file: " << this->_filename << std::endl;
    }
}
