//
// PacketSender.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/srcs/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "packet/PacketSender.hpp"

PacketSender::PacketSender()
{

}

PacketSender::~PacketSender()
{

}

void PacketSender::set(const NetworkCommunicationType type, Converter *client, uint16_t packetId, PacketSerializer &packet)
{
	uint64_t size = 0;
	unsigned char *bytes = packet.pack(packetId, size);

	// std::cerr << "[INFO] Sending packet #" << packetId << " using " << (NetworkCommunicationType::TCP == type ? "TCP" : "UDP") << std::endl;
	client->getClient()->bufferize(type, reinterpret_cast<const char *>(bytes), size);
}