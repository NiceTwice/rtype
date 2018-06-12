//
// ReadyPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/ReadyPacket.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"
#include "game/World.hpp"

ReadyPacket::ReadyPacket()
{

}

ReadyPacket::~ReadyPacket()
{

}

void ReadyPacket::broadcast(World &world)
{
	PacketSerializer response;
	std::vector<Converter *> playerList;

	response << (uint16_t)(world.getPlayerCount());
	response << (uint16_t)(world.getPlayerReady());
	world.lock();
	playerList = world.getPlayerList();
	for (auto &player : playerList)
		PacketSender::set(NetworkCommunicationType::TCP, player, PacketIdentifier::READY_PACKET, response);
	world.unlock();
}

bool ReadyPacket::process(const NetworkCommunicationType, Converter *client, PacketDeserializer &packet)
{
	bool ready;

	packet >> ready;
	client->getPlayer().setReady(ready);
	if (client->getPlayer().getWorld()->getPlayerCount() == client->getPlayer().getWorld()->getPlayerReady())
		client->getPlayer().getWorld()->run();
	this->broadcast(*(client->getPlayer().getWorld()));
	return (true);
}