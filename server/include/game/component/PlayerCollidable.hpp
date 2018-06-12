#pragma once

#include    "game/component/ACollidable.hpp"
#include "game/component/Removable.hpp"

namespace Component
{
    class PlayerCollidable : public ACollidable
    {
    public:
        PlayerCollidable(Entity &);
        void    collideWith(Entity *, viewportCollision *);
    };
}