#pragma once

#include <stack>
#include "game/system/ASystem.hpp"
#include "game/component/Position.hpp"
#include "game/component/RigidBody.hpp"
#include "game/component/Direction.hpp"

typedef struct {
  bool      colX;
  bool      colY;
  Vector2f  pos;
}       viewportCollision;

class CollisionSystem : public ASystem {
public:
    CollisionSystem(World &);

    typedef struct {
        Entity  *e1;
        Entity  *e2;
        viewportCollision *viewport;
    }   collision;
    

    virtual void		updateEntity(Entity* entity, float elapsed_time);
    void                updateAllEntities(float elapsed_time);

private:
    bool                checkCollision(Entity *a, Entity *b);
    viewportCollision   *checkViewPort(Entity *a);
    void                resolveCollisions(void);
    void                resolveCollision(collision *);
private:
    std::stack<collision*>  collisions;
};