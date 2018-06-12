//
// Slave.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/pool/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 16:31:59 2016 Adrien Vasseur
// Last update Fri Dec  2 18:16:23 2016 Adrien Vasseur
//

#pragma		once

#include	"thread/AStdThread.hpp"
#include	"thread/StdMutex.hpp"
#include	"pool/ITask.hpp"
#include	"pool/TaskList.hpp"

class		Slave : public AStdThread
{
public:
  Slave(TaskList<ITask> &);
  ~Slave();

  bool		init();
  void		run();

  bool		isWorking();

private:
  TaskList<ITask>	&_taskList;
  StdMutex			_mutex;
  bool				_working;
};
