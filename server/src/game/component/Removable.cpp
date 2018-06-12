#include	"game/component/Removable.hpp"

namespace Component {
    Removable::Removable()
    {
        this->val = false;
    }

    Removable::~Removable()
    {

    }

    Removable::Removable(bool val) {
        this->val = val;
    }

    Type	Removable::getType() const
    {
        return (Type::REMOVABLE);
    }

    std::string Removable::toString(void) const
    {
        std::stringstream ss;

        ss << "Removable { value: " << (this->val == true ? "true" : "false") << " }";
        return (ss.str());
    }

    void Removable::serialize(PacketSerializer&)
    {
        /**
         * packetSerializer << static_cast<uint32_t>(this->getType());
         * packetSerializer << this->val;
         */
    }
}

std::ostream& operator<<(std::ostream &os, Component::Removable const& rmv)
{
  os << rmv.toString();
  return (os);
}