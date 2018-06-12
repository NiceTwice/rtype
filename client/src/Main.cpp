//
// Main.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 10:39:39 2016 Adrien Vasseur
// Last update Fri Dec  9 13:57:29 2016 Adrien Vasseur
//

#include	<cstdlib>
#include  <iostream>
#include	"Client.hpp"
#include  "ArgParser.hpp"
#include	"core/GameCore.hpp"
#include	"gui/res/ResPool.hpp"
#include  "gui/MainWindow.hpp"

static int usage(const char *binName)
{
  std::cerr << "Usage: " << binName << " SERVER_IP SERVER_PORT" << std::endl;
  return (EXIT_FAILURE);
}

void		garbageSingletons()
{
  delete GameCore::getInstancePtr();
  delete ResPool::getInstancePtr();
  delete MainWindow::getInstancePtr();
}

int			main(int argc, char **argv)
{
  Client	app;
  const char *ip;
  uint16_t port;
  int		ret;

  ret = EXIT_FAILURE;
  (void) argc;
  (void) argv;
  if (((ip = ArgParser::getIp(argc, argv)) == NULL)
      || ((port = ArgParser::getPort(argc, argv)) == 0))
    return (usage(argv[0]));
  if (app.initNetwork(ip, port) && app.exec())
    ret = EXIT_SUCCESS;
  garbageSingletons();
  return (ret);
}
