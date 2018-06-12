#pragma once

#include  <vector>
#include  "game/Entity.hpp"

class World;
class ASystem;

class SystemManager
{
public:
  SystemManager(World& world);
  ~SystemManager();
  
  void    registerEntity(Entity *entity);
  void    unregisterEntity(Entity *entity);
  void    update(double elapsed_time);
  
private:
  std::vector<ASystem *>  _systems;
  World&                  _world;
};