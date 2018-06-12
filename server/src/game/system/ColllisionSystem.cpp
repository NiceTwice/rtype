#include <game/Vector2f.hpp>
#include <game/system/CollisionSystem.hpp>
#include <game/component/ACollidable.hpp>
#include "game/system/CollisionSystem.hpp"

CollisionSystem::CollisionSystem(World &world) : ASystem(world){
    _requirements = Component::Type::RIGIDBODY;
}

void CollisionSystem::updateEntity(Entity *entity, float elapsed_time) {
    (void) entity;
    (void) elapsed_time;
    return;
}

void CollisionSystem::updateAllEntities(float elapsed_time) {
    size_t  length = _entites.size();
    size_t  itr = 0;
    size_t  helperItr = 0;
    viewportCollision *viewport = NULL;

    (void) elapsed_time;
    while (itr < length){
        helperItr = itr + 1;
        Entity *a = _entites.at(itr);
        while (helperItr < length){
            Entity *b = _entites.at(helperItr);
            if (checkCollision(a, b)){
                collision *c = new collision;
                c->e1 = a;
                c->e2 = b;
                c->viewport = NULL;
                collisions.push(c);
            }
            helperItr++;
        }
        if (a->getType() != Entity::Type::DECORATIVE && ((viewport = checkViewPort(a)) != NULL)) {
          collision *c = new collision;
          c->e1 = a;
          c->e2 = NULL;
          c->viewport = viewport;
          collisions.push(c);
        }
        itr++;
    }
    resolveCollisions();
}

viewportCollision*  CollisionSystem::checkViewPort(Entity *e)
{
    viewportCollision *col = new viewportCollision;

    Vector2f  *pos = &((Component::Position*)e->getComponent(Component::Type::POSITION))->val;
    Component::RigidBody *body = (Component::RigidBody*)e->getComponent(Component::Type::RIGIDBODY);
    Vector2f const& viewport = e->getWorld().getMap()->getViewport();
    
    col->colX = false;
    col->colY = false;
    if (pos->getX() < 0)
    {
      col->colX = true;
      col->pos.setX(0);
    }
    if (pos->getY() < 0)
    {
      col->colY = true;
      col->pos.setY(0);
    }
    if ((pos->getX() + body->width) > viewport.getX())
    {
      col->colX = true;
      col->pos.setX(viewport.getX() - body->width);
    }
    if ((pos->getY() + body->height) > viewport.getY())
    {
      col->colY = true;
      col->pos.setY(viewport.getY() - body->height);
    }
    
    if (!col->colX && !col->colY)
    {
      delete col;
      return (NULL);
    }
    return (col);
}

bool CollisionSystem::checkCollision(Entity *a, Entity *b) {
    Vector2f                aPosition = ((Component::Position*)a->getComponent(Component::Type::POSITION))->val;
    Vector2f                bPosition = ((Component::Position*)b->getComponent(Component::Type::POSITION))->val;
    Component::RigidBody    *aRigidBody = (Component::RigidBody*)a->getComponent(Component::Type::RIGIDBODY);
    Component::RigidBody    *bRigidBody = (Component::RigidBody*)b->getComponent(Component::Type::RIGIDBODY);
    uint64_t  offset = a->getWorld().getOffset();

    if (a->getType() != Entity::Type::DECORATIVE)
      aPosition.setX(aPosition.getX() + offset);
    if (b->getType() != Entity::Type::DECORATIVE)
      bPosition.setX(bPosition.getX() + offset);

    return aPosition.getX() < bPosition.getX() + bRigidBody->width &&
    aPosition.getX() + aRigidBody->width > bPosition.getX() &&
    aPosition.getY() < bPosition.getY() + bRigidBody->height &&
    aPosition.getY() + aRigidBody->height > bPosition.getY();
}

void CollisionSystem::resolveCollisions(void) {
  while (!collisions.empty()){
        resolveCollision(collisions.top());
        collisions.pop();
    }
}

void CollisionSystem::resolveCollision(collision *c) {
    if (c->e1->hasComponent(Component::Type::COLLIDABLE))
      (((Component::ACollidable*)c->e1->getComponent(Component::Type::COLLIDABLE))->collideWith(c->e2, c->viewport));
    if (c->e2 && c->e2->hasComponent(Component::Type::COLLIDABLE))
      (((Component::ACollidable*)c->e2->getComponent(Component::Type::COLLIDABLE))->collideWith(c->e1, c->viewport));
}