#pragma once

#include "game/system/ASystem.hpp"
#include "game/component/AIComponent.hpp"

class AISystem : public ASystem {
public:
    AISystem(World &);

    virtual void		updateEntity(Entity* entity, float elapsed_time);
};