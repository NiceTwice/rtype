//
// UDPClientSocket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "net/UDPClientSocket.hpp"

UDPClientSocket::UDPClientSocket()
{

}

UDPClientSocket::UDPClientSocket(const std::string &ip, uint16_t port) : _ip(ip), _port(port)
{

}

UDPClientSocket::~UDPClientSocket()
{

}

bool UDPClientSocket::connect()
{
	return (true);
}

int64_t UDPClientSocket::recv(void *, uint64_t, int)
{
	return (0);
}
  
int64_t UDPClientSocket::send(const void *data, uint64_t size, int)
{
	if (this->_socket.send(data, size, this->_ip, this->_port) != sf::Socket::Done)
		return (0);
	return (size);
}

void UDPClientSocket::setBlocking(bool value)
{
	this->_socket.setBlocking(value);
}

sf::Socket &UDPClientSocket::getSocket()
{
	return (this->_socket);
}

void UDPClientSocket::setIp(const std::string &value)
{
	this->_ip = value;
}

const std::string UDPClientSocket::getIp() const
{
	return (this->_ip.toString());
}

void UDPClientSocket::setPort(uint16_t value)
{
	this->_port = value;
}

uint16_t UDPClientSocket::getPort() const
{
	return (this->_port);
}