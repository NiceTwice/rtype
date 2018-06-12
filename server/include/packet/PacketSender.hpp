//
// PacketSender.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "Converter.hpp"
#include "packet/PacketSerializer.hpp"

class PacketSender
{
public:
	PacketSender();
	~PacketSender();

public:
	static void set(const NetworkCommunicationType type, Converter *, uint16_t, PacketSerializer &);
};