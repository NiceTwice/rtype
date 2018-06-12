//
// Core.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 15:40:13 2016 Quentin Guerin
// Last update Mon Dec 19 17:13:38 2016 Quentin Guerin
//

#include <iostream>
#include <thread>
#include <chrono>
#include "net/TCPServer.hpp"
#include "Core.hpp"
#include "GameUpdater.hpp"

/**
 * @param unsigned int threadCount Number of thread to create in threadPool
 *
 * Constructor for Core class
 */

Core::Core(unsigned int threadCount): ACore(threadCount)
{
}

/**
 * Destructor for Core class
 */

Core::~Core(void)
{
}

/**
 * @param unsigned int const& port Port to use for TCP connections
 *
 * Initializer
 */

bool Core::init(unsigned short port, int timeout)
{
  this->m_port = port;
  try {
    this->m_netServer = new TCPServer(this);
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    this->m_netServer = nullptr;
    return (false);
  }
  if (this->m_netServer->bind(port, timeout) == false)
    return (false);

  try {
#ifdef __linux__
    this->m_loader = new SoLoader();
#else
    this->m_loader = new DllLoader();
#endif
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    this->m_loader = nullptr;
    return (false);
  }

  return (true);
}

/**
 * @return bool Success of operation
 *
 * Run the network server
 */

bool Core::run(void)
{
  if (this->m_netServer != nullptr) {
    this->m_netServer->start();
  }
  this->m_running = true;
  while (this->m_running)
	 {
     this->mutex.lock();
	    for (auto& world : this->m_games)
        {
	        if (!world->inUpdate() && world->isRunning())
            this->addTask(new GameUpdater(*world));
        }
      this->mutex.unlock();
	  std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
  this->m_netServer->stop();
  this->m_netServer->join();
  return (true);
}
