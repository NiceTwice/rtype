//
// MainWindow.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:02:09 2016 Adrien Vasseur
// Last update Mon Dec 12 23:27:13 2016 Adrien Vasseur
//

#pragma		once

#include	"thread/AStdThread.hpp"
#include	"tools/Singleton.hpp"
#include	"gui/sfml/SFMLWindow.hpp"
#include	"gui/sfml/SFMLInputHandler.hpp"
#include	"gui/SceneManager.hpp"

#define		DEFAULT_WIN_WIDTH	330
#define		DEFAULT_WIN_HEIGHT	310

class		MainWindow : public Singleton<MainWindow>
{
public:
  MainWindow();
  ~MainWindow();

  bool		init();
  void		run();
  void		close();

  void          setWidth(unsigned int);
  void          setHeight(unsigned int);

  unsigned int	getWidth() const;
  unsigned int	getHeight() const;

  SceneManager	&getSceneManager();
  SFMLWindow	&getWindow();

private:
  unsigned int      _width;
  unsigned int      _height;

  SFMLWindow		_window;
  SceneManager		_sceneManager;

  StdMutex          _mutex;
};
