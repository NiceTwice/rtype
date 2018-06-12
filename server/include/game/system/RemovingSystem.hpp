#pragma once

#include "game/system/ASystem.hpp"
#include "game/component/Removable.hpp"

class RemovingSystem : public ASystem {
public:
    RemovingSystem(World &);

    virtual void		updateEntity(Entity* entity, float elapsed_time);
};