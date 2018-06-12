#pragma once

#include	"game/component/IComponent.hpp"
#include	"game/Vector2f.hpp"

namespace Component {

	class Position : public IComponent
	{
	public:
		Position();
	    Position(const Vector2f &);
		~Position();

		Type	getType() const;
		std::string toString(void) const;

		void serialize(PacketSerializer&);

	public:
		Vector2f	val;
		Vector2f	prev;
	};
}

std::ostream &operator<<(std::ostream&, Component::Position const&);