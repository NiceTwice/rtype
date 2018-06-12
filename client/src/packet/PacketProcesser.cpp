//
// PacketProcesser.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/PacketProcesser.hpp"
#include "packet/protocol/HelloPacket.hpp"
#include "packet/protocol/MapPacket.hpp"
#include "packet/protocol/PortPacket.hpp"
#include "packet/protocol/ReadyPacket.hpp"
#include "packet/protocol/EntityPacket.hpp"
#include "packet/protocol/SpawnPacket.hpp"
#include "packet/protocol/EndPacket.hpp"
#include "packet/exceptions/InvalidPacketError.hpp"
#include "Printer.hpp"

PacketProcesser::PacketProcesser()
{
	this->_packets.push_back(new HelloPacket());
	this->_packets.push_back(new MapPacket());
	this->_packets.push_back(new PortPacket());
	this->_packets.push_back(new ReadyPacket());
	this->_packets.push_back(new EntityPacket());
	this->_packets.push_back(new SpawnPacket());
	this->_packets.push_back(new EndPacket());
}

PacketProcesser::~PacketProcesser()
{
	while (this->_packets.size() > 0) {
		delete *(this->_packets.begin());
		this->_packets.erase(this->_packets.begin());
	}
}

bool PacketProcesser::run(IManager &manager, PacketDeserializer &packet)
{
	uint16_t packetId = packet.getPacketId();

	//Printer::info("New packet #" + std::to_string(packetId));
	if (packetId < this->_packets.size())
	{
		try
		{
			this->_packets[packetId]->process(manager, packet);
		}
		catch (InvalidPacketError &e)
		{
			Printer::error(e.what());
		}
	}
	return (true);
}