//
// SFMLEvent.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 13:59:10 2016 Adrien Vasseur
// Last update Thu Dec 15 13:59:10 2016 Adrien Vasseur
//

#pragma   once

#include  <map>
#include  <SFML/Window/Event.hpp>
#include  "gui/IEvent.hpp"

class     SFMLEvent : public IEvent
{
public:
  SFMLEvent();
  ~SFMLEvent();

  Event::Type getType() const;
  Event::Key  getKeyboardKey() const;
  Event::Key  getJoystickKey() const;
  int  getMouseMovedX() const;
  int  getMouseMovedY() const;
  int  getMouseClickedX() const;
  int  getMouseClickedY() const;
  unsigned int  getResizedWidth() const;
  unsigned int  getResizedHeight() const;

  bool  isKeyPressed(Event::Key) const;
  float getAxisValue(Event::Axis) const;

  sf::Event     &getHandler();

private:
  sf::Event		_event;

  std::map<sf::Event::EventType, Event::Type> _types;
  std::map<sf::Keyboard::Key, Event::Key>     _keyboard;
  std::map<Event::Key, sf::Keyboard::Key>     _keyboardRev;
  std::map<unsigned int, Event::Key>          _joystick;
  std::map<Event::Key, unsigned int>          _joystickRev;
  std::map<sf::Joystick::Axis, Event::Axis>  _joystickAxis;
  std::map<Event::Axis, sf::Joystick::Axis>  _joystickAxisRev;
};