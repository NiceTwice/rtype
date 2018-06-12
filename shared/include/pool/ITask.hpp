//
// ITask.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/pool/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 15:45:56 2016 Adrien Vasseur
// Last update Wed Nov 30 16:21:46 2016 Adrien Vasseur
//

#pragma		once

class		ITask
{
public:
  virtual	~ITask() {}

  virtual void		process() = 0;
};
