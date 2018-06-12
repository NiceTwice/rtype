//
// SFMLEvent.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 14:04:58 2016 Adrien Vasseur
// Last update Thu Dec 15 14:04:58 2016 Adrien Vasseur
//

#include  <iostream>
#include  "gui/sfml/SFMLEvent.hpp"

SFMLEvent::SFMLEvent()
{
  _types[sf::Event::KeyPressed] = Event::KEY_PRESSED;
  _types[sf::Event::KeyReleased] = Event::KEY_RELEASED;
  _types[sf::Event::MouseButtonPressed] = Event::MOUSE_BUTTON_PRESSED;
  _types[sf::Event::MouseButtonReleased] = Event::MOUSE_BUTTON_RELEASED;
  _types[sf::Event::MouseMoved] = Event::MOUSE_MOVED;
  _types[sf::Event::JoystickConnected] = Event::JOYSTICK_CONNECTED;
  _types[sf::Event::JoystickDisconnected] = Event::JOYSTICK_DISCONNECTED;
  _types[sf::Event::JoystickButtonPressed] = Event::JOYSTICK_BUTTON_PRESSED;
  _types[sf::Event::JoystickButtonReleased] = Event::JOYSTICK_BUTTON_RELEASED;
  _types[sf::Event::JoystickMoved] = Event::JOYSTICK_MOVE;
  _types[sf::Event::Closed] = Event::CLOSED;
  _types[sf::Event::Resized] = Event::RESIZED;
  _keyboard[sf::Keyboard::Up] = Event::UP;
  _keyboard[sf::Keyboard::Right] = Event::RIGHT;
  _keyboard[sf::Keyboard::Down] = Event::DOWN;
  _keyboard[sf::Keyboard::Left] = Event::LEFT;
  _keyboard[sf::Keyboard::Return] = Event::RETURN;
  _keyboard[sf::Keyboard::Space] = Event::SPACE;
  _keyboard[sf::Keyboard::Escape] = Event::ESCAPE;
  _joystick[0] = Event::SPACE;
  _keyboardRev[Event::UP] = sf::Keyboard::Up;
  _keyboardRev[Event::RIGHT] = sf::Keyboard::Right;
  _keyboardRev[Event::DOWN] = sf::Keyboard::Down;
  _keyboardRev[Event::LEFT] = sf::Keyboard::Left;
  _keyboardRev[Event::RETURN] = sf::Keyboard::Return;
  _keyboardRev[Event::SPACE] = sf::Keyboard::Space;
  _keyboardRev[Event::ESCAPE] = sf::Keyboard::Escape;
  _joystickRev[Event::SPACE] = 0;
  _joystickAxis[sf::Joystick::X] = Event::X_AXIS;
  _joystickAxis[sf::Joystick::Y] = Event::Y_AXIS;
  _joystickAxisRev[Event::X_AXIS] = sf::Joystick::X;
  _joystickAxisRev[Event::Y_AXIS] = sf::Joystick::Y;
}

SFMLEvent::~SFMLEvent()
{

}

Event::Type SFMLEvent::getType() const
{
  if (this->_types.find(this->_event.type) != this->_types.end())
    return (this->_types.at(this->_event.type));
  return (Event::UNKNOWN_TYPE);
}

Event::Key  SFMLEvent::getKeyboardKey() const
{
  if (this->_keyboard.find(this->_event.key.code) != this->_keyboard.end())
    return (this->_keyboard.at(this->_event.key.code));
  return (Event::UNKNOWN_KEY);
}

Event::Key  SFMLEvent::getJoystickKey() const
{
  if (this->_joystick.find(this->_event.joystickButton.button) != this->_joystick.end())
    return (this->_joystick.at(this->_event.joystickButton.button));
  return (Event::UNKNOWN_KEY);
}

int  SFMLEvent::getMouseMovedX() const
{
  return (this->_event.mouseMove.x);
}

int  SFMLEvent::getMouseMovedY() const
{
  return (this->_event.mouseMove.y);
}

int  SFMLEvent::getMouseClickedX() const
{
  return (this->_event.mouseButton.x);
}

int  SFMLEvent::getMouseClickedY() const
{
  return (this->_event.mouseButton.y);
}

unsigned int  SFMLEvent::getResizedWidth() const
{
  return (this->_event.size.width);
}

unsigned int  SFMLEvent::getResizedHeight() const
{
  return (this->_event.size.height);
}

bool           SFMLEvent::isKeyPressed(Event::Key key) const
{
  bool         ret = false;

  if (this->_keyboardRev.find(key) != this->_keyboardRev.end())
    ret |= sf::Keyboard::isKeyPressed(this->_keyboardRev.at(key));
  if (this->_joystickRev.find(key) != this->_joystickRev.end())
    ret |= sf::Joystick::isButtonPressed(0, this->_joystickRev.at(key));
  return (ret);
}

float         SFMLEvent::getAxisValue(Event::Axis axis) const
{
  if (this->_joystickAxisRev.find(axis) != this->_joystickAxisRev.end() &&
          sf::Joystick::isConnected(0) &&
          sf::Joystick::hasAxis(0, this->_joystickAxisRev.at(axis)))
    return (sf::Joystick::getAxisPosition(0, this->_joystickAxisRev.at(axis)));
  return (0.0f);
}

sf::Event     &SFMLEvent::getHandler()
{
  return (this->_event);
}