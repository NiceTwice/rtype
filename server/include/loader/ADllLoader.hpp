//
// ADllLoader.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 16:32:09 2016 Quentin Guerin
// Last update Fri Dec 02 11:38:47 2016 Quentin Guerin
//

#pragma once

# include <windows.h>
# include "loader/ALoader.hpp"

# define ILoader ILoader<HMODULE>
# define ALoader ALoader<HMODULE>

class ADllLoader: public ALoader
{
public:
  ADllLoader(void);
  virtual ~ADllLoader(void);

public:
  virtual bool load(std::string const&, std::string const&) = 0;
  virtual bool unload(std::string const&) = 0;

  virtual FARPROC getSymbol(std::string const&, std::string const&) = 0;

  IMob *build(std::string const&, std::string const& = "make") final;

protected:

private:

};
