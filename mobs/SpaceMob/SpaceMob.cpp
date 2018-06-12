#include "SpaceMob.hpp"
#include "game/component/Position.hpp"
#include "game/component/Health.hpp"
#include "game/component/Sprite.hpp"
#include "game/component/Direction.hpp"
#include "game/component/Velocity.hpp"
#include "game/component/RigidBody.hpp"
#include "game/component/Removable.hpp"
#include "game/component/Damage.hpp"
#include "game/component/EnemyCollidable.hpp"

SpaceMob::SpaceMob()
{
  srand(time(nullptr));
  this->m_builders.push_back(&SpaceMob::createHorizontalEntity);
  this->m_builders.push_back(&SpaceMob::createDiagonalEntity);
}

SpaceMob::~SpaceMob()
{
}

void SpaceMob::createHorizontalEntity(Entity *instance) const
{
  instance->setType(Entity::MONSTER);
  instance->addComponent(new Component::Sprite(5));
  instance->addComponent(new Component::Health());
  instance->addComponent(new Component::Direction(Vector2f(-1.f, 0.f)));
  instance->addComponent(new Component::Velocity(0.2));
  instance->addComponent(new Component::RigidBody(21.0f, 24.0f));
  instance->addComponent(new Component::EnemyCollidable(*instance));
  instance->addComponent(new Component::Removable());
  instance->addComponent(new Component::Damage(50));
}

void SpaceMob::createDiagonalEntity(Entity *instance) const
{
  instance->setType(Entity::MONSTER);
  instance->addComponent(new Component::Sprite(5));
  instance->addComponent(new Component::Health());
  instance->addComponent(new Component::Direction(Vector2f(-1.f,
    (rand() % 2 == 1 ? -(static_cast<float>((rand() % 300) + 100.f) / 1000.f) :
    (static_cast<float>((rand() % 300) + 100.f) / 1000.f)))));
  instance->addComponent(new Component::Velocity(0.2));
  instance->addComponent(new Component::RigidBody(21.0f, 24.0f));
  instance->addComponent(new Component::EnemyCollidable(*instance));
  instance->addComponent(new Component::Removable());
  instance->addComponent(new Component::Damage(50));
}

void   SpaceMob::createEntity(Entity* instance)
{
  (this->*this->m_builders[rand() % this->m_builders.size()])(instance);
}

std::string const  SpaceMob::getType() const
{
  return ("Space");
}

extern "C" {
  IMob  *make()
  {
    return (new SpaceMob());
  }
}