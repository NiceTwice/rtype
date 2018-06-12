//
// SFMLInputHandler.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:44:03 2016 Adrien Vasseur
// Last update Mon Dec 12 23:30:08 2016 Adrien Vasseur
//

#include    <iostream>
#include	"gui/sfml/SFMLInputHandler.hpp"

SFMLInputHandler::SFMLInputHandler(SFMLWindow &window) : _window(window)
{

}

SFMLInputHandler::~SFMLInputHandler()
{

}

bool		SFMLInputHandler::init()
{
  this->_callbacks[Event::KEY_PRESSED] = &SFMLInputHandler::onKeyPressed;
  this->_callbacks[Event::KEY_RELEASED] = &SFMLInputHandler::onKeyReleased;
  this->_callbacks[Event::MOUSE_BUTTON_PRESSED] = &SFMLInputHandler::onMouseButtonPressed;
  this->_callbacks[Event::MOUSE_BUTTON_RELEASED] = &SFMLInputHandler::onMouseButtonReleased;
  this->_callbacks[Event::MOUSE_MOVED] = &SFMLInputHandler::onMouseMove;
  this->_callbacks[Event::JOYSTICK_CONNECTED] = &SFMLInputHandler::onJoystickConnected;
  this->_callbacks[Event::JOYSTICK_DISCONNECTED] = &SFMLInputHandler::onJoystickDisconnected;
  this->_callbacks[Event::JOYSTICK_BUTTON_PRESSED] = &SFMLInputHandler::onJoystickButtonPressed;
  this->_callbacks[Event::JOYSTICK_BUTTON_RELEASED] = &SFMLInputHandler::onJoystickButtonReleased;
  this->_callbacks[Event::JOYSTICK_MOVE] = &SFMLInputHandler::onJoystickMove;
  this->_callbacks[Event::CLOSED] = &SFMLInputHandler::onCloseEvent;
  this->_callbacks[Event::RESIZED] = &SFMLInputHandler::onResizeEvent;
  return (true);
}

void		SFMLInputHandler::onKeyPressed()
{

}

void		SFMLInputHandler::onKeyReleased()
{
  
}

void		SFMLInputHandler::onMouseButtonPressed()
{

}

void		SFMLInputHandler::onMouseButtonReleased()
{

}

void		SFMLInputHandler::onMouseMove()
{

}

void        SFMLInputHandler::onJoystickConnected()
{
  std::cout << "[INFO] JoystickConnected: " << sf::Joystick::getIdentification(this->_event.getHandler().joystickConnect.joystickId).name.toAnsiString() << std::endl;
}

void        SFMLInputHandler::onJoystickDisconnected()
{
  std::cout << "[INFO] JoystickDisconnected" << std::endl;
}

void        SFMLInputHandler::onJoystickButtonPressed()
{
  
}

void        SFMLInputHandler::onJoystickButtonReleased()
{

}

void        SFMLInputHandler::onJoystickMove()
{

}

void		SFMLInputHandler::onCloseEvent()
{
  this->_window.close();
}

void		SFMLInputHandler::onResizeEvent()
{
  this->_window.resize(this->_event.getResizedWidth(), this->_event.getResizedHeight());
}

void		SFMLInputHandler::update()
{
  while (this->_window.pollEvent(this->_event))
    {
      if (this->_callbacks.find(this->_event.getType()) != this->_callbacks.end())
		(this->*(_callbacks[this->_event.getType()]))();
    }
}

const SFMLEvent	&SFMLInputHandler::getEvent() const
{
  return (this->_event);
}
