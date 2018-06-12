#include  "game/system/ASystem.hpp"
#include  "game/system/SystemManager.hpp"
#include  "game/system/MovementSystem.hpp"
#include  "game/system/CollisionSystem.hpp"
#include  "game/system/HealthSystem.hpp"
#include  "game/system/RemovingSystem.hpp"
#include  "game/system/FireSystem.hpp"
#include  "game/World.hpp"

SystemManager::SystemManager(World &world) : _world(world)
{
  this->_systems.push_back(new MovementSystem(_world));
  this->_systems.push_back(new CollisionSystem(_world));
  this->_systems.push_back(new HealthSystem(_world));
  this->_systems.push_back(new RemovingSystem(_world));
  this->_systems.push_back(new FireSystem(_world));
}

SystemManager::~SystemManager()
{
  
}

void        SystemManager::registerEntity(Entity *entity)
{
  for(auto& system : this->_systems)
    system->registerEntity(entity);
}

void        SystemManager::unregisterEntity(Entity *entity)
{
  for (auto& system : this->_systems)
		system->unregisterEntity(entity);  
}

void        SystemManager::update(double elapsed_time)
{
  for (auto& system : this->_systems)
    system->updateAllEntities(elapsed_time);
}