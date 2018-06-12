#include "game/component/AIComponent.hpp"

namespace Component
{
    AIComponent::AIComponent()
    {
        this->fireSpeed = 2000;
        this->currentCd = 0;
    }

    AIComponent::AIComponent(float fireSpeed) {
        this->fireSpeed = fireSpeed;
        this->currentCd = 0;
    }

    AIComponent::~AIComponent()
    {

    }

    Type		AIComponent::getType() const
    {
        return (Type::AICOMPONENT);
    }



}