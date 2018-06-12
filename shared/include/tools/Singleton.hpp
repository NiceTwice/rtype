//
// Singleton.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/tools/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 14:01:15 2016 Adrien Vasseur
// Last update Wed Nov 30 15:40:13 2016 Adrien Vasseur
//

#pragma		once

#include	<cstdlib>

template <typename T>
class		Singleton
{
private:
  Singleton(const Singleton<T> &) {}
  Singleton	&operator=(const Singleton<T> &) {}

protected:
  static T	*INSTANCE;

public:
  Singleton()
    {
      INSTANCE = static_cast<T *>(this);
    }

  ~Singleton() {}

  static T	&getInstance()
    {
      return (*INSTANCE);
    }

  static T	*getInstancePtr()
    {
      return (INSTANCE);
    }
};
