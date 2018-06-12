//
// TCPServer.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

# include <list>
# include "ACore.hpp"
# include "thread/StdMutex.hpp"
# include "net/ANetClient.hpp"
# include "net/INetServer.hpp"
# include "net/ASocket.hpp"
# include "net/Poll.hpp"
# include "Converter.hpp"
# include "thread/AStdThread.hpp"

# include "exceptions/TCPServerException.hpp"

class TCPServer : public INetServer, public AStdThread
{
public:
  TCPServer(ACore *) throw(TCPServerException);
  ~TCPServer();

public:
  bool  init();
  bool bind(unsigned short, int = 0);
  void run();
  bool  listen();
  void  cancel();

protected:
  bool _poll(void);
  bool _addNewClient(ANetClient<ATCPSocket, AUDPSocket> *);
  int _disconnect(WSAPOLLFD *);
  int64_t _inputReceived(WSAPOLLFD *) const;
  bool _outputOpen(WSAPOLLFD *) const;
  int64_t _inputReceived(const NetworkCommunicationType, Converter *) const;
  bool _outputOpen(const NetworkCommunicationType, Converter *) const;

private:
  ACore *m_parent;
  ATCPSocket *m_sock;
  std::list<Converter *> m_clients;
  Poll m_poll;
};