//
// HelloPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/HelloPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "Printer.hpp"

HelloPacket::HelloPacket()
{

}

HelloPacket::~HelloPacket()
{

}

bool HelloPacket::process(IManager &manager, PacketDeserializer &packet)
{
	float version;
	PacketSerializer response;

	Printer::info("HelloPacket received");
	packet >> version;
	if (RTYPE_VERSION != version)
	{
		Printer::error("Client not up-to-date");
		return (false);
	}
	PacketSender::set(manager, PacketIdentifier::MAP_PACKET, response);
	return (true);
}