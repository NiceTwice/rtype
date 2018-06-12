//
// StdMutex.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:52:12 2016 Adrien Vasseur
// Last update Wed Nov 30 17:26:25 2016 Adrien Vasseur
//

#pragma		once

#include	<mutex>
#include	"thread/IMutex.hpp"

class		StdMutex : public IMutex
{
public:
  StdMutex();
  ~StdMutex();

  void		lock();
  bool		tryLock();
  void		unlock();

  std::mutex	&getHandler();

private:
  std::mutex	_mutex;
};
