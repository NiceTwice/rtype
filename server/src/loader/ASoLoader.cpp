//
// ASoLoader.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/loader
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 11:48:53 2016 Quentin Guerin
// Last update Fri Dec 02 11:48:54 2016 Quentin Guerin
//

#include "loader/ASoLoader.hpp"

ASoLoader::ASoLoader(void)
{
}

ASoLoader::~ASoLoader(void)
{
}

/**
 * @return IMob* Instance built from the SO
 * @param std::string const& binding Name of the binding in the loader
 * @param std::string const& builder Name of the symbol to build the instance
 *
 * Build a new instance of the object inside of SO
 */

IMob *ASoLoader::build(std::string const& binding, std::string const& builder)
{
  IMob *(*symbol)();

  try {
    symbol = reinterpret_cast<IMob *(*)()>(this->getSymbol(binding, builder));
  }
  catch (LoaderException const& e) {
    return (nullptr);
  }
  return (symbol());
}