//
// EntityPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet/protocol
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "packet/protocol/IProtocol.hpp"

class EntityPacket : public IProtocol
{
public:
	EntityPacket();
	~EntityPacket();

public:
	bool process(const NetworkCommunicationType, Converter *, PacketDeserializer &);
};