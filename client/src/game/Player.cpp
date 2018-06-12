//
// Player.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/core
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "game/Player.hpp"

Player::Player()
{

}

Player::~Player()
{

}

void Player::setId(uint32_t value)
{
	this->_mutex.lock();
	this->_id = value;
	this->_mutex.unlock();
}

uint32_t Player::getId()
{
	this->_mutex.lock();
	uint32_t value(this->_id);
	this->_mutex.unlock();
	return (value);
}