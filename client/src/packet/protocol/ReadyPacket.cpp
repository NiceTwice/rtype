//
// ReadyPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/ReadyPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "core/GameCore.hpp"
#include "Printer.hpp"

ReadyPacket::ReadyPacket()
{

}

ReadyPacket::~ReadyPacket()
{

}

bool ReadyPacket::process(IManager &, PacketDeserializer &packet)
{
	uint16_t playersCount;
	uint16_t readyCount;

	packet >> playersCount;
	packet >> readyCount;
	Printer::info("ReadyPacket received");
	GameCore::getInstance().setPlayers(playersCount);
	GameCore::getInstance().setReadyPlayers(readyCount);
	if (playersCount == readyCount)
		GameCore::getInstance().setGameReady(true);
	return (true);
}