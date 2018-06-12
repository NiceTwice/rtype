//
// PacketReceiver.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/PacketReceiver.hpp"
#include "packet/PacketProcesser.hpp"
#include "packet/PacketDeserializer.hpp"
#include "Printer.hpp"

bool PacketReceiver::get(IManager &manager)
{
	PacketDeserializer packet;
	PacketProcesser processer;
	uint32_t sizeLength;
	uint32_t sizeContent;
	uint64_t size = 2;
	const char *ret = manager.getInput().retrieve(size, false);

	if (size < 2)
		return (PacketReceiver::onError(ret));
	sizeLength = packet.parseLenghtSize(reinterpret_cast<const unsigned char *>(ret));
	if (sizeLength > 0)
	{
		delete [] ret;
		if ((ret = PacketReceiver::appendSize(manager.getInput(), size, sizeLength)) == NULL)
			return (PacketReceiver::onError(ret));
		sizeContent = packet.parseContentSize(reinterpret_cast<const unsigned char *>(ret));
		if (sizeContent > 0)
		{
			delete [] ret;
			if ((ret = PacketReceiver::appendSize(manager.getInput(), size, sizeContent)) == NULL)
				return (PacketReceiver::onError(ret));
		}
	}
	delete [] ret;
	ret = manager.getInput().retrieve(size);
	packet.unpack(reinterpret_cast<const unsigned char *>(ret));
	processer.run(manager, packet);
	delete [] ret;
	return (true);
}

bool PacketReceiver::onError(const char *ret)
{
	if (ret != NULL)
		delete [] ret;
	return (false);
}

const char *PacketReceiver::appendSize(RingBuffer &buffer, uint64_t &actualSize, uint32_t length)
{
	const char *ret;
	uint64_t expectedSize;

	expectedSize = actualSize + length;
	actualSize += length;
	ret = buffer.retrieve(actualSize, false);
	if (actualSize != expectedSize)
	{
		delete [] ret;
		return (NULL);
	}
	return (ret);
}