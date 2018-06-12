#pragma once

#include "game/system/ASystem.hpp"

class MovementSystem : public ASystem {
public:
    MovementSystem(World &);

    virtual void		updateEntity(Entity* entity, float elapsed_time);
};