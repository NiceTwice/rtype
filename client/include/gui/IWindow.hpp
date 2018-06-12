//
// IWindow.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:19:02 2016 Adrien Vasseur
// Last update Thu Dec  1 21:20:30 2016 Adrien Vasseur
//

#pragma		once

class		IWindow
{
public:
  virtual	~IWindow() {}

  virtual void		open() = 0;
  virtual void		resize(unsigned int, unsigned int) = 0;
  virtual void		update() = 0;
  virtual void		close() = 0;
};
