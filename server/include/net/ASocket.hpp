//
// ASocket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

# include "net/ISocket.h"
# include "net/SocketAddress.hpp"
# include "exceptions/SocketException.hpp"

# ifdef __linux__

#  include <string.h>
#  include <unistd.h>
#  include <netinet/in.h>
#  include <sys/socket.h>
#  include <sys/ioctl.h>
#  define INVALID_SOCKET -1
#  define SOCKET_ERROR -1
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
typedef unsigned int SOCKLEN_T;

# else

#  include <memory.h>
#  include <winsock2.h>
#  include <Ws2tcpip.h>
typedef int SOCKLEN_T;

# endif

class ASocket : public ISocket
{
public:
  ASocket();
  virtual ~ASocket();

public:

  virtual bool init(void);
  virtual bool run(void);
  virtual bool stop(void);

  ASocket& findSocketAddress(void);

  ASocket& setPort(uint16_t port);

  virtual int64_t recv(void *, uint64_t, int);
  virtual int64_t send(const void *, uint64_t, int);

  SOCKET const& getSocket(void) const;
  SocketAddress const& getSocketAddress() const;

  bool const& isRunning() const;

protected:
  virtual bool _bind(void) = 0;
  virtual void _close(void);

  ASocket& _setRunning(bool = true);

protected:
  bool m_running;
  SOCKET m_sock;
  SocketAddress m_saddr;
};