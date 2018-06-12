//
// PacketSender.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/PacketSender.hpp"

bool PacketSender::set(IManager &manager, uint16_t packetId, PacketSerializer &packet)
{
	uint64_t size = 0;
	unsigned char *bytes = packet.pack(packetId, size);

	manager.getOutput().insert((char *)bytes, size);
	return (true);
}