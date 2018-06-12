//
// PacketProcesser.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <vector>
#include "Converter.hpp"
#include "packet/PacketDeserializer.hpp"
#include "packet/protocol/IProtocol.hpp"

class PacketProcesser
{
public:
	PacketProcesser();
	~PacketProcesser();

public:
	bool run(const NetworkCommunicationType, Converter *, PacketDeserializer &) const;

private:
	std::vector<IProtocol *> _packets;
};