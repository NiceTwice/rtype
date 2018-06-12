//
// EntityPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <map>
#include "packet/protocol/IProtocol.hpp"
#include "game/map/MovableEntity.hpp"

class EntityPacket : public IProtocol
{
public:
	EntityPacket();
	~EntityPacket();

public:
	bool process(IManager &, PacketDeserializer &);

private:
	void updatePlayer(std::map<uint64_t, MovableEntity *> *, PacketDeserializer &);
};