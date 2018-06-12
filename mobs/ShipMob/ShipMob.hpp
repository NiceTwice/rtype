#pragma once

#include <map>
#include  "IMob.hpp"

class ShipMob : public IMob
{
public:
  ShipMob();
  ~ShipMob();

  void             createEntity(Entity *entity);
  std::string const  getType() const;

private:
  void createHorizontalEntity(Entity *) const;
  void createDiagonalEntity(Entity *) const;

private:
  std::vector<void (ShipMob::*)(Entity*) const> m_builders;
};
