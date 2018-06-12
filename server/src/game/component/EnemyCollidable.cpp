#include	"game/component/EnemyCollidable.hpp"
#include  "game/component/Position.hpp"

namespace Component {

    EnemyCollidable::EnemyCollidable(Entity &ent): ACollidable(ent) {

    }

    void EnemyCollidable::collideWith(Entity *ent, viewportCollision *viewport) {

      if (ent == NULL && viewport != NULL)
      {
        if (viewport->colX && viewport->pos.getX() == 0)
          ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
        return;
      }
        switch (static_cast<uint32_t>(ent->getType())) {
            case static_cast<uint32_t>(Entity::DECORATIVE):
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
        }
    }
}
