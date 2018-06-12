//
// StdMutex.cpp for rtype in /home/lanquemar/rendu/rtype/shared/src/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:53:11 2016 Adrien Vasseur
// Last update Wed Nov 30 21:23:27 2016 Adrien Vasseur
//

#include	"thread/StdMutex.hpp"

StdMutex::StdMutex()
{

}

StdMutex::~StdMutex()
{

}

void		StdMutex::lock()
{
  this->_mutex.lock();
}

bool		StdMutex::tryLock()
{
  return (this->_mutex.try_lock());
}

void		StdMutex::unlock()
{
  this->_mutex.unlock();
}

std::mutex	&StdMutex::getHandler()
{
  return (this->_mutex);
}
