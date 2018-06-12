#include	"game/component/Sprite.hpp"

namespace Component
{
	Sprite::Sprite(uint16_t id)
	{
		this->id = id;
	}

	Sprite::~Sprite()
	{

	}

	Type		Sprite::getType() const
	{
		return (Type::SPRITE);
	}
}