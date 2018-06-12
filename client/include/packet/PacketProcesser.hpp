//
// PacketProcesser.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <vector>
#include "net/IManager.hpp"
#include "packet/protocol/IProtocol.hpp"
#include "packet/PacketDeserializer.hpp"

class PacketProcesser
{
public:
	PacketProcesser();
	~PacketProcesser();

public:
	bool run(IManager &, PacketDeserializer &);

private:
	std::vector<IProtocol *> _packets;
};