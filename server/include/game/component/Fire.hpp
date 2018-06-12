#pragma once

#include  <chrono>
#include  <atomic>
#include	"game/component/IComponent.hpp"

namespace Component {

	class Fire : public IComponent
	{
	public:
		Fire();
		~Fire();

		Type	getType() const;

	public:
		std::atomic<bool>    firing;
    std::chrono::steady_clock::time_point	cooldown;
	};
}
