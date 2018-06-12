//
// main.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/srcs
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Nov 29 11:07:46 2016 Quentin Guerin
// Last update Fri Dec 02 11:39:52 2016 Quentin Guerin
//

#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#endif // _WIN32

#include <signal.h>
#include <cstdlib>
#include <iostream>
#include <climits>
#include "game/map/MapPool.hpp"
#include "ArgumentParser.hpp"
#include "Core.hpp"
#include "exceptions/SigIntException.hpp"



static void handleSig(int a)
{
  (void)a;
  ACore::m_running = false;
//  throw SigIntException();
}

/**
 * @return int Success of operation
 * @param const char* progname Name of program
 *
 * Display usage
 */

static int usage(const char *progname)
{
  std::cerr << "Usage : " << progname << " [OPTIONS]..." << std::endl;
  std::cerr << std::endl;
  std::cerr << "The mandatory arguments for the long options are also mandatory for the short ones." << std::endl;
  std::cerr << "  -p, --port [PORT]\t\tsets the listening port (DEFAULT: ";

#ifdef DEFAULT_PORT
  std::cerr << DEFAULT_PORT;
#else
  std::cerr << 8080u;
#endif
  std::cerr << ")" << std::endl;

  std::cerr << "  -t, --timeout [TIMEOUT]\tsets the timeout for poll (Reduces CPU usage)" << std::endl;
  std::cerr << "  -h, --help\t\t\tshows this help" << std::endl;
  return (EXIT_SUCCESS);
}

/**
 * @return unsigned short Port
 * @param ArgumentParser const& ap ArgumentParser holding arguments
 *
 * Retrieve port from arguments
 */

static unsigned short getPort(ArgumentParser const& ap)
{
#ifdef DEFAULT_PORT
  unsigned long port = DEFAULT_PORT;
#else
  unsigned long port = 8080u;
#endif
  size_t idx;

  if (ap.flagExists(true, "--port", "-p") == true) {
    std::string portArgument = ap.getValueForFlag("--port", "-p");
    {
      unsigned long tmp;

      tmp = std::stoul(portArgument, &idx, 0);
      if (portArgument.size() == idx)
	port = tmp;
      else {
	throw ArgumentParserException("Invalid port");
      }
    }
  }
  else {
    std::cerr << "[WARNING] Port not specified, using default value -> " << port << std::endl;
  }

  if (port > USHRT_MAX || port == 0)
    return (0);
  return (static_cast<unsigned short>(port));
}

int main(int argc, char **argv, char **env)
{
  unsigned short port;
  Core core(7);
  const ArgumentParser ap(argc, argv, env);

  signal(SIGINT, &handleSig);
  ACore::m_running = true;
  try {
    if (ap.flagExists(false, "--help", "-h") == true || (port = getPort(ap)) == 0)
      return (!usage(argv[0]));
    if (!core.init(port, 100) || !MapPool::getInstance().loadAll())
      return (EXIT_FAILURE);
    core.run();
  }
  catch (SigIntException const& e) {
    core.stop();
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    return (!usage(argv[0]));
  }
  delete MapPool::getInstancePtr();
  return (EXIT_SUCCESS);
}
