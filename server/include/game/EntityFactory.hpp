#pragma once

#include	"game/Entity.hpp"
#include    "game/map/MapEntity.hpp"
#include	"IMob.hpp"
#include  "tools/Random.hpp"

class World;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	Entity*	createPlayer(World& world);
	Entity*	createProjectile(World& world, Entity* entity);
	Entity*	createEnemyProjectile(World& world, Entity* entity);
  Entity* createStaticMesh(World &, const MapEntity *, std::uint32_t);
	Entity*	createMob(World&, IMob*);

private:
	Entity*	create(World& world);
	uint64_t	_id_count;
	uint16_t  _sprite_id;
};
