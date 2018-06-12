#include  "game/component/Fire.hpp"

namespace Component {
  Fire::Fire()
  {
    this->firing = false;
    this->cooldown = std::chrono::steady_clock::now();
  }

  Fire::~Fire()
  {
    
  }

  Type    Fire::getType() const
  {
    return (Type::FIRING);
  }

}
