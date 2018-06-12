//
// SceneManager.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 14:57:44 2016 Adrien Vasseur
// Last update Mon Dec 12 23:27:28 2016 Adrien Vasseur
//

#pragma		once

#include	<string>
#include	<map>
#include	"gui/scenes/AScene.hpp"

class		SceneManager
{
public:
  SceneManager();
  ~SceneManager();

  void		addScene(const std::string &, AScene * const);
  void		setScene(const std::string &);

  void		draw();

private:
  AScene	*_currentScene;
  std::map<std::string, AScene *>	_sceneList;
};
