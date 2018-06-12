#pragma once

#include	"game/component/IComponent.hpp"

namespace Component
{
    class AIComponent : public IComponent
    {
    public:
        AIComponent();
        AIComponent(float fireSpeed);
        ~AIComponent();

        Type		getType() const;

    public:
        float 		    fireSpeed;
        float           currentCd;
    };
}