#pragma once

#include	"game/component/IComponent.hpp"
#include	"game/Vector2f.hpp"

namespace Component {

    class Direction : public IComponent
    {
    public:
        Direction();
        Direction(Vector2f const &vec);
        ~Direction();

        Type	getType() const;
        std::string toString(void) const;

        void serialize(PacketSerializer&);

    public:
        Vector2f	val;
    };
}

std::ostream &operator<<(std::ostream&, Component::Direction const&);