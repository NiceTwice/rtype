//
// InsideMineBackground.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Fri Dec 30 14:56:26 2016 Adrien Vasseur
// Last update Fri Dec 30 14:56:26 2016 Adrien Vasseur
//

#pragma   once

#include  "gui/gfx/ABackground.hpp"
#include  "gui/sfml/SFMLImage.hpp"

class     InsideMineBackground : public ABackground
{
public:
  InsideMineBackground();
  ~InsideMineBackground();

  bool	  create();
  void	  display();
  void	  destroy();

private:
  SFMLImage *_img;
};