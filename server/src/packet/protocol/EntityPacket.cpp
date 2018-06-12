//
// EntityPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "packet/protocol/EntityPacket.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"

EntityPacket::EntityPacket()
{

}

EntityPacket::~EntityPacket()
{

}

bool EntityPacket::process(const NetworkCommunicationType type, Converter *client, PacketDeserializer &packet)
{
	if (client->getPlayer().getEntity() != nullptr) {
		bool isFiring;
		Vector2f direction;
		Vector2f *playerDirection;

		(void)type;
		packet >> isFiring;
		packet >> direction;
		if ((playerDirection = client->getPlayer().getEntity()->getDirection()) != NULL)
		{
			playerDirection->setX(direction.getX());
			playerDirection->setY(direction.getY());
		}
		client->getPlayer().getEntity()->setFiring(isFiring);
	}
	return (true);
}