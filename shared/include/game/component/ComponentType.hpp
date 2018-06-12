//
// ComponentType.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/core
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

namespace Component {

	typedef enum Type : uint32_t
	{
		NONE = 0,
		POSITION = 1 << 0,
		VELOCITY = 1 << 1,
		HEALTH = 1 << 2,
		DIRECTION = 1 << 3,
		RIGIDBODY = 1 << 4,
		DAMAGE = 1 << 5,
		REMOVABLE = 1 << 6,
		COLLIDABLE = 1 << 7,
		SPRITE = 1 << 8,
		FIRING = 1 << 9,
		AICOMPONENT = 1 << 10
	} 	Type;

}