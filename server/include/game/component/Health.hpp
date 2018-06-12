#pragma once

#include	"game/component/IComponent.hpp"

namespace Component
{
	class Health : public IComponent
	{
	public:
		Health();
		Health(int32_t health);
		~Health();

		Type		getType() const;
		std::string	toString(void) const;

		void serialize(PacketSerializer&);

	public:
		int32_t			val;
		int32_t 		changeAmount;
	};
}

std::ostream& operator<<(std::ostream&, Component::Health const&);