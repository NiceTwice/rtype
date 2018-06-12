//
// FadeAnimation.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Dec  7 10:06:51 2016 Adrien Vasseur
// Last update Mon Dec 12 22:45:41 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/anim/IAnimation.hpp"
#include	"gui/sfml/SFMLImage.hpp"
#include	"gui/sfml/SFMLClock.hpp"

class		FadeAnimation : public IAnimation
{
public:
  FadeAnimation();
  ~FadeAnimation();

  void		setImage(SFMLImage * const);

  void		setInterval(unsigned int);
  void		setRepeated(bool);
  void		setPosition(const Vector2f &);

  bool		isRunning() const;

  float     getAlpha() const;

  void		start();
  void		display();
  void		stop();
  void      destroy();

private:
  SFMLImage 	*_img;
  bool			_running;
  bool			_repeated;
  unsigned int	_interval;

  SFMLClock		_clock;
  unsigned int	_lastClock;

  Vector2f		_pos;
  float         _alpha;

  void			calcAlpha();
};
