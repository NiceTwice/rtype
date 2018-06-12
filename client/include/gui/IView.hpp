//
// IView.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:06:19 2016 Adrien Vasseur
// Last update Thu Dec  1 15:14:54 2016 Adrien Vasseur
//

#pragma		once

class		IView
{
public:
  virtual	~IView() {}

  virtual bool	create() = 0;
  virtual void	display() = 0;
  virtual void	destroy() = 0;
};
