//
// StdCondVar.cpp for rtype in /home/lanquemar/rendu/rtype/shared/src/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 12:23:15 2016 Adrien Vasseur
// Last update Wed Nov 30 21:23:15 2016 Adrien Vasseur
//

#include	<iostream>
#include	"thread/StdCondVar.hpp"

StdCondVar::StdCondVar()
{

}

StdCondVar::~StdCondVar()
{

}

void		StdCondVar::signal()
{
  this->_condVar.notify_one();
}

void		StdCondVar::broadcast()
{
  this->_condVar.notify_all();
}

void		StdCondVar::wait(IMutex &mtx)
{
  try
    {
      StdMutex	&realMutex = dynamic_cast<StdMutex &>(mtx);
      std::unique_lock<std::mutex>	locker(realMutex.getHandler(), std::defer_lock);
      
      this->_condVar.wait(locker);
    }
  catch (const std::bad_cast& e)
    {
      std::cerr << "[ERROR] StdCondVar::wait : " << e.what() << std::endl;
    }
}
