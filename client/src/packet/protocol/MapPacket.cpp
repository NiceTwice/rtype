//
// MapPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/MapPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "core/GameCore.hpp"
#include "net/Network.hpp"
#include "Printer.hpp"

MapPacket::MapPacket()
{

}

MapPacket::~MapPacket()
{

}

const MapEntity *MapPacket::getEntity(PacketDeserializer &packet)
{
	uint16_t entitySprite;
	Vector2f entityPosition;
	Vector2f entitySize;

	MapEntity *entity = new MapEntity();
	packet >> entitySprite;
	entity->setSprite(entitySprite);
	packet >> entityPosition;
	entity->setPosition(entityPosition);
	packet >> entitySize;
	entity->setSize(entitySize);
	std::cout << "	Entity: Sprite = " << entitySprite << " - Position = " << entityPosition << " - Size = " << entitySize << std::endl;
	return (entity);
}

const Chunk *MapPacket::getChunk(PacketDeserializer &packet)
{
	Chunk *chunk;
	uint32_t i;
	uint32_t entitiesSize;
	uint8_t chunkBackground;
	uint32_t chunkWidth;

	chunk = new Chunk();
	packet >> chunkBackground;
	chunk->setBackground(chunkBackground);
	packet >> chunkWidth;
	chunk->setWidth(chunkWidth);
	std::cout << "Chunk: Background = " << (int)chunkBackground << " - Width = " << chunkWidth << std::endl;
	packet >> entitiesSize;
	i = 0;
	while (i < entitiesSize)
	{
		chunk->addEntity(this->getEntity(packet));
		i++;
	}
	return (chunk);
}

Map *MapPacket::getMap(PacketDeserializer &packet)
{
	Map *map = new Map("");
	uint32_t i;
	uint32_t chunksSize;
	Vector2f viewport;

	packet >> viewport;
	map->setViewport(viewport);
	packet >> chunksSize;
	std::cout << "Viewport = " << viewport << std::endl;
	i = 0;
	while (i < chunksSize)
	{
		map->addChunk(this->getChunk(packet));
		i++;
	}
	return (map);	
}

bool MapPacket::process(IManager &manager, PacketDeserializer &packet)
{
	uint16_t port;
	PacketSerializer response;

	Printer::info("MapPacket received");
	try
	{
		GameCore::getInstance().setMap(this->getMap(packet));
	}
	catch (std::invalid_argument &e)
	{
		Printer::error("Invalid map");
		return (false);
	}
	port = Network::getInstance().udpListen(Network::getInstance().getServerIp());
	response << port;
	Printer::info("UDP server is running in port #" + std::to_string(port));
	PacketSender::set(manager, PacketIdentifier::PORT_PACKET, response);
	return (true);
}