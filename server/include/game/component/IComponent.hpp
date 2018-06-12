#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include "packet/PacketSerializer.hpp"
# include "game/component/ComponentType.hpp"

namespace Component {

	class IComponent
	{
	public:
		virtual ~IComponent() {}


		virtual	Type	getType() const = 0;
		
	private:

	};

}
