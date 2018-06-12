//
// AStdThread.cpp for rtype in /home/lanquemar/rendu/rtype/shared/src/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 10:55:47 2016 Adrien Vasseur
// Last update Wed Nov 30 11:57:25 2016 Adrien Vasseur
//

#include	"thread/AStdThread.hpp"

#include <iostream>

AStdThread::AStdThread()
{
  this->_thread = NULL;
  this->_running = false;
}

AStdThread::~AStdThread()
{
  if (this->_thread)
    delete this->_thread;
}

void		AStdThread::start()
{
  this->_mutex.lock();
  if (this->_thread)
    delete this->_thread;
  this->_thread = new std::thread(&AStdThread::internalRun, this);
  this->_running = true;
  this->_mutex.unlock();
}

void		AStdThread::join()
{
  this->_thread->join();
}

void		AStdThread::stop()
{
  this->_mutex.lock();
  this->_running = false;
  this->_mutex.unlock();
}

void		AStdThread::internalRun()
{
  bool		isRunning;

  isRunning = true;
  while (isRunning)
    {
      this->run();
      this->_mutex.lock();
      isRunning = this->_running;
      this->_mutex.unlock();
    }
}
