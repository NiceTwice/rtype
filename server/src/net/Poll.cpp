//
// Poll.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Mon Dec 12 15:26:47 2016 Quentin Guerin
// Last update Mon Dec 12 15:50:42 2016 Quentin Guerin
//

#include <iostream>
#include <string.h>
#include "net/Poll.hpp"

Poll::Poll(void): m_tmpFds(nullptr)
{
}

Poll::~Poll(void)
{
  while (this->m_fds.size() > 0) {
    delete *(this->m_fds.begin());
    this->m_fds.erase(this->m_fds.begin());
  }
  if (this->m_tmpFds != nullptr)
    delete[] this->m_tmpFds;
}

void Poll::addFd(WSAPOLLFD *fd)
{
  this->m_fds.push_back(fd);
}

void Poll::setTimeout(int const& to)
{
  this->m_timeout = to;
}

int Poll::poll(void)
{
  int ret;
  unsigned int i;

  if (this->size() > 0) {
    this->m_tmpFds = this->getFdsAsArray();
#ifdef __linux__
    ret = ::poll(this->m_tmpFds, this->size(), int(this->m_timeout));
#else
    ret = WSAPoll(this->m_tmpFds, this->size(), int(this->m_timeout));
#endif // __linux__

    for (i = 0; i < this->m_fds.size(); i++) {
      this->m_fds[i]->revents = this->m_tmpFds[i].revents;
    }
    delete[] this->m_tmpFds;
    this->m_tmpFds = nullptr;
    return (ret);
  }
  else
    return (0);
}

int Poll::getTimeout(void) const
{
  return (this->m_timeout);
}

WSAPOLLFD *Poll::getFdsAsArray(void) const
{
  unsigned int i;
  WSAPOLLFD *ret;
  WSAPOLLFD* const* fds;

  if (this->m_fds.size() == 0)
    return (nullptr);
  else {
    fds = &((this->m_fds)[0]);
    ret = new WSAPOLLFD[this->m_fds.size()];
    for (i = 0; i < this->m_fds.size(); i++) {
      memcpy(ret + i, *(fds + i), sizeof(WSAPOLLFD));
    }
    return (ret);
  }
}

std::vector<WSAPOLLFD *>& Poll::getFds(void)
{
  return (this->m_fds);
}

std::vector<WSAPOLLFD *> const& Poll::getFds(void) const
{
  return (this->m_fds);
}

void Poll::resetFds(void)
{
  std::vector<WSAPOLLFD *>::iterator it;

  for (it = this->m_fds.begin(); it != this->m_fds.end(); ++it) {
    delete *it;
  }
  this->m_fds.clear();
}

uint64_t Poll::size(void) const
{
  return (this->m_fds.size());
}

void Poll::erase(WSAPOLLFD *fd)
{
  std::vector<WSAPOLLFD *>::iterator it;

  for (it = this->m_fds.begin(); it != this->m_fds.end(); ++it) {
    if (*it == fd) {
      this->m_fds.erase(it);
      break;
    }
  }
}