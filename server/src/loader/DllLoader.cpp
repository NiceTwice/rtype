//
// DllLoader.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 15:52:21 2016 Quentin Guerin
// Last update Mon Dec 05 13:44:23 2016 Quentin Guerin
//

#include "loader/DllLoader.hpp"

DllLoader::DllLoader(void)
{
}

DllLoader::~DllLoader(void)
{
}

/**
 * @return bool Success of operation
 * @param std::string const& binding Name of the binding in the loader
 * @param std::string const& filename Name of the file
 *
 * Try to load DLL
 */

bool DllLoader::load(std::string const& binding, std::string const& filename)
{
  if (this->_libraries.find(binding) == this->_libraries.end())
    {
      HMODULE handle = LoadLibrary(filename.c_str());

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
 * Try to unload DLL
 */

bool DllLoader::unload(std::string const& binding)
{
  auto it = this->_libraries.find(binding);

  if (it != this->_libraries.end())
    {
      if (FreeLibrary(it->second) != 0)
	this->_libraries.erase(it);
      else
	return (false);
    }
  return (true);
}

/**
 * @return FARPROC Pointer to symbol
 * @param std::string const& binding Name of the binding in the loader
 * @param std::string const& symbolName Name of the symbol
 *
 * Try to getSymbol in DLL
 */

FARPROC DllLoader::getSymbol(std::string const& binding, std::string const& symbolName) throw(LoaderException)
{
  FARPROC function = nullptr;
  auto it = this->_libraries.find(binding);

  if (it != this->_libraries.end())
    {
      if ((function = GetProcAddress(it->second, symbolName.c_str())) != nullptr)
	return (function);
      else
	throw LoaderException("Symbol not found");
    }
  else
    return (nullptr);
}
