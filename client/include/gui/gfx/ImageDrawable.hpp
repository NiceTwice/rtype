//
// ImageDrawable.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 29 17:57:37 2016 Adrien Vasseur
// Last update Thu Dec 29 17:57:37 2016 Adrien Vasseur
//

#pragma   once

#include <gui/sfml/SFMLImage.hpp>
#include  "gui/IMusic.hpp"
#include  "gui/gfx/ADrawable.hpp"

class     ImageDrawable : public ADrawable
{
public:
  ImageDrawable(const std::string &, MovableEntity *);
  ImageDrawable(const std::string &, const std::string & = "");
  ~ImageDrawable();

  bool    create();
  void    display();
  void    destroy();

  ADrawable *clone(MovableEntity *);

  const std::string &getName() const;
private:
  std::string   _name;
  std::string   _cloneMusicName;
};