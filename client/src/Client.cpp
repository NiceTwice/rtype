//
// Client.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:10:01 2016 Adrien Vasseur
// Last update Fri Dec  9 13:57:10 2016 Adrien Vasseur
//

#include	"Client.hpp"
#include	"gui/res/ResPool.hpp"
#include	"gui/MainWindow.hpp"
#include	"net/Network.hpp"

Client::Client()
{

}

Client::~Client()
{

}

bool		Client::initNetwork(const std::string &ip, uint16_t port)
{
	return (Network::getInstance().tcpConnect(ip, port));
}

bool		Client::exec()
{
  if (!MainWindow::getInstance().init())
    return (false);
  Network::getInstance().start();
  MainWindow::getInstance().run();
  Network::getInstance().join();
  return (true);
}