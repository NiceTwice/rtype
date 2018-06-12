#pragma once

#include "game/component/ACollidable.hpp"
#include "game/component/Damage.hpp"
#include "game/component/Removable.hpp"
#include "game/component/Health.hpp"

namespace Component
{
    class PlayerProjectileCollidable : public ACollidable
    {
    public:
        PlayerProjectileCollidable(Entity &);
        void    collideWith(Entity *, viewportCollision *);
    };
}