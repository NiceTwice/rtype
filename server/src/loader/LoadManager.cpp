//
// LoadManager.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/loader
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Sat Dec 31 10:10:54 2016 Quentin Guerin
// Last update Sat Dec 31 11:15:52 2016 Quentin Guerin
//

#include <iostream>
#include <algorithm>
#include <dirent.h>
#include "loader/LoadManager.hpp"
#include "exceptions/LoadManagerException.hpp"
#include "IMob.hpp"

#if (defined WIN32) || (defined _WIN32)
template<> LoadManager*	Singleton<LoadManager>::INSTANCE = new LoadManager(".dll");
#else
template<> LoadManager*	Singleton<LoadManager>::INSTANCE = new LoadManager(".so");
#endif

LoadManager::LoadManager(std::string const& suffix): m_loader(nullptr), m_suffix(suffix)
{
  this->reset();
}

LoadManager::~LoadManager(void)
{
  if (this->m_loader != nullptr)
    delete this->m_loader;
}

LoadManager &LoadManager::reset(void)
{
  if (this->m_loader != nullptr)
    delete this->m_loader;
#if (defined WIN32) || (defined _WIN32)
  this->m_loader = new DllLoader();
#else
  this->m_loader = new SoLoader();
#endif
  return (*this);
}

const std::vector<std::string> LoadManager::_findLibraries(std::string const& dir) const
{
  DIR *dirp;
  std::vector<std::string> found;

  if ((dirp = opendir(dir.c_str())) != nullptr) {
    struct dirent *ent;

    while ((ent = readdir(dirp)) != nullptr) {
      std::string filename = std::string(ent->d_name);

      if (filename.length() >= this->m_suffix.length() &&
	  filename.compare(filename.length() - this->m_suffix.length(), this->m_suffix.length(), this->m_suffix) == 0) {
	if (dir.back() == '/')
	  filename = dir + filename;
	else
	  filename = dir + "/" + filename;
	found.push_back(filename);
	std::cerr << "[FOUND] " << filename << std::endl;
      }
    }
    closedir(dirp);
  }
  else
    throw LoadManagerException("Cannot find directory");
  return (found);
}

const std::vector<std::string> LoadManager::getLoadedLibraries(void) const
{
  return (dynamic_cast<ALoader *>(this->m_loader)->getLibraries());
}

LoadManager &LoadManager::update(void)
{
  if (this->m_loader != nullptr) {
    const std::vector<std::string> found = this->_findLibraries("./mobs/");
    const std::vector<std::string> loaded = this->getLoadedLibraries();
    std::vector<std::pair<std::string, std::string> > toLoad;

    for (std::string file: found) {
      if (std::find(loaded.begin(), loaded.end(), file) == loaded.end())
	toLoad.push_back(std::pair<std::string, std::string>(file, file));
    }

    for (std::string file: loaded) {
      if (std::find(found.begin(), found.end(), file) == found.end())
	this->m_loader->unload(file);
    }

    if (this->m_loader->loadAll(toLoad) == false)
      throw LoadManagerException("Loading failed");
  }
  else
    throw LoadManagerException("Loader not initialized");
  return (*this);
}

const std::map<uint64_t, IMob *> LoadManager::getBuilders(void) const
{
  uint64_t uid = 0;
  std::vector<std::string> loaded = this->getLoadedLibraries();
  std::map<uint64_t, IMob *> ret;

  for (std::string key: loaded) {
    ret[uid++] = this->m_loader->build(key);
  }
  return (ret);
}