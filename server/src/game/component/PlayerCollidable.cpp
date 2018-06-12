#include	"game/component/PlayerCollidable.hpp"
#include  "game/component/Position.hpp"

namespace Component {

    PlayerCollidable::PlayerCollidable(Entity &ent): ACollidable(ent) {

    }

    void PlayerCollidable::collideWith(Entity *ent, viewportCollision *viewport) {

      if (ent == NULL && viewport != NULL)
      {
        Vector2f& pos = ((Component::Position*)_parent.getComponent(Component::Type::POSITION))->val;
        Vector2f& prev = ((Component::Position*)_parent.getComponent(Component::Type::POSITION))->prev;

        (void)prev;
        if (viewport->colX)
          pos.setX(viewport->pos.getX());
        if (viewport->colY)
          pos.setY(viewport->pos.getY());
        return;
      }
        switch (static_cast<uint32_t>(ent->getType())) {
            case static_cast<uint32_t>(Entity::DECORATIVE):
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
            case static_cast<uint32_t>(Entity::MONSTER):
                ((Component::Removable*)_parent.getComponent(Component::Type::REMOVABLE))->val = true;
                break;
        }
    }
}
