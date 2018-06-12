//
// IMutex.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:50:03 2016 Adrien Vasseur
// Last update Wed Nov 30 11:51:36 2016 Adrien Vasseur
//

#pragma		once

class		IMutex
{
public:
  virtual	~IMutex() {}

  virtual void	lock() = 0;
  virtual bool	tryLock() = 0;
  virtual void	unlock() = 0;
};
