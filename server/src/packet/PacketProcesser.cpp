//
// PacketProcesser.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "packet/PacketProcesser.hpp"
#include "packet/protocol/HelloPacket.hpp"
#include "packet/protocol/MapPacket.hpp"
#include "packet/protocol/PortPacket.hpp"
#include "packet/protocol/ReadyPacket.hpp"
#include "packet/protocol/EntityPacket.hpp"
#include "packet/exceptions/InvalidPacketError.hpp"

PacketProcesser::PacketProcesser()
{
	this->_packets.push_back(new HelloPacket());
	this->_packets.push_back(new MapPacket());
	this->_packets.push_back(new PortPacket());
	this->_packets.push_back(new ReadyPacket());
	this->_packets.push_back(new EntityPacket());
}

PacketProcesser::~PacketProcesser()
{
	while (this->_packets.size() > 0) {
		delete (*(this->_packets.begin()));
		this->_packets.erase(this->_packets.begin());
	}
}

bool PacketProcesser::run(const NetworkCommunicationType type, Converter *client, PacketDeserializer &packet) const
{
	uint16_t packetId = packet.getPacketId();

	(void)type;
	if (packetId < this->_packets.size())
	{
		try
		{
			client->lock();
			this->_packets[packetId]->process(type, client, packet);
			client->unlock();
		}
		catch (InvalidPacketError &e)
		{
			std::cerr << "[ERROR] Invalid packet received" << std::endl;
		}
	}
	return (true);
}