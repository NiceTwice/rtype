//
// InsideShipBackground.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 10:31:36 2016 Adrien Vasseur
// Last update Wed Dec 28 10:31:36 2016 Adrien Vasseur
//

#pragma   once

#include  "gui/gfx/ABackground.hpp"
#include  "gui/sfml/SFMLImage.hpp"

class     InsideShipBackground : public ABackground
{
public:
  InsideShipBackground();
  ~InsideShipBackground();

  bool	  create();
  void	  display();
  void	  destroy();

private:
  SFMLImage *_img;
};