//
// KeyAnimation.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  2 11:04:17 2016 Adrien Vasseur
// Last update Mon Dec 12 22:55:45 2016 Adrien Vasseur
//

#include	<cstdlib>
#include	"gui/anim/KeyAnimation.hpp"

KeyAnimation::KeyAnimation()
{
  this->destroy();
}

KeyAnimation::~KeyAnimation()
{

}

void		KeyAnimation::addKey(const Vector2f &vec)
{
  this->_keys.push_back(vec);
}

void		KeyAnimation::setImage(SFMLImage * const img)
{
  this->_img = img;
}

void		KeyAnimation::setInterval(unsigned int interval)
{
  this->_interval = interval;
}

void		KeyAnimation::setRepeated(bool repeated)
{
  this->_repeated = repeated;
}

void		KeyAnimation::start()
{
  this->_running = true;
  this->_clock.restart();
}

void		KeyAnimation::calcPos(unsigned int key)
{
  unsigned int	nextKey = (key + 1) % ((unsigned int) this->_keys.size());
  unsigned int	step = this->_lastClock % this->_interval;
  Vector2f		pos;

  if (!this->_repeated && step == this->_keys.size() - 1)
    pos = this->_keys[this->_keys.size() - 1];
  else
    {
      pos.setX(this->_keys[key].getX() + (this->_keys[nextKey].getX() - this->_keys[key].getX()) * (((float) step) / ((float) this->_interval)));
      pos.setY(this->_keys[key].getY() + (this->_keys[nextKey].getY() - this->_keys[key].getY()) * (((float) step) / ((float) this->_interval)));
    }
  this->_img->setPosition(pos);
}

bool		KeyAnimation::isOnLastKey() const
{
  unsigned int	step;

  if (this->_interval != 0 && this->_keys.size() > 0)
    {
      step = (this->_lastClock / this->_interval) % ((unsigned int) this->_keys.size());
      return (step == this->_keys.size() - 1);
    }
  return (false);
}

void		KeyAnimation::display()
{
  if (this->_img != NULL && this->_keys.size() > 0)
    {
      if (this->_running && (this->_repeated || this->_lastClock < this->_interval * this->_keys.size()))
		this->_lastClock = this->_clock.getElapsedTime();
      if (this->_interval == 0 ||  this->_keys.size() == 1)
		this->_img->setPosition(this->_keys[0]);
      else
		this->calcPos((this->_lastClock / this->_interval) % ((unsigned int) this->_keys.size()));
      this->_img->display();
    }
}

void		KeyAnimation::stop()
{
  this->_running = false;
}

void        KeyAnimation::destroy()
{
  this->_img = NULL;
  this->_running = false;
  this->_repeated = true;
  this->_interval = 200;
  this->_lastClock = 0;
}