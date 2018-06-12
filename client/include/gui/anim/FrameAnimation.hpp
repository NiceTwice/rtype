//
// FrameAnimation.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 22:04:48 2016 Adrien Vasseur
// Last update Mon Dec 12 22:45:57 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/anim/IAnimation.hpp"
#include	"gui/sfml/SFMLImage.hpp"
#include	"gui/sfml/SFMLClock.hpp"

class		FrameAnimation : public IAnimation
{
public:
  FrameAnimation();
  ~FrameAnimation();

  void		addFrame(SFMLImage * const);

  void		setInterval(unsigned int);
  void		setRepeated(bool);

  void		setPosition(const Vector2f &);

  void		start();
  void		display();
  void		stop();
  void      destroy();

  bool      isRunning() const;

private:
  std::vector<SFMLImage *>	_frames;
  bool			_running;
  bool			_repeated;
  unsigned int	_interval;

  SFMLClock		_clock;
  unsigned int	_lastClock;

  Vector2f		_pos;

  void		draw(SFMLImage *);
};
