//
// AEntity.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src/core
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "game/AEntity.hpp"

void AEntity::setPos(const Vector2f &value)
{
	this->_mutex.lock();
	this->_pos = value;
	this->_mutex.unlock();
}

const Vector2f AEntity::getPos()
{
	this->_mutex.lock();
	Vector2f value(this->_pos);
	this->_mutex.unlock();
	return (value);
}

void AEntity::setVelocity(float value)
{
	this->_mutex.lock();
	this->_velocity = value;
	this->_mutex.unlock();
}

float AEntity::getVelocity()
{
	this->_mutex.lock();
	float value(this->_velocity);
	this->_mutex.unlock();
	return (value);
}

void AEntity::setHealth(uint32_t value)
{
	this->_mutex.lock();
	this->_health = value;
	this->_mutex.unlock();
}

uint32_t AEntity::getHealth()
{
	this->_mutex.lock();
	uint32_t value(this->_health);
	this->_mutex.unlock();
	return (value);
}

void AEntity::setDir(const Vector2f &value)
{
	this->_mutex.lock();
	this->_dir = value;
	this->_mutex.unlock();
}

const Vector2f AEntity::getDir()
{
	this->_mutex.lock();
	Vector2f value(this->_dir);
	this->_mutex.unlock();
	return (value);
}