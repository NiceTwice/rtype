//
// MapPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "packet/protocol/IProtocol.hpp"
#include "packet/PacketDeserializer.hpp"
#include "game/map/Map.hpp"

class MapPacket : public IProtocol
{
public:
	MapPacket();
	~MapPacket();

public:
	bool process(IManager &, PacketDeserializer &);

private:
	Map *getMap(PacketDeserializer &);
	const Chunk *getChunk(PacketDeserializer &);
	const MapEntity *getEntity(PacketDeserializer &);
};