#pragma once

#include	<vector>
#include	<bitset>
#include	"game/Entity.hpp"
#include 	"game/World.hpp"

class World;

class ASystem
{
public:
	ASystem(World& world);
	~ASystem();

	void				registerEntity(Entity* entity);
	void				unregisterEntity(Entity* entity);
	virtual void		updateEntity(Entity* entity, float elapsed_time) = 0;
	virtual void		updateAllEntities(float elapsed_time);

protected:
	std::vector<Entity*>	_entites;
	std::bitset<32>			_requirements;
	World&					_world;
};
