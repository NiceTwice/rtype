#pragma once

#include <map>
#include  "IMob.hpp"

class SpaceMob : public IMob
{
public:
  SpaceMob();
  ~SpaceMob();

  void             createEntity(Entity *entity);
  std::string const  getType() const;

private:
  void createHorizontalEntity(Entity *) const;
  void createDiagonalEntity(Entity *) const;

private:
  std::vector<void (SpaceMob::*)(Entity*) const> m_builders;
};