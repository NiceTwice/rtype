//
// SoLoader.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 15:52:07 2016 Quentin Guerin
// Last update Fri Dec 02 11:39:36 2016 Quentin Guerin
//

#include "loader/SoLoader.hpp"

SoLoader::SoLoader(void)
{
}

SoLoader::~SoLoader(void)
{
}

/**
 * @return bool Success of operation
 * @param std::string const& binding Name of the binding in the loader
 *
 * Try to load SO
 */

bool SoLoader::load(std::string const& binding, std::string const& filename)
{
  if (this->_libraries.find(binding) == this->_libraries.end())
    {
      void *handle = dlopen(filename.c_str(), RTLD_LAZY);

      if (handle == nullptr)
	return (false);
      else
	this->_libraries[binding] = handle;
    }
  return (true);
}

/**
 * @return bool Success of operation
 * @param std::string const& binding Name of the binding in the loader
 *
 * Try to unload SO
 */

bool SoLoader::unload(std::string const& binding)
{
  auto it = this->_libraries.find(binding);

  if (it != this->_libraries.end())
    {
      if (dlclose(it->second) != 0)
	this->_libraries.erase(it);
      else
	return (false);
    }
  return (true);
}

/**
 * @return void* Pointer to symbol
 * @param std::string const& binding Name of the binding in the loader
 * @param std::string const& symbolName Name of the symbol
 *
 * Try to getSymbol in SO
 */

void *SoLoader::getSymbol(std::string const& binding, std::string const& symbolName) throw(LoaderException)
{
  void *function = nullptr;
  auto it = this->_libraries.find(binding);

  if (it != this->_libraries.end())
    {
      if ((function = dlsym(it->second, symbolName.c_str())) != nullptr)
	return (function);
      else
	throw LoaderException("Symbol not found");
    }
  else
    return (nullptr);
}
