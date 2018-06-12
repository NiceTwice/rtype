//
// ResLoader.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  9 13:18:13 2016 Adrien Vasseur
// Last update Fri Dec  9 14:31:51 2016 Adrien Vasseur
//

#pragma		once

#include	<queue>
#include	"pool/ITask.hpp"

class		ResLoader
{
public:
  ResLoader();
  ~ResLoader();

  ITask		*getNewTask();
  void		setError(bool);
  bool		hasError() const;

private:
  std::queue<ITask *>	_tasks;
  bool					_error;
};
