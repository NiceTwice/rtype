#pragma once

#include    "game/Entity.hpp"
#include    "game/system/CollisionSystem.hpp"

namespace Component
{
    class ACollidable : public IComponent
    {
    public:
        ACollidable(Entity &);

        Type		    getType() const;
        std::string toString(void) const;
        virtual void    collideWith(Entity *, viewportCollision *) = 0;
        void serialize(PacketSerializer&);
    protected:
        Entity    &_parent;
    };
}

std::ostream &operator<<(std::ostream&, Component::ACollidable const&);