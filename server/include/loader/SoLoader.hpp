//
// SoLoader.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 15:44:19 2016 Quentin Guerin
// Last update Fri Dec 02 11:39:17 2016 Quentin Guerin
//

#pragma once

# include "loader/ASoLoader.hpp"

class SoLoader: public ASoLoader
{
public:
  SoLoader(void);
  ~SoLoader(void);

public:
  bool load(std::string const&, std::string const&) final;
  bool unload(std::string const&) final;

  void *getSymbol(std::string const&, std::string const&) throw(LoaderException) final;

protected:

private:

};
