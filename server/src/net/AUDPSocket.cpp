//
// AUDPSocket.cpp for R-Type - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Fri Dec 23 13:35:38 2016 Quentin Guerin
// Last update Fri Dec 23 13:35:39 2016 Quentin Guerin
//

#include <fcntl.h>
#include "net/AUDPSocket.hpp"

AUDPSocket::AUDPSocket()
{
}

/**
 * Destructor
 */

AUDPSocket::~AUDPSocket()
{
}

/**
 * @return int number of byte sent
 * @param void* data Buffer containing the data to be send
 * @param uint64_t size Number of bytes to send
 * @param int flags Flags
 * @param SocketAddress const& saddr Target
 *
 * Binding for sendto
 */

int64_t AUDPSocket::sendto(const void *data, uint64_t len, int flags, SocketAddress const& addr)
{
  return (::sendto(this->m_sock, reinterpret_cast<const char *>(data), len, flags,
		   reinterpret_cast<const SOCKADDR *>(&addr.getAddressInfo()), sizeof(addr.getAddressInfo())));
}

/**
 * @return int number of byte received
 * @param void* data Buffer containing the data received
 * @param uint64_t size Max number of bytes to receive
 * @param int flags Flags
 * @param SocketAddress& saddr Sender
 *
 * Binding for recvfrom
 */

int64_t AUDPSocket::recvfrom(void *data, uint64_t len, int flags, SocketAddress& saddr)
{
  int64_t ret;
  SOCKADDR_IN in_saddr;
  SOCKLEN_T address_len = sizeof(SOCKADDR_IN);

  memset(&in_saddr, 0, address_len);
  ret = ::recvfrom(this->m_sock, reinterpret_cast<char *>(data), len, flags,
		     reinterpret_cast<SOCKADDR *>(&in_saddr), &address_len);
  saddr = SocketAddress(in_saddr);
  return (ret);
}

/**
 * @return bool Success of operation
 *
 * Binding for bind
 */

bool AUDPSocket::_bind(void)
{
  SOCKET sock;

  this->_close();
  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    throw SocketException("Unable to create socket");
  else
    this->m_sock = sock;
  if (::bind(this->m_sock, (SOCKADDR *)&(this->m_saddr.getAddressInfo()),
       sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    throw SocketException("Unable to bind socket on this port.");
  return (true);
}

AUDPSocket& AUDPSocket::setTarget(SocketAddress const& saddr)
{
  this->m_target = saddr;
  return (*this);
}

bool AUDPSocket::setRecvBufferSize(int size)
{
  if (::setsockopt(this->m_sock, (int) SOL_SOCKET, (int) SO_RCVBUF, (char *) &size, sizeof(int)))
    throw SocketException("setsockopt: error");
  return true;
}

bool AUDPSocket::setReuseAddress(bool b)
{
  int bOption = b;
  if (::setsockopt(this->m_sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&bOption, sizeof(bOption)) != 0)
    throw SocketException("setsockopt: error");
  return true;
}

SocketAddress AUDPSocket::getPeerName() const
{
  SOCKADDR_IN name;
  SOCKLEN_T name_len = sizeof(name);

  memset(&name, 0, name_len);
  getpeername(this->m_sock, (sockaddr * )&name, &name_len);
  return (SocketAddress(name));
}

SocketAddress const& AUDPSocket::getTarget(void) const
{
  return (this->m_target);
}

SOCKET& AUDPSocket::_getSocketRef(void)
{
  return (this->m_sock);
}

SocketAddress& AUDPSocket::_getSocketAddressRef(void)
{
  return (this->m_saddr);
}