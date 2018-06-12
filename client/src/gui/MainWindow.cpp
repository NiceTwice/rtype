//
// MainWindow.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:05:23 2016 Adrien Vasseur
// Last update Mon Dec 12 23:29:02 2016 Adrien Vasseur
//

#include	"gui/MainWindow.hpp"
#include	"gui/scenes/LoadingScene.hpp"
#include	"gui/scenes/GameMenuScene.hpp"
#include    "gui/scenes/GameBoardScene.hpp"
#include    "core/GameCore.hpp"
#include    "net/Network.hpp"

template<> MainWindow*	Singleton<MainWindow>::INSTANCE = new MainWindow();

MainWindow::MainWindow()
{
  this->_width = DEFAULT_WIN_WIDTH;
  this->_height = DEFAULT_WIN_HEIGHT;
}

MainWindow::~MainWindow()
{
}

bool		MainWindow::init()
{
  this->_window.open();
  this->_sceneManager.addScene("LoadingScene", new LoadingScene(this->_window));
  this->_sceneManager.addScene("GameMenuScene", new GameMenuScene(this->_window));
  this->_sceneManager.addScene("GameBoardScene", new GameBoardScene(this->_window));
  this->_sceneManager.setScene("LoadingScene");
  return (true);
}

void		MainWindow::run()
{
  while (this->_window.isOpen())
    {
      this->_sceneManager.draw();
      this->_window.update();
    }
  Network::getInstance().destroy();
}

void		MainWindow::close()
{
  this->_mutex.lock();
  this->_window.close();
  this->_mutex.unlock();
}

void        MainWindow::setWidth(unsigned int width)
{
  this->_width = width;
  this->_window.resize();
}

void        MainWindow::setHeight(unsigned int height)
{
  this->_height = height;
  this->_window.resize();
}

unsigned int	MainWindow::getWidth() const
{
  return (this->_width);
}

unsigned int	MainWindow::getHeight() const
{
  return (this->_height);
}

SceneManager	&MainWindow::getSceneManager()
{
  return (this->_sceneManager);
}

SFMLWindow	&MainWindow::getWindow()
{
  return (this->_window);
}
