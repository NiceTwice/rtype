//
// ThreadsPool.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/pool/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 16:29:57 2016 Adrien Vasseur
// Last update Fri Dec  2 19:02:23 2016 Adrien Vasseur
//

#pragma		once

#include	"pool/Slave.hpp"

#include <iostream>
class		ThreadsPool
{
public:
  ThreadsPool(unsigned int threads)
    {
      for (unsigned int i = 0; i < threads; i++)
		{
	  	  Slave *slave = new Slave(this->_taskList);

	      if (!slave->init())
	    	delete slave;
	      else
	    	{
	      	  slave->start();
	      	  this->_slaves.push_back(slave);
	    	}

		}
    }

  ~ThreadsPool()
    {
      this->_taskList.disable();
      for (unsigned int i = 0; i < this->_slaves.size(); i++)
		{
		  this->_slaves[i]->stop();
	      this->_slaves[i]->join();
        }
      while (this->_slaves.size() > 0) {
        delete (*(this->_slaves.begin()));
        this->_slaves.erase(this->_slaves.begin());
      }
    }

  void		addTask(ITask * const task)
    {
      this->_mutex.lock();
      this->_taskList.addTask(task);
      this->_mutex.unlock();
    }

  size_t	size()
    {
      size_t	ret;

      this->_mutex.lock();
      ret = this->_taskList.size();
      this->_mutex.unlock();
      return (ret);
    }

  bool		hasFinished()
    {
      if (this->size() != 0)
		return (false);
      this->_mutex.lock();
      for (unsigned int i = 0; i < this->_slaves.size(); i++)
		{
	  	  if (this->_slaves[i]->isWorking())
	    	{
	      	  this->_mutex.unlock();
	      	  return (false);
	    	}
		}
      this->_mutex.unlock();
      return (true);
    }

private:
  std::vector<Slave *>	_slaves;
  TaskList<ITask>		_taskList;
  StdMutex				_mutex;
};
