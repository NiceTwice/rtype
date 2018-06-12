//
// TaskList.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/pool/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 15:48:25 2016 Adrien Vasseur
// Last update Fri Dec  2 18:29:50 2016 Adrien Vasseur
//

#pragma		once

#include	<queue>
#include	"thread/StdMutex.hpp"
#include	"thread/StdCondVar.hpp"

template <typename T>
class		TaskList
{
public:
  TaskList()
    {
      this->_enabled = true;
    }

  ~TaskList()
    {

    }

  void		addTask(T * const task)
    {
      this->_mutex.lock();
      this->_list.push(task);
      this->_condVar.signal();
      this->_mutex.unlock();
    }

  T * 		getTask()
    {
      T		*task;

      this->_mutex.lock();
      while (this->_list.empty() && this->_enabled)
		this->_condVar.wait(this->_mutex);
      if (!this->_enabled)
		{
	  	  this->_mutex.unlock();
	  	  return (NULL);
		}
      task = this->_list.front();
      this->_list.pop();
      this->_mutex.unlock();
      return (task);
    }

  void		disable()
    {
      this->_mutex.lock();
      this->_enabled = false;
      this->_condVar.broadcast();
      this->_mutex.unlock();
    }

  bool		isEnabled()
    {
      bool	value;

      this->_mutex.lock();
      value = this->_enabled;
      this->_mutex.unlock();
      return (value);
    }

  size_t	size()
    {
      size_t	value;

      this->_mutex.lock();
      value = this->_list.size();
      this->_mutex.unlock();
      return (value);
    }

private:
  bool					_enabled;
  std::queue<T *>		_list;
  StdMutex				_mutex;
  StdCondVar			_condVar;
};
