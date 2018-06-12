//
// Core.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 15:41:16 2016 Quentin Guerin
// Last update Mon Dec 19 17:09:51 2016 Quentin Guerin
//

#pragma once

# ifndef DEFAULT_PORT
#  define DEFAULT_PORT 8080u
# endif

# include "ACore.hpp"

class Core: public ACore
{
public:
  Core(unsigned int = 7);
  ~Core();

public:
  bool init(unsigned short, int) final;
  bool run(void);
};
