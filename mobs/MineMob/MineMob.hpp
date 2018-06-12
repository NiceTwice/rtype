#pragma once

#include <map>
#include  "IMob.hpp"

class MineMob : public IMob
{
public:
  MineMob();
  ~MineMob();

  void             createEntity(Entity *entity);
  std::string const  getType() const;

private:
  void createHorizontalEntity(Entity *) const;
  void createDiagonalEntity(Entity *) const;

private:
  std::vector<void (MineMob::*)(Entity*) const> m_builders;
};
