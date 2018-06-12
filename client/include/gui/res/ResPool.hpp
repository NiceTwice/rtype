//
// ResPool.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 22:06:11 2016 Adrien Vasseur
// Last update Fri Dec  9 13:29:54 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/res/ResLoader.hpp"
#include	"tools/Singleton.hpp"
#include	"gui/sfml/SFMLTexture.hpp"
#include	"gui/sfml/SFMLImage.hpp"
#include    "gui/sfml/SFMLSound.hpp"
#include    "gui/sfml/SFMLFont.hpp"

class		ResPool : public Singleton<ResPool>
{
public:
  ResPool();
  ~ResPool();

  void		addTexture(const std::string &, SFMLTexture * const);
  void		addImage(const std::string &, SFMLImage * const);
  void      addMusic(const std::string &, IMusic * const);
  void      addFont(const std::string &, SFMLFont * const);

  SFMLImage	*getImage(const std::string &);
  IMusic    *getMusic(const std::string &);
  SFMLFont  *getFont(const std::string &);
  ResLoader	&getLoader();

private:
  std::map<std::string, SFMLTexture *>	_textures;
  std::map<std::string, SFMLImage *>	_images;
  std::map<std::string, IMusic *>	    _musics;
  std::map<std::string, SFMLFont *>     _fonts;
  ResLoader								_loader;
};
