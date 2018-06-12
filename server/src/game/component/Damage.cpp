#include	"game/component/Damage.hpp"

namespace Component {
    Damage::Damage()
    {
        this->val = 0;
    }

    Damage::~Damage()
    {

    }

    Damage::Damage(int32_t val) {
        this->val = val;
    }

    Type Damage::getType() const
    {
        return (Type::DAMAGE);
    }

    std::string Damage::toString(void) const
    {
        std::stringstream ss;

        ss << "Damage { value: " << this->val << " }";
        return (ss.str());
    }

    void Damage::serialize(PacketSerializer&)
    {
      /**
       * packetSerializer << static_cast<uint32_t>(this->getType());
       * packetSerializer << this->val;
       */
    }
}

std::ostream& operator<<(std::ostream &os, Component::Damage const& dmg)
{
  os << dmg.toString();
  return (os);
}