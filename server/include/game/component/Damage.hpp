#pragma once

#include	"game/component/IComponent.hpp"

namespace Component
{
  class Damage : public IComponent
  {
  public:
    Damage();
    Damage(int32_t val);
    ~Damage();

    Type getType() const;
    std::string toString(void) const;

    void serialize(PacketSerializer&);

  public:
    int32_t val;
  };
}

std::ostream &operator<<(std::ostream&, Component::Damage const&);