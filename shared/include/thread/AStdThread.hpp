//
// AStdThread.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 10:52:18 2016 Adrien Vasseur
// Last update Wed Nov 30 11:58:40 2016 Adrien Vasseur
//

#pragma		once

#include	<thread>
#include	"thread/IThread.hpp"
#include	"thread/StdMutex.hpp"

class		AStdThread : public IThread
{
public:
  AStdThread();
  ~AStdThread();

  void		start();
  void		join();
  void		stop();

private:
  void		internalRun();

  StdMutex		_mutex;
  std::thread	*_thread;
  bool			_running;
};
