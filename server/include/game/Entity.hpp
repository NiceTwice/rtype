#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <atomic>
#include "game/component/IComponent.hpp"

class World;

class Entity
{
public:
  Entity(uint32_t id, World& world);
  ~Entity();

  typedef enum Type: uint32_t
  {
    PLAYER = 0,
    MONSTER = 1,
    DECORATIVE = 2,
    PLAYER_PROJECTILE = 3,
    ENNEMY_PROJECTILE = 4
  } Type;

  void addComponent(Component::IComponent* component);
  void removeComponent(Component::Type type);
  Component::IComponent *getComponent(Component::Type type);
  std::vector<Component::IComponent *> const& getComponents(void) const;

  bool hasComponent(Component::Type type) const;
  std::bitset<32> const& getComponentSet() const;

  void setType(Entity::Type type);
	World&	getWorld();

  uint32_t const& getID() const;
  Entity::Type getType() const;

  std::string toString(void) const;

  Vector2f*   getDirection();
  void   setFiring(bool value);

  bool isReady() const;
  void setReady(bool);

private:
  const uint32_t _uniqueID;
  Type _type;
	World&		_world;

  std::bitset<32> _componentSet;
  std::vector<Component::IComponent *> _componentList;
};

std::ostream& operator<<(std::ostream&, Entity const&);