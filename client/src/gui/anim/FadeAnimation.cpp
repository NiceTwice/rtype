//
// FadeAnimation.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Dec  7 10:15:47 2016 Adrien Vasseur
// Last update Mon Dec 12 22:55:37 2016 Adrien Vasseur
//

#include	<cstdlib>
#include	"gui/anim/FadeAnimation.hpp"

FadeAnimation::FadeAnimation()
{
  this->destroy();
}

FadeAnimation::~FadeAnimation()
{

}

void		FadeAnimation::setImage(SFMLImage * const img)
{
  this->_img = img;
}

void		FadeAnimation::setInterval(unsigned int value)
{
  this->_interval = value;
}

void		FadeAnimation::setRepeated(bool value)
{
  this->_repeated = value;
}

void		FadeAnimation::setPosition(const Vector2f &pos)
{
  this->_pos = pos;
}

void		FadeAnimation::start()
{
  this->_running = true;
  this->_clock.restart();
}

void		FadeAnimation::calcAlpha()
{
  unsigned int	step = this->_lastClock % this->_interval;
  float		alpha;

  if (!this->_repeated && this->_lastClock / this->_interval >= 1)
    step = this->_interval;
  alpha = ((float) step) / ((float) this->_interval);
  this->_img->setAlpha(this->_alpha = alpha);
  if (this->_repeated && this->_lastClock / this->_interval % 2 == 1)
    this->_img->setAlpha(this->_alpha = (1.0f - alpha));
}

void		FadeAnimation::display()
{
  if (this->_img != NULL)
    {
      this->_img->setPosition(this->_pos);
      if (this->_running)
		this->_lastClock = this->_clock.getElapsedTime();
      if (this->_interval == 0)
		this->_img->setAlpha((this->_alpha = 1.0));
      else
		this->calcAlpha();
      this->_img->display();
      this->_img->setAlpha(1.0);
    }
}

void		FadeAnimation::stop()
{
  this->_running = false;
}

void        FadeAnimation::destroy()
{
  this->_running = false;
  this->_repeated = true;
  this->_interval = 1000;
  this->_lastClock = 0;
  this->_img = NULL;
  this->_alpha = 0;
}

float       FadeAnimation::getAlpha() const
{
  return (this->_alpha);
}

bool		FadeAnimation::isRunning() const
{
  return (this->_running);
}
