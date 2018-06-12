//
// LoadingScene.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/scenes/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:32:58 2016 Adrien Vasseur
// Last update Mon Dec 12 23:28:32 2016 Adrien Vasseur
//

#include	"gui/scenes/LoadingScene.hpp"
#include	"gui/res/ResPool.hpp"
#include	"gui/MainWindow.hpp"

LoadingScene::LoadingScene(SFMLWindow &win) : AScene(win)
{
  this->_animation = NULL;
}

LoadingScene::~LoadingScene()
{
  this->destroy();
}

bool		LoadingScene::create()
{
  return (init());
}

void		LoadingScene::internalInit()
{
  if (this->_animation == NULL &&
      ResPool::getInstance().getImage("loader-0x0") != NULL &&
      ResPool::getInstance().getImage("loader-0x1") != NULL &&
      ResPool::getInstance().getImage("loader-0x2") != NULL &&
      ResPool::getInstance().getImage("loader-0x3") != NULL)
    {
      this->_animation = new FrameAnimation();
      this->_animation->addFrame(ResPool::getInstance().getImage("loader-0x0"));
      this->_animation->addFrame(ResPool::getInstance().getImage("loader-0x1"));
      this->_animation->addFrame(ResPool::getInstance().getImage("loader-0x2"));
      this->_animation->addFrame(ResPool::getInstance().getImage("loader-0x3"));
      this->_animation->setInterval(200);
      this->_animation->setRepeated(true);
      this->_animation->start();
    }
}

void		LoadingScene::displayHud()
{
  if (!this->_animation)
    return;
  this->_animation->setPosition(Vector2f(0.0f, 0.0f));
  this->_animation->display();
  this->_animation->setPosition(Vector2f(0.0f, MainWindow::getInstance().getHeight() - ResPool::getInstance().getImage("loader-0x3")->getSize().getY()));
  this->_animation->display();
  this->_animation->setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("loader-0x3")->getSize().getX(), 0.0f));
  this->_animation->display();
  this->_animation->setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("loader-0x3")->getSize().getX(), MainWindow::getInstance().getHeight() - ResPool::getInstance().getImage("loader-0x3")->getSize().getY()));
  this->_animation->display();
}

void		LoadingScene::loadAsset()
{
  ITask		*newTask;

  if ((newTask = ResPool::getInstance().getLoader().getNewTask()) != NULL)
    {
      newTask->process();
      delete newTask;
      if (ResPool::getInstance().getLoader().hasError())
		MainWindow::getInstance().close();
    }
  else
    MainWindow::getInstance().getSceneManager().setScene("GameMenuScene");
}

void		LoadingScene::display()
{
  this->internalInit();
  this->displayHud();
  this->loadAsset();
}

void		LoadingScene::destroy()
{
  if (this->_animation)
    {
      delete this->_animation;
      this->_animation = NULL;
    }
}
