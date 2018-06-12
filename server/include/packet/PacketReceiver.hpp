//
// PacketReceiver.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
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

class PacketReceiver
{
public:
	PacketReceiver();
	~PacketReceiver();

public:
	static bool get(const NetworkCommunicationType, Converter *);

private:
	static bool onError(const char *);
	static const char *appendSize(const NetworkCommunicationType, Converter *, uint64_t &, uint32_t);
};