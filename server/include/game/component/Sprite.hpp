#pragma once

#include  "game/component/IComponent.hpp"

namespace Component
{
	class Sprite : public IComponent
	{
	public:
		Sprite(uint16_t id);
		~Sprite();
    
		Type		getType() const;
		
	public:
		uint16_t  id;
	};
}  