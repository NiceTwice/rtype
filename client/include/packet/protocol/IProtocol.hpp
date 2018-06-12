//
// IProtocol.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/IManager.hpp"
#include "packet/PacketDeserializer.hpp"
#include "packet/protocol/PacketIdentifier.hpp"

class IProtocol
{
public:
	virtual bool process(IManager &, PacketDeserializer &) = 0;
};