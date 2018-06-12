//
// BlueStarsBackground.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 17:42:08 2016 Adrien Vasseur
// Last update Thu Dec 15 17:42:08 2016 Adrien Vasseur
//

#pragma   once

#include  "gui/gfx/ABackground.hpp"
#include  "gui/sfml/SFMLRectangle.hpp"

#define   RATIO_BLUE_STARS (0.33f)
#define   RATIO_WHITE_STARS (0.10f)

class     BlueStarsBackground : public ABackground
{
public:
  BlueStarsBackground();
  ~BlueStarsBackground();

  bool	  create();
  void	  display();
  void	  destroy();

private:
  std::vector<SFMLRectangle *>  _stars;

  unsigned int  _lastWidth;
  unsigned int  _lastHeight;
};