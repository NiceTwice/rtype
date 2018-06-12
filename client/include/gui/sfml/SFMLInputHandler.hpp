//
// SFMLInputHandler.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:38:23 2016 Adrien Vasseur
// Last update Fri Dec  2 11:43:18 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/IInputHandler.hpp"
#include	"gui/sfml/SFMLWindow.hpp"
#include    "gui/sfml/SFMLEvent.hpp"

class		SFMLInputHandler : public IInputHandler
{
  typedef	void (SFMLInputHandler::*eventHandler)(void);

public:
  SFMLInputHandler(SFMLWindow &);
  ~SFMLInputHandler();

  bool			init();
  void			update();

protected:
  virtual void	onKeyPressed();
  virtual void	onKeyReleased();
  virtual void	onMouseButtonPressed();
  virtual void	onMouseButtonReleased();
  virtual void	onMouseMove();
  virtual void  onJoystickConnected();
  virtual void  onJoystickDisconnected();
  virtual void  onJoystickButtonPressed();
  virtual void  onJoystickButtonReleased();
  virtual void  onJoystickMove();
  virtual void	onCloseEvent();
  virtual void	onResizeEvent();

  const SFMLEvent   &getEvent() const;

private:
  SFMLWindow	&_window;
  SFMLEvent     _event;

  std::map<Event::Type, eventHandler>	_callbacks;
};
