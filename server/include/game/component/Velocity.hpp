#pragma once

#include	"game/component/IComponent.hpp"

namespace Component
{
    class Velocity : public IComponent
    {
    public:
        Velocity();
        Velocity(float val);
        ~Velocity();

        Type		getType() const;
        std::string toString(void) const;

        void serialize(PacketSerializer&);

    public:
        float			val;
    };
}

std::ostream& operator<<(std::ostream&, Component::Velocity const&);