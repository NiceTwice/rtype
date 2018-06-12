#include <game/component/Position.hpp>
#include <game/component/Direction.hpp>
#include <game/component/Velocity.hpp>
#include "game/system/MovementSystem.hpp"

MovementSystem::MovementSystem(World &world) : ASystem(world){
    _requirements = Component::Type::DIRECTION | Component::Type::POSITION | Component::Type::VELOCITY;
}

void MovementSystem::updateEntity(Entity *entity, float elapsed_time) {
    Vector2f& position = ((Component::Position*)entity->getComponent(Component::Type::POSITION))->val;
    Vector2f& prev = ((Component::Position*)entity->getComponent(Component::Type::POSITION))->prev;
    Vector2f& direction = ((Component::Direction*)entity->getComponent(Component::Type::DIRECTION))->val;
    float velocity = ((Component::Velocity*)entity->getComponent(Component::Type::VELOCITY))->val;

    prev = position;
    position = position + direction * velocity * elapsed_time;
}