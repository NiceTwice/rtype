//
// UDPServerSocket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "net/UDPServerSocket.hpp"

UDPServerSocket::UDPServerSocket()
{

}

UDPServerSocket::UDPServerSocket(const std::string &ip, uint16_t port) : _ip(ip), _port(port)
{

}

UDPServerSocket::~UDPServerSocket()
{

}

bool UDPServerSocket::bind()
{
	if (this->_socket.bind(this->_port) != sf::Socket::Done)
		return (false);
	this->_port = this->_socket.getLocalPort();
	return (true);
}

bool UDPServerSocket::listen()
{
	return (false);
}

int64_t UDPServerSocket::recv(void *data, uint64_t size, int)
{
	size_t readSize;

	if (this->_socket.receive(data, size, readSize, this->_ip, this->_port) != sf::Socket::Done)
		return (0);
	return (readSize);
}
  
int64_t UDPServerSocket::send(const void *data, uint64_t size, int)
{
	return (0);
}

void UDPServerSocket::setBlocking(bool value)
{
	this->_socket.setBlocking(value);
}

sf::Socket &UDPServerSocket::getSocket()
{
	return (this->_socket);
}

void UDPServerSocket::setIp(const std::string &value)
{
	this->_ip = value;
}

const std::string UDPServerSocket::getIp() const
{
	return (this->_ip.toString());
}

void UDPServerSocket::setPort(uint16_t value)
{
	this->_port = value;
}

uint16_t UDPServerSocket::getPort() const
{
	return (this->_port);
}