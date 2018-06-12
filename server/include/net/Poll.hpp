//
// Poll.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Mon Dec 12 15:14:22 2016 Quentin Guerin
// Last update Mon Dec 12 15:14:23 2016 Quentin Guerin
//

#pragma once

# include <cstdlib>
# ifdef __linux__
typedef struct pollfd WSAPOLLFD;
#  include <poll.h>
# else
#  include <WinSock2.h>
# endif


# include <vector>

class Poll
{
public:
  Poll(void);
  ~Poll(void);

public:
  void addFd(WSAPOLLFD *);
  void setTimeout(int const&);

  int poll(void);

  int getTimeout(void) const;
  WSAPOLLFD* getFdsAsArray(void) const;
  std::vector<WSAPOLLFD *>& getFds(void);
  std::vector<WSAPOLLFD *> const& getFds(void) const;
  void resetFds(void);

  void erase(WSAPOLLFD *);

  uint64_t size(void) const;

protected:
  int m_timeout;
  std::vector<WSAPOLLFD *> m_fds;
  WSAPOLLFD *m_tmpFds;
};