//
// ILoader.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 15:33:08 2016 Quentin Guerin
// Last update Fri Dec 02 11:45:51 2016 Quentin Guerin
//

#pragma once

# include <map>
# include <string>
# include <vector>
# include "game/Entity.hpp"
# include "IMob.hpp"
# include "exceptions/LoaderException.hpp"
# include "IMob.hpp"

template <typename T>
class ILoader
{
public:
  ILoader<T>(void) {};
  virtual ~ILoader<T>(void) {};

public:
  virtual bool load(std::string const&, std::string const&) = 0;
  virtual bool unload(std::string const&) = 0;

  virtual bool loadAll(std::vector<std::pair<std::string, std::string> > const&) = 0;
  virtual bool unloadAll(bool = false) = 0;

  virtual IMob *build(std::string const&, std::string const& = "make") = 0;

protected:

private:

};
