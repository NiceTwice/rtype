#include	"game/component/Velocity.hpp"

namespace Component {
    Velocity::Velocity()
    {
        this->val = 0.2;
    }

    Velocity::~Velocity()
    {

    }

    Velocity::Velocity(float val) {
        this->val = val;
    }

    Type	Velocity::getType() const
    {
        return (Type::VELOCITY);
    }

    std::string Velocity::toString(void) const
    {
        std::stringstream ss;

        ss << "Velocity { value: " << this->val << " }";
        return (ss.str());
    }

    void Velocity::serialize(PacketSerializer& packetSerializer)
    {
        packetSerializer << static_cast<uint32_t>(this->getType());
        packetSerializer << this->val;
    }
}

std::ostream& operator<<(std::ostream &os, Component::Velocity const& velocity)
{
  os << velocity.toString();
  return (os);
}