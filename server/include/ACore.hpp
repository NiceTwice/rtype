//
// ACore.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 02 15:12:17 2016 Quentin Guerin
// Last update Mon Dec 19 17:09:40 2016 Quentin Guerin
//

#pragma once

# include <memory>
# include "Converter.hpp"
# include "pool/ITask.hpp"
# include "pool/ThreadsPool.hpp"
# include "net/INetServer.hpp"
# include "net/ASocket.hpp"
# include "game/World.hpp"
# include "thread/StdMutex.hpp"

# ifdef __linux__
#  include "loader/SoLoader.hpp"
# else
#  include "loader/DllLoader.hpp"
# endif

# define VERSION 0.1

class TCPServer;

class ACore
{
public:
  ACore(unsigned int = 5);
  virtual ~ACore();

public:
  virtual bool init(unsigned short, int = 0) = 0;
  bool run(void);
  bool stop(void);
  void clientConnected(Converter *);
  void clientDisconnected(Converter *);
  void dataReceived(const NetworkCommunicationType, Converter *);

  void addTask(ITask *);

  INetServer *getNetworkServer(void);

public:
  static float version;
  static bool   m_running;

protected:
  ThreadsPool m_threadPool;
  unsigned short m_port;
  TCPServer* m_netServer;
  ILoader *m_loader;
  std::vector<World *> m_games;
  StdMutex mutex;
};
