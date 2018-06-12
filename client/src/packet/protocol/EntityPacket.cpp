//
// EntityPacket.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "packet/protocol/EntityPacket.hpp"
#include "packet/PacketSerializer.hpp"
#include "packet/PacketSender.hpp"
#include "core/GameCore.hpp"
#include "tools/Chrono.hpp"
#include "Printer.hpp"

EntityPacket::EntityPacket()
{

}

EntityPacket::~EntityPacket()
{

}

void EntityPacket::updatePlayer(std::map<uint64_t, MovableEntity *> *entities, PacketDeserializer &packet)
{
	MovableEntity *entity;
	uint64_t id;
	uint16_t sprite;
	float velocity;
	Vector2f position;
	Vector2f direction;

	packet >> id;
	packet >> sprite;
	packet >> velocity;
	packet >> position;
	packet >> direction;
	//std::cout << "Id: " << id << " - Velocity: " << velocity << " - Sprite: " << sprite << " - Pos: " << position << " - Dir: " << direction << std::endl;
	if (entities->find(id) != entities->end())
		entity = (*entities)[id];
	else
	{
		entity = new MovableEntity();
		(*entities)[id] = entity;
	}
	(*entities)[id]->setSprite(sprite);
	(*entities)[id]->setVelocity(velocity);
	(*entities)[id]->setPosition(position);
	(*entities)[id]->setDir(direction);
	(*entities)[id]->setLastUpdate(Chrono::getCurrentTime());
}

bool EntityPacket::process(IManager &manager, PacketDeserializer &packet)
{
	std::map<uint64_t, MovableEntity *> *entities;
	uint64_t offset;
	uint16_t i;
	uint16_t playersSize;

	packet >> offset;
	GameCore::getInstance().setMapOffset(offset);
	packet >> playersSize;
	entities = GameCore::getInstance().getEntities();
	//std::cout << "Player size: " << playersSize << std::endl;
	i = 0;
	while (i < playersSize)
	{
		this->updatePlayer(entities, packet);
		i++;
	}
	GameCore::getInstance().setEntities(entities);
	delete entities;
	return (true);
}