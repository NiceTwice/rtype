#include "game/system/HealthSystem.hpp"
#include  "game/component/Removable.hpp"

HealthSystem::HealthSystem(World &world) : ASystem(world){
    _requirements = Component::Type::HEALTH;
}

void HealthSystem::updateEntity(Entity *entity, float elapsed_time) {
  Component::Health *health = (Component::Health*)entity->getComponent(Component::Type::HEALTH);
  (void) elapsed_time;
  if (health->changeAmount != 0 && health->val > 0) {
    health->val += health->changeAmount;
    health->changeAmount = 0;
    if (health->val <= 0)
    {
      ((Component::Removable*)entity->getComponent(Component::Type::REMOVABLE))->val = true;
      health->val = 0;
    }
  }
}