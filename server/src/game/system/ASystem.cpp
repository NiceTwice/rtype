#include	<algorithm>
#include	"game/system/ASystem.hpp"
#include	"game/World.hpp"

ASystem::ASystem(World& world) : _world(world)
{

}

ASystem::~ASystem()
{

}

void	ASystem::registerEntity(Entity* entity)
{
	if ((this->_requirements & entity->getComponentSet()) == this->_requirements)
  {
    this->_entites.push_back(entity);
  }
}

void	ASystem::unregisterEntity(Entity* entity)
{
	auto item = std::find(this->_entites.begin(), this->_entites.end(), entity);

	if (item != this->_entites.end())
		this->_entites.erase(item);
}

void	ASystem::updateAllEntities(float elapsed_time)
{
	for (auto &entity : this->_entites)
		this->updateEntity(entity, elapsed_time);
}