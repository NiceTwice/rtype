//
// LoadManager.hpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/loader
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Sat Dec 31 10:10:36 2016 Quentin Guerin
// Last update Sat Dec 31 10:10:37 2016 Quentin Guerin
//

#pragma once

# include <map>
# include "tools/Singleton.hpp"
# if (defined WIN32) || (defined _WIN32)
#  include "loader/DllLoader.hpp"
# else
#  include "loader/SoLoader.hpp"
# endif

class LoadManager: public Singleton<LoadManager>
{
public:
  LoadManager(std::string const&);
  ~LoadManager();

public:
  LoadManager &update(void);
  LoadManager &reset(void);

  const std::vector<std::string> getLoadedLibraries(void) const;
  const std::map<uint64_t, IMob *> getBuilders(void) const;

private:
  const std::vector<std::string> _findLibraries(std::string const& dir) const;

private:
  ILoader *m_loader;
  const std::string m_suffix;
};