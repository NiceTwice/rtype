//
// EndPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/EndPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "core/GameCore.hpp"
#include "Printer.hpp"

EndPacket::EndPacket()
{

}

EndPacket::~EndPacket()
{

}

bool EndPacket::process(IManager &, PacketDeserializer &packet)
{
	bool end;

	Printer::info("EndPacket received");
	packet >> end;
	GameCore::getInstance().setEnd((end) ? 1 : 2);
	return (true);
}