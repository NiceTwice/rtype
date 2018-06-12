#include <sstream>
#include "game/Entity.hpp"
#include "game/World.hpp"
#include "game/component/Direction.hpp"
#include "game/component/Fire.hpp"


Entity::Entity(uint32_t id, World& world) : _uniqueID(id), _world(world)
{
}

Entity::~Entity()
{
	while (this->_componentList.size() > 0) {
		delete (*(this->_componentList.begin()));
		this->_componentList.erase(this->_componentList.begin());
	}
}

void		Entity::addComponent(Component::IComponent* component)
{
	this->_componentSet |= component->getType();
	this->_componentList.push_back(component);
}

Vector2f*	Entity::getDirection()
{
	return (&((Component::Direction *)this->getComponent(Component::Type::DIRECTION))->val);
}

void 		Entity::setFiring(bool value)
{
	if (((Component::Fire *)this->getComponent(Component::Type::FIRING)) != NULL)
		((Component::Fire *)this->getComponent(Component::Type::FIRING))->firing = value;
}

Component::IComponent*	Entity::getComponent(Component::Type type)
{
	for (auto& component : this->_componentList)
	{
		if (component->getType() == type)
			return (component);
	}
	return (NULL);
}

std::vector<Component::IComponent *> const& Entity::getComponents(void) const
{
  return (this->_componentList);
}

std::bitset<32> const&	Entity::getComponentSet() const
{
	return (this->_componentSet);
}

void		Entity::removeComponent(Component::Type type)
{
	for (auto it = this->_componentList.begin();
		it != this->_componentList.end();
		it++)
	{
		if ((*it)->getType() == type)
		{
			delete (*it);
			this->_componentList.erase(it);
			return;
		}
	}
}

bool		Entity::hasComponent(Component::Type type) const
{
	if ((this->_componentSet & std::bitset<32>(type)) == type)
		return true;
	else
		return false;
}

void		Entity::setType(Entity::Type type)
{
	this->_type = type;
}

uint32_t const&	Entity::getID() const
{
	return (this->_uniqueID);
}

Entity::Type	Entity::getType() const
{
	return (this->_type);
}

World&	Entity::getWorld()
{
  return (this->_world);
}

std::string Entity::toString(void) const
{
  std::stringstream ss;
  std::vector<Component::IComponent *>::const_iterator it;
  std::string types[5] = {"Player", "Monster", "Decorative", "Player projectile", "Ennemy projectile"};

  ss << "Entity { UID: " << this->_uniqueID << ", type: " << types[this->_type];
  ss << ", componentSet: " << this->_componentSet << ", [ ";
  for (it = this->_componentList.begin(); it != this->_componentList.end(); ++it) {
    ss << *it;
    if (++it != this->_componentList.end())
      ss << ", ";
    --it;
  }
  ss << " ] }";
  return (ss.str());
}

std::ostream& operator<<(std::ostream &os, Entity const& entity)
{
  os << entity.toString();
  return (os);
}