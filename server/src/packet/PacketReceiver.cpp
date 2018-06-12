//
// PacketReceiver.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "packet/PacketReceiver.hpp"
#include "packet/PacketProcesser.hpp"

PacketReceiver::PacketReceiver()
{

}

PacketReceiver::~PacketReceiver()
{

}

bool PacketReceiver::get(const NetworkCommunicationType type, Converter *client)
{
	PacketDeserializer packet;
	PacketProcesser processer;
	uint32_t sizeLength;
	uint32_t sizeContent;
	uint32_t packetId;
	uint64_t size = 2;
	const char *ret = client->getClient()->retrieve(type, size, false);

	if (size < 2)
		return (PacketReceiver::onError(ret));
	sizeLength = packet.parseLenghtSize(reinterpret_cast<const unsigned char *>(ret));
	if (sizeLength > 0)
	{
		delete [] ret;
		if ((ret = PacketReceiver::appendSize(type, client, size, sizeLength)) == NULL)
			return (PacketReceiver::onError(ret));
		sizeContent = packet.parseContentSize(reinterpret_cast<const unsigned char *>(ret));
		if (sizeContent > 0)
		{
			delete [] ret;
			if ((ret = PacketReceiver::appendSize(type, client, size, sizeContent)) == NULL)
				return (PacketReceiver::onError(ret));
		}
	}
	delete [] ret;
	ret = client->getClient()->retrieve(type, size);
	(void)(packetId = packet.unpack(reinterpret_cast<const unsigned char *>(ret)));
	// std::cerr << "[INFO] New " << (type == NetworkCommunicationType::UDP ? "UDP" : "TCP")<< " packet #" << packetId << std::endl;
	processer.run(type, client, packet);
	delete [] ret;
	return (true);
}

bool PacketReceiver::onError(const char *ret)
{
	if (ret != NULL)
		delete [] ret;
	return (false);
}

const char *PacketReceiver::appendSize(const NetworkCommunicationType type, Converter *client, uint64_t &actualSize, uint32_t length)
{
	const char *ret;
	uint64_t expectedSize;

	expectedSize = actualSize + length;
	actualSize += length;
	ret = client->getClient()->retrieve(type, actualSize, false);
	if (actualSize != expectedSize)
	{
		delete [] ret;
		return (NULL);
	}
	return (ret);
}