//
// IEvent.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 13:47:35 2016 Adrien Vasseur
// Last update Thu Dec 15 13:47:35 2016 Adrien Vasseur
//

#pragma   once

namespace Event
{
  enum    Type
  {
    UNKNOWN_TYPE,
    KEY_PRESSED,
    KEY_RELEASED,
    MOUSE_BUTTON_PRESSED,
    MOUSE_BUTTON_RELEASED,
    MOUSE_MOVED,
    JOYSTICK_CONNECTED,
    JOYSTICK_DISCONNECTED,
    JOYSTICK_BUTTON_PRESSED,
    JOYSTICK_BUTTON_RELEASED,
    JOYSTICK_MOVE,
    CLOSED,
    RESIZED
  };

  enum    Key
  {
    UNKNOWN_KEY,
    UP,
    RIGHT,
    DOWN,
    LEFT,
    RETURN,
    SPACE,
    ESCAPE
  };

  enum    Axis
  {
    UNKOWN_AXIS,
    X_AXIS,
    Y_AXIS
  };

};

class     IEvent
{
public:
  virtual ~IEvent() {}

  virtual Event::Type getType() const = 0;
  virtual Event::Key  getKeyboardKey() const = 0;
  virtual Event::Key  getJoystickKey() const = 0;
  virtual int  getMouseMovedX() const = 0;
  virtual int  getMouseMovedY() const = 0;
  virtual int  getMouseClickedX() const = 0;
  virtual int  getMouseClickedY() const = 0;
  virtual unsigned int  getResizedWidth() const = 0;
  virtual unsigned int  getResizedHeight() const = 0;

  virtual bool  isKeyPressed(Event::Key) const = 0;
  virtual float getAxisValue(Event::Axis) const = 0;
};