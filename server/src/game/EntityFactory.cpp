#include <game/component/RigidBody.hpp>
#include <game/component/EnemyProjectileCollidable.hpp>
#include    "game/map/MapEntity.hpp"
#include	"game/EntityFactory.hpp"
#include	"game/component/Position.hpp"
#include	"game/component/Health.hpp"
#include	"game/component/Direction.hpp"
#include	"game/component/Velocity.hpp"
#include	"game/component/Damage.hpp"
#include	"game/component/Sprite.hpp"
#include	"game/component/RigidBody.hpp"
#include	"game/component/PlayerCollidable.hpp"
#include	"game/component/PlayerProjectileCollidable.hpp"
#include	"game/component/Removable.hpp"
#include	"game/component/Fire.hpp"
#include  "game/World.hpp"

EntityFactory::EntityFactory()
{
  this->_id_count = 0;
  this->_sprite_id = 0;
}

EntityFactory::~EntityFactory()
{

}

Entity*		EntityFactory::create(World &world)
{
	Entity*	instance = new Entity(this->_id_count, world);

	this->_id_count++;
	return (instance);
}

Entity*     EntityFactory::createStaticMesh(World &world, const MapEntity *mesh, std::uint32_t offset)
{
  Entity    *instance = this->create(world);

  instance->addComponent(new Component::Position(Vector2f(mesh->getPosition().getX() + offset, mesh->getPosition().getY())));
  instance->addComponent(new Component::RigidBody(mesh->getSize()));
  instance->setType(Entity::DECORATIVE);
  world.addEntity(instance);
  return (instance);
}

Entity*		EntityFactory::createPlayer(World& world)
{
	Entity*	instance = this->create(world);

  instance->addComponent(new Component::Sprite(world.getNextSpriteId()));
	instance->addComponent(new Component::Health());
	instance->addComponent(new Component::Position(Vector2f(0.f, (world.getMap()->getViewport().getY() / 2.f) - 1.f)));
  instance->addComponent(new Component::Fire());
	instance->addComponent(new Component::Direction(Vector2f(0.f, 0.f)));
	instance->addComponent(new Component::Velocity());
  instance->addComponent(new Component::RigidBody(33.0f, 17.0f));
  instance->addComponent(new Component::Removable());
	instance->addComponent(new Component::Damage(100));
	instance->setType(Entity::PLAYER);
  world.addEntity(instance);
	return (instance);
}

Entity*		EntityFactory::createProjectile(World& world, Entity* entity)
{
	Entity*	instance = this->create(world);
  Vector2f& position = ((Component::Position*)entity->getComponent(Component::Type::POSITION))->val;

	instance->addComponent(new Component::Position(position));
  instance->addComponent(new Component::Sprite(4));
	instance->addComponent(new Component::Direction(Vector2f(1.f, 0.f)));
	instance->addComponent(new Component::Velocity(0.3f));
  instance->addComponent(new Component::RigidBody(9.0f, 2.0f));
  instance->addComponent(new Component::Removable());
  instance->addComponent(new Component::PlayerProjectileCollidable(*instance));
  instance->addComponent(new Component::Damage(100));
	instance->setType(Entity::PLAYER_PROJECTILE);
  world.addEntity(instance);
	return (instance);
}

Entity *EntityFactory::createEnemyProjectile(World &world, Entity *entity) {
    Entity*	instance = this->create(world);
    Vector2f& position = ((Component::Position*)entity->getComponent(Component::Type::POSITION))->val;

    instance->addComponent(new Component::Position(position));
    instance->addComponent(new Component::Sprite(4));
    instance->addComponent(new Component::Direction(Vector2f(-1.f, 0.f)));
    instance->addComponent(new Component::Velocity(0.3f));
    instance->addComponent(new Component::RigidBody(9.0f, 2.0f));
    instance->addComponent(new Component::Removable());
    instance->addComponent(new Component::EnemyProjectileCollidable(*instance));
    instance->setType(Entity::ENNEMY_PROJECTILE);
    world.addEntity(instance);
    return (instance);
}

Entity* EntityFactory::createMob(World &world, IMob* mob)
{
  Entity*	instance = this->create(world);
  float   posY;
  float   height;

  mob->createEntity(instance);
  height = ((Component::RigidBody *)(instance->getComponent(Component::Type::RIGIDBODY)))->height;
  posY = (float)(Random::getNextInteger(0, world.getMap()->getViewport().getY() - height + 1));
  instance->addComponent(new Component::Position(Vector2f(500.0f, posY)));
  world.addEntity(instance);
  return (instance);
}
