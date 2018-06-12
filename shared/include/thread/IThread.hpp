//
// IThread.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 10:49:58 2016 Adrien Vasseur
// Last update Wed Nov 30 11:20:52 2016 Adrien Vasseur
//

#pragma		once

class		IThread
{
public:
  virtual	~IThread() {}

  virtual bool	init() = 0;
  virtual void	start() = 0;
  virtual void	join() = 0;
  virtual void	stop() = 0;

protected:
  virtual void	run() = 0;
};
