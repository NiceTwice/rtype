//
// KeyAnimation.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  2 10:57:44 2016 Adrien Vasseur
// Last update Mon Dec 12 22:46:17 2016 Adrien Vasseur
//

#pragma		once

#include	<vector>
#include	"gui/anim/IAnimation.hpp"
#include	"game/Vector2f.hpp"
#include	"gui/sfml/SFMLImage.hpp"
#include	"gui/sfml/SFMLClock.hpp"

class		KeyAnimation : public IAnimation
{
public:
  KeyAnimation();
  ~KeyAnimation();

  void		addKey(const Vector2f &);

  void		setImage(SFMLImage * const);
  void		setInterval(unsigned int);
  void		setRepeated(bool);

  void		start();
  void		display();
  void		stop();
  void      destroy();

  bool		isOnLastKey() const;

private:
  std::vector<Vector2f>	_keys;
  SFMLImage	*_img;

  bool		_running;
  bool		_repeated;
  unsigned int	_interval;

  SFMLClock		_clock;
  unsigned int	_lastClock;

  void		calcPos(unsigned int);
};
