#include	"game/component/Position.hpp"

namespace Component {
	Position::Position()
	{

	}

  	Position::Position(const Vector2f &pos)
	{
		this->val = pos;
	}

	Position::~Position()
	{

	}

	Type	Position::getType() const
	{
		return (Type::POSITION);
	}

	std::string Position::toString(void) const
	{
		std::stringstream ss;

		ss << "Position { value: " << this->val << " }";
		return (ss.str());
	}

	void Position::serialize(PacketSerializer& packetSerializer)
	{
		packetSerializer << static_cast<uint32_t>(this->getType());
		packetSerializer << this->val;
	}
}

std::ostream &operator<<(std::ostream& os, Component::Position const& position)
{
  os << position.toString();
  return (os);
}
