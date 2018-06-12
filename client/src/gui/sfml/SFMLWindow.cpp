//
// SFMLWindow.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 10:21:39 2016 Adrien Vasseur
// Last update Fri Dec  2 15:26:55 2016 Adrien Vasseur
//

#include	"gui/sfml/SFMLWindow.hpp"
#include	"gui/MainWindow.hpp"

SFMLWindow::SFMLWindow()
{
  this->_scale = 1.0f;
}

SFMLWindow::~SFMLWindow()
{
  if (this->_window.isOpen())
    this->_window.close();
}

void		SFMLWindow::open()
{
  this->_border.setFillColor(sf::Color(0, 0, 0));
  this->_window.create(sf::VideoMode(1024, 768), "RType");
  this->_window.setFramerateLimit(60);
}

void		SFMLWindow::resize(unsigned int width, unsigned int height)
{
  double	aspectRatio = ((float) MainWindow::getInstance().getWidth()) / ((float) MainWindow::getInstance().getHeight());
  double	newAspectRatio = ((float) width) / ((float) height);
  sf::View	newView;

  if (newAspectRatio > aspectRatio)
    this->_scale = ((float) height) / ((float) MainWindow::getInstance().getHeight());
  else
    this->_scale = ((float) width) / ((float) MainWindow::getInstance().getWidth());
  newView.reset(sf::FloatRect(- (((float) width) - ((float) MainWindow::getInstance().getWidth()) * this->_scale) / 2.0f,
			      - (((float) height) - ((float) MainWindow::getInstance().getHeight()) * this->_scale) / 2.0f, (float) width, (float) height));
  this->_window.setView(newView);
}

void        SFMLWindow::resize()
{
  this->resize(this->_window.getSize().x, this->_window.getSize().y);
}

void		SFMLWindow::update()
{
  this->_border.setSize(sf::Vector2f((((float) this->_window.getSize().x) - ((float) MainWindow::getInstance().getWidth()) * this->_scale) / 2.0f,
				     ((float) this->_window.getSize().y)));
  this->_border.setPosition(- (((float) this->_window.getSize().x) - ((float) MainWindow::getInstance().getWidth()) * this->_scale) / 2.0f,
			    - (((float) this->_window.getSize().y) - ((float) MainWindow::getInstance().getHeight()) * this->_scale) / 2.0f);
  this->_window.draw(this->_border);
  this->_border.setPosition(((float) this->_window.getSize().x) - this->_border.getSize().x * 2,
			    - (((float) this->_window.getSize().y) - ((float) MainWindow::getInstance().getHeight()) * this->_scale) / 2.0f);
  this->_window.draw(this->_border);
  this->_border.setSize(sf::Vector2f(((float) this->_window.getSize().x),
				     (((float) this->_window.getSize().y) - ((float) MainWindow::getInstance().getHeight()) * this->_scale) / 2.0f));
  this->_border.setPosition(- (((float) this->_window.getSize().x) - ((float) MainWindow::getInstance().getWidth()) * this->_scale) / 2.0f,
			    - (((float) this->_window.getSize().y) - ((float) MainWindow::getInstance().getHeight()) * this->_scale) / 2.0f);
  this->_window.draw(this->_border);
  this->_border.setPosition(- (((float) this->_window.getSize().x) - ((float) MainWindow::getInstance().getWidth()) * this->_scale) / 2.0f,
			    ((float) this->_window.getSize().y) - this->_border.getSize().y * 2);
  this->_window.draw(this->_border);
  this->_window.display();
  this->_window.clear();
}

void		SFMLWindow::close()
{
  this->_window.close();
}

bool		SFMLWindow::isOpen()
{
  return (this->_window.isOpen());
}

bool		SFMLWindow::pollEvent(SFMLEvent &evt)
{
  return (this->_window.pollEvent(evt.getHandler()));
}

float		SFMLWindow::getScale()
{
  return (this->_scale);
}

sf::RenderWindow	&SFMLWindow::getHandler()
{
  return (this->_window);
}
