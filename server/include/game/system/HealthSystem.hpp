#pragma once

#include "game/system/ASystem.hpp"
#include "game/component/Health.hpp"

class HealthSystem : public ASystem {
public:
    HealthSystem(World &);

    virtual void		updateEntity(Entity* entity, float elapsed_time);
};