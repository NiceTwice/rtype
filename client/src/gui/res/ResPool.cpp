//
// ResPool.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 22:22:42 2016 Adrien Vasseur
// Last update Fri Dec  9 13:57:46 2016 Adrien Vasseur
//

#include	"gui/res/ResPool.hpp"
#include	"gui/res/ResImageLoader.hpp"
#include	"gui/MainWindow.hpp"

template<> ResPool*	Singleton<ResPool>::INSTANCE = new ResPool();

ResPool::ResPool()
{

}

ResPool::~ResPool()
{
  for (std::map<std::string, SFMLImage *>::iterator ite = this->_images.begin(); ite != this->_images.end(); ite++)
    delete ite->second;
  this->_images.clear();
  for (std::map<std::string, SFMLTexture *>::iterator ite = this->_textures.begin(); ite != this->_textures.end(); ite++)
    delete ite->second;
  this->_textures.clear();
  for (std::map<std::string, IMusic *>::iterator ite = this->_musics.begin(); ite != this->_musics.end(); ite++)
    delete ite->second;
  this->_musics.clear();
  for (std::map<std::string, SFMLFont *>::iterator ite = this->_fonts.begin(); ite != this->_fonts.end(); ite++)
    delete ite->second;
  this->_fonts.clear();
}

void		ResPool::addTexture(const std::string &name, SFMLTexture * const texture)
{
  this->_textures[name] = texture;
}

void		ResPool::addImage(const std::string &name, SFMLImage * const image)
{
  this->_images[name] = image;
}

void        ResPool::addMusic(const std::string &name, IMusic * const music)
{
  this->_musics[name] = music;
}

void        ResPool::addFont(const std::string &name, SFMLFont * const font)
{
  this->_fonts[name] = font;
}

SFMLImage	*ResPool::getImage(const std::string &name)
{
  if (this->_images.find(name) != this->_images.end())
    return (this->_images[name]);
  return (NULL);
}

IMusic      *ResPool::getMusic(const std::string &name)
{
  if (this->_musics.find(name) != this->_musics.end())
    return (this->_musics[name]);
  return (NULL);
}

SFMLFont    *ResPool::getFont(const std::string &name)
{
  if (this->_fonts.find(name) != this->_fonts.end())
    return (this->_fonts[name]);
  return (NULL);
}

ResLoader	&ResPool::getLoader()
{
  return (this->_loader);
}
