//
// SFMLWindow.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:20:00 2016 Adrien Vasseur
// Last update Fri Dec  2 14:49:13 2016 Adrien Vasseur
//

#pragma		once

#include	<SFML/Graphics.hpp>
#include	"gui/IWindow.hpp"
#include    "gui/sfml/SFMLEvent.hpp"
#include	"thread/StdMutex.hpp"

class		SFMLWindow : public IWindow
{
public:
  SFMLWindow();
  ~SFMLWindow();

  void		open();
  void		resize(unsigned int, unsigned int);
  void      resize();
  void		update();
  void		close();

  bool		isOpen();

  bool		pollEvent(SFMLEvent &);

  float 	getScale();

  sf::RenderWindow	&getHandler();

private:
  sf::RenderWindow	_window;
  sf::RectangleShape	_border;
  float			_scale;
};
