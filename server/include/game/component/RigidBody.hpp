#pragma once

#include <game/Vector2f.hpp>
#include	"game/component/IComponent.hpp"

namespace Component
{
    class RigidBody : public IComponent
    {
    public:
        RigidBody(float width, float height);
        RigidBody(const Vector2f &);
        ~RigidBody();

        Type		getType() const;
        std::string toString(void) const;

        void serialize(PacketSerializer&);

    public:
        float			width;
        float     height;
    };
}

std::ostream &operator<<(std::ostream&, Component::RigidBody const&);