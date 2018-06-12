//
// FrameAnimation.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 22:08:43 2016 Adrien Vasseur
// Last update Mon Dec 12 22:55:40 2016 Adrien Vasseur
//

#include	"gui/anim/FrameAnimation.hpp"

FrameAnimation::FrameAnimation()
{
  this->destroy();
}

FrameAnimation::~FrameAnimation()
{

}

void		FrameAnimation::addFrame(SFMLImage * const img)
{
  this->_frames.push_back(img);
}

void		FrameAnimation::setInterval(unsigned int value)
{
  this->_interval = value;
}

void		FrameAnimation::setRepeated(bool value)
{
  this->_repeated = value;
}

void		FrameAnimation::setPosition(const Vector2f &pos)
{
  this->_pos = pos;
}

void		FrameAnimation::start()
{
  this->_running = true;
  this->_clock.restart();
}

void		FrameAnimation::draw(SFMLImage *img)
{
  img->setPosition(this->_pos);
  img->display();
}

void		FrameAnimation::display()
{
  if (this->_frames.size() > 0)
    {
      if (this->_running)
		this->_lastClock = this->_clock.getElapsedTime();
      if (this->_interval == 0)
		this->draw(this->_frames[0]);
      else if (this->_repeated || this->_lastClock / this->_interval < this->_frames.size())
		this->draw(this->_frames[(this->_lastClock / this->_interval) % this->_frames.size()]);
      else
		this->draw(this->_frames[this->_frames.size() - 1]);
    }
}

void		FrameAnimation::stop()
{
  this->_running = false;
}

void        FrameAnimation::destroy()
{
  this->_running = false;
  this->_repeated = true;
  this->_interval = 200;
  this->_lastClock = 0;
  this->_frames.clear();
}

bool        FrameAnimation::isRunning() const
{
  return (this->_running);
}