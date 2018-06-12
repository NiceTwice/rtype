//
// PortPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/PortPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "core/GameCore.hpp"
#include "net/Network.hpp"
#include "Printer.hpp"

PortPacket::PortPacket()
{

}

PortPacket::~PortPacket()
{

}

bool PortPacket::process(IManager &, PacketDeserializer &packet)
{
	uint16_t port;

	packet >> port;
	Network::getInstance().udpConnect(Network::getInstance().getServerIp(), port);
	Printer::info("UDP client is connecting to server port #" + std::to_string(port));
	GameCore::getInstance().setNetReady(true);
	return (true);
}