//
// StdCondVar.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/thread/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 12:21:48 2016 Adrien Vasseur
// Last update Wed Nov 30 12:40:48 2016 Adrien Vasseur
//

#pragma		once

#include	<condition_variable>
#include	"thread/ICondVar.hpp"
#include	"thread/StdMutex.hpp"

class		StdCondVar : public ICondVar
{
public:
  StdCondVar();
  ~StdCondVar();

  void		signal();
  void		broadcast();
  void		wait(IMutex &);

private:
  std::condition_variable	_condVar;
};
