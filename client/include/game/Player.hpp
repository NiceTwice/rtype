//
// Player.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/core
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "game/AEntity.hpp"

class Player : public AEntity
{
public:
	Player();
	~Player();

public:
	void setId(uint32_t);
	uint32_t getId();

private:
	uint32_t _id;
};