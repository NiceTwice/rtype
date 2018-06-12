#pragma once

#include	"game/component/IComponent.hpp"

namespace Component
{
    class Removable : public IComponent
    {
    public:
        Removable();
        Removable(bool);
        ~Removable();

        Type		getType() const;
        std::string toString(void) const;

        void serialize(PacketSerializer&);

    public:
        bool		val;
    };
}

std::ostream &operator<<(std::ostream&, Component::Removable const&);