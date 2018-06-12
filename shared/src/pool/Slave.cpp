//
// Slave.cpp for rtype in /home/lanquemar/rendu/rtype/shared/src/pool/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 16:33:41 2016 Adrien Vasseur
// Last update Fri Dec  2 18:17:35 2016 Adrien Vasseur
//

#include	"pool/Slave.hpp"

Slave::Slave(TaskList<ITask> &list) : _taskList(list)
{
  this->_working = false;
}

Slave::~Slave()
{

}

bool		Slave::init()
{
  return (true);
}

void		Slave::run()
{
  ITask		*task;

  if ((task = this->_taskList.getTask()) == NULL)
    {
      this->stop();
      return;
    }
  this->_mutex.lock();
  this->_working = true;
  this->_mutex.unlock();
  task->process();
  this->_mutex.lock();
  this->_working = false;
  this->_mutex.unlock();
}

bool		Slave::isWorking()
{
  bool		ret;

  this->_mutex.lock();
  ret = this->_working;
  this->_mutex.unlock();
  return (ret);
}
