//
// AEntity.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/core
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "game/Vector2f.hpp"
#include "thread/StdMutex.hpp"

class AEntity
{
public:
	AEntity() {}
	virtual ~AEntity() {};

public:
	void setPos(const Vector2f &);
	const Vector2f getPos();
	void setVelocity(float);
	float getVelocity();
	void setHealth(uint32_t);
	uint32_t getHealth();
	void setDir(const Vector2f &);
	const Vector2f getDir();

protected:
	StdMutex _mutex;
	Vector2f _pos;
	float _velocity;
	uint32_t _health;
	Vector2f _dir;
};