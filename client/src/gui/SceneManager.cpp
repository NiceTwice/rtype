//
// SceneManager.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:17:24 2016 Adrien Vasseur
// Last update Mon Dec 12 23:27:45 2016 Adrien Vasseur
//

#include	<cstdlib>
#include <iostream>
#include	"gui/SceneManager.hpp"

SceneManager::SceneManager()
{
  this->_currentScene = NULL;
}

SceneManager::~SceneManager()
{
  for (std::map<std::string, AScene *>::iterator ite = this->_sceneList.begin();
          ite != this->_sceneList.end();
          ite++)
    delete ite->second;
  this->_sceneList.clear();
}

void		SceneManager::addScene(const std::string &name, AScene * const view)
{
  this->_sceneList[name] = view;
}

void		SceneManager::setScene(const std::string &name)
{
  if (this->_sceneList.find(name) != this->_sceneList.end())
    {
      if (this->_currentScene)
		this->_currentScene->destroy();
      this->_currentScene = this->_sceneList[name];
      if (this->_currentScene && !this->_currentScene->create())
		this->_currentScene = NULL;
    }
  else
    this->_currentScene = NULL;
}

void		SceneManager::draw()
{
  if (this->_currentScene != NULL)
    {
      this->_currentScene->update();
      this->_currentScene->display();
    }
}
