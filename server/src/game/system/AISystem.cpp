#include "game/system/AISystem.hpp"

AISystem::AISystem(World &world) : ASystem(world){
    _requirements = Component::Type::AICOMPONENT;
}

void AISystem::updateEntity(Entity *entity, float elapsed_time) {
    Component::AIComponent *ai = (Component::AIComponent *)entity->getComponent(Component::Type::AICOMPONENT);

    ai->currentCd -= elapsed_time;
    if (ai->currentCd <= 0){
        _world.getFactory().createEnemyProjectile(_world, entity);
        ai->currentCd = ai->fireSpeed;
    }
}