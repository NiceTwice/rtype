#include	"game/component/ACollidable.hpp"

namespace Component {
    ACollidable::ACollidable(Entity &ent) : _parent(ent)
    {
    }


    Type	ACollidable::getType() const
    {
        return (Type::COLLIDABLE);
    }

    std::string ACollidable::toString(void) const
    {
      std::stringstream ss;

      ss << "Collidable {}";
      return (ss.str());
    }

    void ACollidable::serialize(PacketSerializer&)
    {
    }
}

std::ostream &operator<<(std::ostream& os, Component::ACollidable const& ac)
{
  os << ac.toString();
  return (os);
}