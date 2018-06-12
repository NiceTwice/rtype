#pragma once

#include  <string>
#include <ctime>
#include <cstdlib>
#include  "game/Entity.hpp"

class IMob
{
public:
  virtual ~IMob() {}
  virtual void createEntity(Entity *entity) = 0;
  virtual std::string const getType() const = 0;
};