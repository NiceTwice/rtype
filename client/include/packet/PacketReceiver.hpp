//
// PacketReceiver.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/IManager.hpp"
#include "net/RingBuffer.hpp"

class PacketReceiver
{
public:
	static bool get(IManager &);

private:
	static bool onError(const char *);
	static const char *appendSize(RingBuffer &, uint64_t &actualSize, uint32_t length);
};