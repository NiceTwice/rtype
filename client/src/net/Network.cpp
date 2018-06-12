//
// Network.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include <SFML/Network.hpp>
#include "net/Network.hpp"
#include "packet/PacketReceiver.hpp"
#include "Printer.hpp"
#include "gui/MainWindow.hpp"

#include "core/GameCore.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"
#include "net/exceptions/DisconnectionException.hpp"

Network Network::_instance = Network();

Network::Network()
{

}

Network::~Network()
{

}

Network& Network::getInstance()
{
    return (_instance);
}

bool Network::init()
{
	return (true);
}

bool Network::tcpConnect(const std::string &ip, uint16_t port)
{
	this->_serverIp = ip;
	return (this->_tcpManager.connect(ip, port));
}

uint16_t Network::udpListen(const std::string &ip)
{
	return (this->_udpManager.runServer(ip));
}

bool Network::udpConnect(const std::string &ip, uint16_t port)
{
	this->_udpManager.connectClient(ip, port);
	return (true);
}

void Network::destroy()
{
	this->_tcpManager.disconnect();
	this->_udpManager.disconnect();
	this->stop();
}

void Network::onError(const std::string &reason)
{
	Printer::error(reason);
	MainWindow::getInstance().close();
	this->destroy();
}

void Network::write(IManager &manager)
{
	try
	{
		manager.write();
	}
	catch (DisconnectionException &e)
	{
		this->onError("Server connection interrupted");
	}
}

void Network::read(IManager &manager)
{
	try
	{
		manager.read();
		while (PacketReceiver::get(manager));
	}
	catch (DisconnectionException &e)
	{
		this->onError("Server connection interrupted");
	}
}

void Network::run()
{
	sf::SocketSelector selector;

	selector.add(this->_tcpManager.getSocket().getSocket());
	selector.add(this->_udpManager.getServerSocket().getSocket());
	if (selector.wait(sf::milliseconds(30)))
	{
		if (this->_udpManager.isServerRunning()
			&& selector.isReady(this->_udpManager.getServerSocket().getSocket()))
			this->read(this->_udpManager);
		if (this->_tcpManager.isRunning()
			&& selector.isReady(this->_tcpManager.getSocket().getSocket()))
			this->read(this->_tcpManager);
	}
	
	if (this->_udpManager.isClientRunning() && GameCore::getInstance().isGameReady())
	{
		PacketSerializer response;

		response << GameCore::getInstance().isFiring();
		response << GameCore::getInstance().getPlayerDir();
		//std::cout << "isFiring: " << GameCore::getInstance().isFiring() << " - Dir: " << GameCore::getInstance().getPlayerDir() << std::endl;
		PacketSender::set(this->_udpManager, PacketIdentifier::ENTITY_PACKET, response);
	}

	this->write(this->_udpManager);
	this->write(this->_tcpManager);
}

void Network::ready(bool value)
{
	PacketSerializer response;

	response << value;
	PacketSender::set(this->_tcpManager, PacketIdentifier::READY_PACKET, response);
}

const std::string &Network::getServerIp()
{
	return (this->_serverIp);
}