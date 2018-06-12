//
// IProtocol.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "Converter.hpp"
#include "packet/PacketDeserializer.hpp"

class IProtocol
{
public:
	virtual ~IProtocol(void) {};

public:
	virtual bool process(const NetworkCommunicationType, Converter *, PacketDeserializer &) = 0;
};