//
// ACore.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 15:12:31 2016 Quentin Guerin
// Last update Mon Dec 19 17:13:04 2016 Quentin Guerin
//

#include "ACore.hpp"
#include "packet/PacketReceiver.hpp"
#include "packet/PacketSender.hpp"
# include "net/TCPServer.hpp"

#if (defined VERSION)
float ACore::version = VERSION;
#else
float ACore::version = 0;
#endif


bool    ACore::m_running = false;
/**
 * @param unsigned int threadCount Number of thread to create in threadPool
 *
 * Constructor for ACore class
 */

ACore::ACore(unsigned int threadCount): m_threadPool(threadCount), m_port(0), m_netServer(nullptr), m_loader(nullptr)
{
}

/**
 * Destructor for ACore class
 */

ACore::~ACore(void)
{
  if (this->m_netServer != nullptr)
    {
      this->m_netServer->stop();
      delete this->m_netServer;
    }
  if (this->m_loader != nullptr)
    delete this->m_loader;
}

/**
 * @return bool Success of operation
 *
 * Run the network server
 */

bool ACore::run(void)
{
  if (this->m_netServer != nullptr)
    this->m_netServer->run();
  return (true);
}

/**
 * @return bool Success of operation
 *
 * Stop the network server
 */

bool ACore::stop(void)
{
  return (ACore::m_running = false);
}

/**
 * @param ITask* task Task to add to the threadPool's tasklist
 *
 * Run the network server
 */

void ACore::addTask(ITask *task)
{
  this->m_threadPool.addTask(task);
}

/**
 * @return INetServer* Network server
 *
 * Get the network server
 */

INetServer *ACore::getNetworkServer(void)
{
  return (this->m_netServer);
}

/**
 * @param Converter* client New Client
 *
 * Notify server that a new client connected
 */

void ACore::clientConnected(Converter *client)
{
  this->mutex.lock();
  if (this->m_games.empty())
    this->m_games.push_back(new World(4));
  if (this->m_games.back()->isRunning()
    || this->m_games.back()->full())
    this->m_games.push_back(new World(4));
  this->m_games.back()->createPlayer(client);
  /*if (this->m_games.back()->getPlayerCount() == this->m_games.back()->getPlayerReady())
    this->m_games.back()->run();*/
  this->mutex.unlock();
  std::cerr << "[INFO] New client" << std::endl;
}

/**
 * @param Converter* client Client disconnected
 *
 * Notify server that a new client disconnected
 */
//TODO: Implement
void ACore::clientDisconnected(Converter *client)
{
  client->getPlayer().getWorld()->disconnectPlayer(client);
  std::cerr << "[INFO] Player left" << std::endl;
}

/**
 * @param Converter* client Client who received data
 *
 * Notify server that data has been received
 */

void ACore::dataReceived(const NetworkCommunicationType type, Converter *client)
{
  // std::cerr << "[INFO] Client received data" << std::endl;
  while (PacketReceiver::get(type, client) == true);
}