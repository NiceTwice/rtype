//
// IAnimation.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/anim/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Mon Dec 12 22:42:31 2016 Adrien Vasseur
// Last update Mon Dec 12 22:44:44 2016 Adrien Vasseur
//

#pragma		once

class		IAnimation
{
public:
  virtual ~IAnimation() {}

  virtual void	start() = 0;
  virtual void	display() = 0;
  virtual void	stop() = 0;
  virtual void  destroy() = 0;
};
