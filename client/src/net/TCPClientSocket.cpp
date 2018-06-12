//
// TCPClientSocket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "net/TCPClientSocket.hpp"
#include "net/exceptions/DisconnectionException.hpp"

TCPClientSocket::TCPClientSocket()
{

}

TCPClientSocket::TCPClientSocket(const std::string &ip, uint16_t port) : _ip(ip), _port(port)
{

}

TCPClientSocket::~TCPClientSocket()
{

}

bool TCPClientSocket::connect()
{
	sf::Socket::Status status = this->_socket.connect(this->_ip, this->_port);
	if (status != sf::Socket::Done)
		return (false);
	return (true);
}

void TCPClientSocket::disconnect()
{
	this->_socket.disconnect();
}

int64_t TCPClientSocket::recv(void *data, uint64_t size, int)
{
	size_t readSize;

	if (this->_socket.receive(data, (size_t)size, readSize) == sf::Socket::Disconnected)
		throw DisconnectionException("Server disconnected");
	return (readSize);
}
  
int64_t TCPClientSocket::send(const void *data, uint64_t size, int)
{
	size_t writeSize = 0;
	sf::Socket::Status status;

	status = this->_socket.send(data, (size_t)size, writeSize);
	if (status == sf::Socket::Disconnected)
		throw DisconnectionException("Server disconnected");
	return (writeSize);
}

void TCPClientSocket::setBlocking(bool value)
{
	this->_socket.setBlocking(value);
}

sf::Socket &TCPClientSocket::getSocket()
{
	return (this->_socket);
}

void TCPClientSocket::setIp(const std::string &value)
{
	this->_ip = value;
}

const std::string &TCPClientSocket::getIp() const
{
	return (this->_ip);
}

void TCPClientSocket::setPort(uint16_t value)
{
	this->_port = value;
}

uint16_t TCPClientSocket::getPort() const
{
	return (this->_port);
}