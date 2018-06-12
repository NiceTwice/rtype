//
// IInputHandler.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:32:08 2016 Adrien Vasseur
// Last update Thu Dec  1 11:21:57 2016 Adrien Vasseur
//

#pragma		once

class		IInputHandler
{
public:
  virtual	~IInputHandler() {}

  virtual void	onKeyPressed() = 0;
  virtual void	onKeyReleased() = 0;
  virtual void	onMouseButtonPressed() = 0;
  virtual void	onMouseButtonReleased() = 0;
  virtual void	onMouseMove() = 0;
  virtual void  onJoystickConnected() = 0;
  virtual void  onJoystickDisconnected() = 0;
  virtual void  onJoystickButtonPressed() = 0;
  virtual void  onJoystickButtonReleased() = 0;
  virtual void  onJoystickMove() = 0;
  virtual void	onCloseEvent() = 0;
  virtual void	onResizeEvent() = 0;
  virtual void	update() = 0;
};
