#include "game/system/FireSystem.hpp"

FireSystem::FireSystem(World &world) : ASystem(world){
    _requirements = Component::Type::FIRING;
}

void FireSystem::updateEntity(Entity *entity, float elapsed_time) {
  Component::Fire *firing = (Component::Fire*)entity->getComponent(Component::Type::FIRING);
  std::chrono::steady_clock::time_point	now = std::chrono::steady_clock::now();

  (void) elapsed_time;
  if (firing && firing->firing == true)
  {
    double cd_val = std::chrono::duration_cast<std::chrono::milliseconds>(now - firing->cooldown).count();
    if (cd_val > 333)
    {
      this->_world.getFactory().createProjectile(this->_world, entity);
      firing->cooldown = now;      
    }
  }
}