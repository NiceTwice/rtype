#include "MineMob.hpp"
#include "game/component/Position.hpp"
#include "game/component/Health.hpp"
#include "game/component/Sprite.hpp"
#include "game/component/Direction.hpp"
#include "game/component/Velocity.hpp"
#include "game/component/RigidBody.hpp"
#include "game/component/Removable.hpp"
#include "game/component/Damage.hpp"
#include "game/component/EnemyCollidable.hpp"

MineMob::MineMob()
{
  srand(time(nullptr));
  this->m_builders.push_back(&MineMob::createHorizontalEntity);
  this->m_builders.push_back(&MineMob::createDiagonalEntity);
}

MineMob::~MineMob()
{
}

void MineMob::createHorizontalEntity(Entity *instance) const
{
  instance->setType(Entity::MONSTER);
  instance->addComponent(new Component::Sprite(7));
  instance->addComponent(new Component::Health());
  instance->addComponent(new Component::Direction(Vector2f(-1.f, 0.f)));
  instance->addComponent(new Component::Velocity(0.1));
  instance->addComponent(new Component::RigidBody(31.0f, 23.0f));
  instance->addComponent(new Component::EnemyCollidable(*instance));
  instance->addComponent(new Component::Removable());
  instance->addComponent(new Component::Damage(50));
}

void MineMob::createDiagonalEntity(Entity *instance) const
{
  instance->setType(Entity::MONSTER);
  instance->addComponent(new Component::Sprite(7));
  instance->addComponent(new Component::Health());
  instance->addComponent(new Component::Direction(Vector2f(-1.f,
    (rand() % 2 == 1 ? -(static_cast<float>((rand() % 300) + 100.f) / 1000.f) :
    (static_cast<float>((rand() % 300) + 100.f) / 1000.f)))));
  instance->addComponent(new Component::Velocity(0.1));
  instance->addComponent(new Component::RigidBody(32.0f, 24.0f));
  instance->addComponent(new Component::EnemyCollidable(*instance));
  instance->addComponent(new Component::Removable());
  instance->addComponent(new Component::Damage(50));
}

void   MineMob::createEntity(Entity* instance)
{
  (this->*this->m_builders[rand() % this->m_builders.size()])(instance);
}

std::string const  MineMob::getType() const
{
  return ("Mine");
}

extern "C" {
  IMob  *make()
  {
    return (new MineMob());
  }
}
