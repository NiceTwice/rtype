//
// UDPManager.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "net/UDPManager.hpp"
#include "Printer.hpp"

UDPManager::UDPManager()
{
	this->_clientRunning = false;
	this->_serverRunning = false;
}

UDPManager::~UDPManager()
{

}

bool UDPManager::connectClient(const std::string &ip, uint16_t port)
{
	this->_clientSocket.setIp(ip);
	this->_clientSocket.setPort(port);
	this->_clientRunning = true;
	this->_clientSocket.setBlocking(false);
	return (true);
}

uint16_t UDPManager::runServer(const std::string &ip)
{
	this->_serverSocket.setIp(ip);
	this->_serverSocket.setPort(0);
	this->_serverRunning = this->_serverSocket.bind();
	this->_serverSocket.setBlocking(false);
	return (this->_serverSocket.getPort());
}

void UDPManager::disconnect()
{
	this->_clientRunning = false;
	this->_serverRunning = false;
}

void UDPManager::write()
{
	uint64_t size = 1024;
	const char *buff;

	size = 1024;
	buff = this->_output.retrieve(size, true);
	if (size != 0)
		this->_clientSocket.send((void *)buff, size);
}

void UDPManager::read()
{
	uint64_t size = 1024;
	char *buff;

	size = 1024;
	buff = new char[size];
	size = this->_serverSocket.recv((void *)buff, size);
	if (size != 0)
	{
		//Printer::info("UDP: Received " + std::to_string(size) + " bytes");
		this->_input.insert(buff, size);
	}
	else
		delete [] buff;
}

bool UDPManager::isClientRunning() const
{
	return (this->_clientRunning);
}

bool UDPManager::isServerRunning() const
{
	return (this->_serverRunning);
}

const UDPClientSocket &UDPManager::getClientSocket() const
{
	return (this->_clientSocket);
}

UDPServerSocket &UDPManager::getServerSocket()
{
	return (this->_serverSocket);
}


RingBuffer &UDPManager::getInput()
{
	return (this->_input);
}

RingBuffer &UDPManager::getOutput()
{
	return (this->_output);
}