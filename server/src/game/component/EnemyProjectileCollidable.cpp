#include <game/component/Damage.hpp>
#include "game/component/Removable.hpp"
#include "game/component/Health.hpp"
#include	"game/component/EnemyProjectileCollidable.hpp"

namespace Component {

    EnemyProjectileCollidable::EnemyProjectileCollidable(Entity &ent): ACollidable(ent) {

    }

    void EnemyProjectileCollidable::collideWith(Entity *ent, viewportCollision *viewport) {
        (void)viewport;
        switch (static_cast<uint32_t>(ent->getType())) {
            case static_cast<uint32_t>(Entity::DECORATIVE):
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
            case static_cast<uint32_t>(Entity::PLAYER):
                ((Component::Health*)ent->getComponent(Component::Type::HEALTH))->changeAmount += ((Component::Damage*)_parent.getComponent(Component::Type::DAMAGE))->val * -1;
                break;
        }
    }
}
