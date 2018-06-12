#pragma once

#include "game/system/ASystem.hpp"
#include "game/component/Fire.hpp"

class FireSystem : public ASystem {
public:
    FireSystem(World &);

    virtual void		updateEntity(Entity* entity, float elapsed_time);
};