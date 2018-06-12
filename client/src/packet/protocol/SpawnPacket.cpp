//
// SpawnPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/SpawnPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "core/GameCore.hpp"
#include "Printer.hpp"

SpawnPacket::SpawnPacket()
{

}

SpawnPacket::~SpawnPacket()
{

}

bool SpawnPacket::process(IManager &, PacketDeserializer &packet)
{
	uint32_t life;

	Printer::info("SpawnPacket received");
	packet >> life;
	GameCore::getInstance().setLife(life);
	return (true);
}