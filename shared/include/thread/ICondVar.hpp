//
// ICondVar.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 12:17:26 2016 Adrien Vasseur
// Last update Wed Nov 30 12:40:40 2016 Adrien Vasseur
//

#pragma		once

#include	"thread/IMutex.hpp"

class		ICondVar
{
public:
  virtual	~ICondVar() {}

  virtual void		signal() = 0;
  virtual void		broadcast() = 0;
  virtual void		wait(IMutex &) = 0;
};
