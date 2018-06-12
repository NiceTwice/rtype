#pragma once

#include "game/component/ACollidable.hpp"
#include "game/component/Removable.hpp"

namespace Component
{
    class EnemyCollidable : public ACollidable
    {
    public:
        EnemyCollidable(Entity &);
        void    collideWith(Entity *, viewportCollision *);
    };
}