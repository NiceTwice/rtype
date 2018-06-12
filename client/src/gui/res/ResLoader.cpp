//
// ResLoader.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  9 13:20:12 2016 Adrien Vasseur
// Last update Fri Dec  9 14:33:44 2016 Adrien Vasseur
//

#include	"gui/res/ResLoader.hpp"
#include	"gui/res/ResImageLoader.hpp"
#include    "gui/res/ResFontLoader.hpp"
#include    "gui/res/ResSoundLoader.hpp"
#include    "gui/res/ResMusicLoader.hpp"
#include	"gui/MainWindow.hpp"

ResLoader::ResLoader()
{
  std::string	dir("assets/");

  this->_error = false;
  this->_tasks.push(new ResImageLoader("loader", dir + "loader.png", 1, 4));
  this->_tasks.push(new ResImageLoader("r", dir + "r.png", 1, 1));
  this->_tasks.push(new ResImageLoader("r-type", dir + "r-type.png", 1, 1));
  this->_tasks.push(new ResImageLoader("menuhud", dir + "menuhud.png", 1, 6));
  this->_tasks.push(new ResFontLoader("VCR", dir + "VCR.ttf"));
  this->_tasks.push(new ResMusicLoader("RType-Menu-Begin", dir + "RType-Menu-Begin.ogg"));
  this->_tasks.push(new ResMusicLoader("RType-Menu-Loop", dir + "RType-Menu-Loop.ogg"));
  this->_tasks.push(new ResMusicLoader("RType-Game-Loop", dir + "RType-Game-Loop.ogg"));
  this->_tasks.push(new ResSoundLoader("Shoot", dir + "Shoot.ogg"));
  this->_tasks.push(new ResImageLoader("ship", dir + "ship.png", 5, 5));
  this->_tasks.push(new ResImageLoader("background-1", dir + "background-1.png", 1, 1));
  this->_tasks.push(new ResImageLoader("background-2", dir + "background-2.png", 1, 1));
  this->_tasks.push(new ResImageLoader("static-meshs-1", dir + "static-meshs-1.png", 4, 4));
  this->_tasks.push(new ResImageLoader("static-meshs-2", dir + "static-meshs-2.png", 2, 1));
  this->_tasks.push(new ResImageLoader("static-meshs-3", dir + "static-meshs-3.png", 1, 2));
  this->_tasks.push(new ResImageLoader("missiles", dir + "missiles.png", 1, 1));
  this->_tasks.push(new ResImageLoader("explosion", dir + "explosion.png", 12, 1));
  this->_tasks.push(new ResImageLoader("explosion-2", dir + "explosion-2.png", 6, 1));
  this->_tasks.push(new ResImageLoader("mob-1", dir + "mob-1.png", 4, 1));
  this->_tasks.push(new ResImageLoader("mob-2", dir + "mob-2.png", 4, 1));
  this->_tasks.push(new ResImageLoader("mob-3", dir + "mob-3.png", 4, 1));
  this->_tasks.push(new ResImageLoader("unknown", dir + "unknown.png", 1, 1));
}

ResLoader::~ResLoader()
{

}

ITask		*ResLoader::getNewTask()
{
  ITask		*task = NULL;

  if (this->_tasks.size() > 0)
    {
      task = this->_tasks.front();
      this->_tasks.pop();
    }
  return (task);
}

void		ResLoader::setError(bool error)
{
  this->_error = error;
}

bool		ResLoader::hasError() const
{
  return (this->_error);
}
