#pragma once

#include    "game/component/ACollidable.hpp"

namespace Component
{
    class EnemyProjectileCollidable : public ACollidable
    {
    public:
        EnemyProjectileCollidable(Entity &);
        void    collideWith(Entity *, viewportCollision *);
    };
}