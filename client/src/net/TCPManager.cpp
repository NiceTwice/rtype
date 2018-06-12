//
// TCPManager.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <cstdint>
#include <cstring>
#include "net/TCPManager.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"
#include "Printer.hpp"

TCPManager::TCPManager()
{
	this->_running = false;
}

TCPManager::~TCPManager()
{

}

bool TCPManager::connect(const std::string &ip, uint16_t port)
{
	PacketSerializer packet;

	this->_socket.setIp(ip);
	this->_socket.setPort(port);
	if (!(this->_running = this->_socket.connect()))
	{
		Printer::error("Unable to connect to server.");
		return (false);
	}
	Printer::info("Connect to server");
	PacketSender::set(*this, PacketIdentifier::HELLO_PACKET, packet);
	this->_socket.setBlocking(false);
	return (true);
}

void TCPManager::disconnect()
{
	if (this->isRunning())
		this->_socket.disconnect();
	this->_running = false;
}

void TCPManager::write()
{
	uint64_t size = 1024;
	const char *buff;

	size = 1024;
	buff = this->_output.retrieve(size, true);
	if (size != 0)
		this->_socket.send((void *)buff, size);
}

void TCPManager::read()
{
	uint64_t size = 1024;
	char *buff;

	size = 1024;
	buff = new char[size];
	size = this->_socket.recv((void *)buff, size);
	if (size != 0)
	{
		//Printer::info("Received " + std::to_string(size) + " bytes");
		this->_input.insert(buff, size);
	}
	else
		delete [] buff;
}

bool TCPManager::isRunning() const
{
	return (this->_running);
}

TCPClientSocket &TCPManager::getSocket()
{
	return (this->_socket);
}

RingBuffer &TCPManager::getInput()
{
	return (this->_input);
}

RingBuffer &TCPManager::getOutput()
{
	return (this->_output);
}