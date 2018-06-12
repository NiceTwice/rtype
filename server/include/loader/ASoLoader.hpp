//
// ASoLoader.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 16:31:57 2016 Quentin Guerin
// Last update Fri Dec 02 11:39:00 2016 Quentin Guerin
//

#pragma once

# include <dlfcn.h>
# include "loader/ALoader.hpp"

# define ILoader ILoader<void *>
# define ALoader ALoader<void *>

class ASoLoader: public ALoader
{
public:
  ASoLoader(void);
  virtual ~ASoLoader(void);

public:
  virtual bool load(std::string const&, std::string const&) = 0;
  virtual bool unload(std::string const&) = 0;

  virtual void *getSymbol(std::string const&, std::string const&) = 0;

  IMob *build(std::string const&, std::string const& = "make") final;

protected:

private:

};
