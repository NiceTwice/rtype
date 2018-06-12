////////////////////////////////////////////////////////////////////
// Project : rtype
// File Name : SocketAddress.hpp
// Created by : pain_l (14/DEC/2016)
////////////////////////////////////////////////////////////////////

#ifndef SOCKETADDRESS_HPP
#define SOCKETADDRESS_HPP

#ifdef __linux__
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <cstdint>
#else
#include <memory.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#endif

#include <iostream>

typedef struct sockaddr_in SOCKADDR_IN;

class SocketAddress
{
  public :
    SocketAddress(uint16_t port = 0u);
    SocketAddress(const SOCKADDR_IN &addr);
    SocketAddress(const SocketAddress &addr);
    ~SocketAddress();

    const SOCKADDR_IN &getAddressInfo() const;

    SocketAddress& setPort(uint16_t port);
    SocketAddress& setAnyIp(uint16_t port);
    SocketAddress& setBroadcast(uint16_t port);
    bool setHost(const std::string &hostname, uint16_t port);
    void clear();

    uint16_t getPort() const;
    std::string getIp() const;

  public:
    bool operator==(SocketAddress const&) const;
    bool operator!=(SocketAddress const&) const;

  private:
    SOCKADDR_IN _addr;
};

#endif // SOCKETADDRESS_HPP