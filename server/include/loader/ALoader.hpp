//
// ALoader.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Thu Dec 01 15:39:36 2016 Quentin Guerin
// Last update Fri Dec 02 11:38:54 2016 Quentin Guerin
//

#pragma once

# include "loader/ILoader.hpp"

template <typename T>
class ALoader: public ILoader<T>
{
public:
  ALoader<T>(void) {};

  virtual ~ALoader<T>(void)
  {
    this->unloadAll();
  }

public:
  virtual bool load(std::string const&, std::string const&) = 0;
  virtual bool unload(std::string const&) = 0;

  bool loadAll(std::vector<std::pair<std::string, std::string> > const& bindings)
  {
    std::vector<std::pair<std::string, std::string> >::const_iterator it;

    for (it = bindings.begin(); it != bindings.end(); ++it)
      {
	if (this->load(it->first, it->second) == false)
	  return (false);
      }
    return (true);
  }

  bool unloadAll(bool ignore = false) final
  {
    auto it = this->_libraries.begin();

    for (; it != this->_libraries.end(); ++it)
      {
	if (this->unload(it->first) == false && ignore == false)
	  return (false);
      }
    return (true);
  }

  const std::vector<std::string> getLibraries(void) const
  {
    std::vector<std::string> libs;

    for (auto const& imap : this->_libraries) {
      libs.push_back(imap.first);
    }
    return (libs);
  }

  virtual IMob *build(std::string const&, std::string const& = "make") = 0;

protected:
  std::map<std::string, T> _libraries;
};
