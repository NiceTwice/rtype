////////////////////////////////////////////////////////////////////
// Project : rtype
// File Name : SocketAddress.cpp
// Created by : pain_l (14/12/16)
////////////////////////////////////////////////////////////////////

#define	_WINSOCK_DEPRECATED_NO_WARNINGS
#include "net/SocketAddress.hpp"

SocketAddress::~SocketAddress() {}

SocketAddress::SocketAddress(uint16_t port)
{
  this->_addr.sin_family = AF_INET;
  this->_addr.sin_addr.s_addr = INADDR_ANY;
  this->_addr.sin_port = htons(port);
}

SocketAddress::SocketAddress(const SOCKADDR_IN &addr)
{
  this->_addr.sin_family = addr.sin_family;
  this->_addr.sin_addr.s_addr = addr.sin_addr.s_addr;
  this->_addr.sin_port = addr.sin_port;
}

SocketAddress::SocketAddress(const SocketAddress &addr)
{
  this->_addr.sin_family = addr._addr.sin_family;
  this->_addr.sin_addr.s_addr = addr._addr.sin_addr.s_addr;
  this->_addr.sin_port = addr._addr.sin_port;
}

const SOCKADDR_IN &SocketAddress::getAddressInfo() const
{
  return this->_addr;
}

SocketAddress& SocketAddress::setPort(uint16_t port)
{
  this->_addr.sin_port = htons(port);
  return (*this);
}

SocketAddress& SocketAddress::setAnyIp(uint16_t port)
{
  this->_addr.sin_family = AF_INET;
  this->_addr.sin_addr.s_addr = INADDR_ANY;
  this->_addr.sin_port = htons(port);
  return (*this);
}

SocketAddress& SocketAddress::setBroadcast(uint16_t port)
{
  this->_addr.sin_family = AF_INET;
  this->_addr.sin_addr.s_addr = 0xffffffff;
  this->_addr.sin_port = htons(port);
  return (*this);
}

void SocketAddress::clear()
{
  _addr.sin_family = AF_INET;
  _addr.sin_addr.s_addr = INADDR_ANY;
  _addr.sin_port = htons(0);
}

bool SocketAddress::setHost(const std::string &hostname, uint16_t port)
{
  struct hostent *hp = NULL;
  long addr = (long)inet_addr(hostname.c_str());
  if (addr == INADDR_NONE)
  {
    hp = gethostbyname(hostname.c_str());
    if (hp == NULL)
      return false;
    else
      memcpy(&_addr.sin_addr, hp->h_addr_list[0], (unsigned int) hp->h_length);
  }
  else
    memcpy(&_addr.sin_addr, &addr, sizeof(addr));

  _addr.sin_port = htons(port);
  _addr.sin_family = AF_INET;
  return true;
}

uint16_t SocketAddress::getPort() const
{
  return ntohs(this->_addr.sin_port);
}

std::string SocketAddress::getIp() const
{
  return std::string(inet_ntoa(this->_addr.sin_addr));
}

bool SocketAddress::operator==(SocketAddress const& other) const
{
  return (this->_addr.sin_family == other._addr.sin_family &&
	  this->_addr.sin_addr.s_addr == other._addr.sin_addr.s_addr &&
	  this->_addr.sin_port == other._addr.sin_port);
}

bool SocketAddress::operator!=(SocketAddress const& other) const
{
  return (!(*this == other));
}