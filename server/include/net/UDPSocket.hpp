////////////////////////////////////////////////////////////////////
// PName : rtype
// File Name : UDPSocket.hpp
// Created by : pain_l (15/DEC/16)
////////////////////////////////////////////////////////////////////

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include "net/AUDPSocket.hpp"

#define BSDBLOCK
const long LOCAL_NONBLOCK = 1;
// With BSDBLOCK defined, we don't need FIONBIO.
//const long LOCAL_FL_SET = FIONBIO ;
const int LOCAL_BLOCKING_ERROR = EAGAIN;
const int LOCAL_CONNECT_BLOCKING = EINPROGRESS;

class UDPSocket: public AUDPSocket
{
  public:
    UDPSocket();
    ~UDPSocket();
};

#endif // UDPSOCKET_HPP_
