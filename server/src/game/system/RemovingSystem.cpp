#include "game/system/RemovingSystem.hpp"

RemovingSystem::RemovingSystem(World &world) : ASystem(world){
    _requirements = Component::Type::REMOVABLE;
}

void RemovingSystem::updateEntity(Entity *entity, float elapsed_time) {
  (void) elapsed_time;

  if (((Component::Removable*)entity->getComponent(Component::Type::REMOVABLE))->val)
    _world.destroyEntity(entity);
}