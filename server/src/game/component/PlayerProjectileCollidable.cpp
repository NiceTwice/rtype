#include	"game/component/PlayerProjectileCollidable.hpp"

namespace Component {

    PlayerProjectileCollidable::PlayerProjectileCollidable(Entity &ent): ACollidable(ent) {

    }

    void PlayerProjectileCollidable::collideWith(Entity *ent, viewportCollision *viewport) {
      if (ent == NULL && viewport != NULL)
      {
        ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
        return;
      }
        switch (static_cast<uint32_t>(ent->getType())) {
            case static_cast<uint32_t>(Entity::DECORATIVE):
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
            case static_cast<uint32_t>(Entity::MONSTER):
                ((Component::Health*)ent->getComponent(Component::Type::HEALTH))->changeAmount += ((Component::Damage*)_parent.getComponent(Component::Type::DAMAGE))->val * -1;
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
        }
    }
}
