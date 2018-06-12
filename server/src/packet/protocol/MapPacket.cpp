//
// MapPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/MapPacket.hpp"
#include "packet/PacketSender.hpp"
#include  "game/World.hpp"
#include "packet/protocol/PacketIdentifier.hpp"

MapPacket::MapPacket()
{

}

MapPacket::~MapPacket()
{

}

bool MapPacket::process(const NetworkCommunicationType type, Converter *client, PacketDeserializer &)
{
	PacketSerializer response;
	size_t i;
	size_t y;
	const Map *map;

	map = client->getPlayer().getWorld()->getMap();
	if (map == nullptr)
		return (false);
	response << map->getViewport();
	response << (uint32_t)map->getChunks().size();
	i = 0;
	while (i < map->getChunks().size())
	{
		response << map->getChunks()[i]->getBackground();
		response << map->getChunks()[i]->getWidth();
		response << (uint32_t)map->getChunks()[i]->getEntities().size();
		y = 0;
		while (y < map->getChunks()[i]->getEntities().size())
		{
			response << map->getChunks()[i]->getEntities()[y]->getSprite();
			response << map->getChunks()[i]->getEntities()[y]->getPosition();
			response << map->getChunks()[i]->getEntities()[y]->getSize();
			y++;
		}
		i++;
	}
	PacketSender::set(type, client, PacketIdentifier::MAP_PACKET, response);
	return (true);
}