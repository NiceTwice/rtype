#include	"game/component/Direction.hpp"

namespace Component {
    Direction::Direction()
    {
        this->val.setX(0);
        this->val.setY(0);
    }

    Direction::~Direction()
    {

    }

    Direction::Direction(Vector2f const &vec) {
        this->val = vec;
    }

    Type	Direction::getType() const
    {
        return (Type::DIRECTION);
    }

    std::string Direction::toString(void) const
    {
        std::stringstream ss;

        ss << "Direction { value: " << this->val << " }";
        return (ss.str());
    }

    void Direction::serialize(PacketSerializer& packetSerializer)
    {
      packetSerializer << static_cast<uint32_t>(this->getType());
      packetSerializer << this->val;
    }
}

std::ostream& operator<<(std::ostream &os, Component::Direction const& direction)
{
  os << direction.toString();
  return (os);
}