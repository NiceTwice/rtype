//
// ADllLoader.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/loader
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 11:49:06 2016 Quentin Guerin
// Last update Fri Dec 02 11:49:07 2016 Quentin Guerin
//

#include "loader/ADllLoader.hpp"

ADllLoader::ADllLoader(void)
{
}

ADllLoader::~ADllLoader(void)
{
}

/**
 * @return IMob* Instance built from the DLL
 * @param std::string const& binding Name of the binding in the loader
 * @param std::string const& builder Name of the symbol to build the instance
 *
 * Build a new instance of the object inside of DLL
 */

IMob *ADllLoader::build(std::string const& binding, std::string const& builder)
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