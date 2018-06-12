#pragma once

#include	"pool/ITask.hpp"
#include  "game/World.hpp"

class	GameUpdater : public ITask
{
public:
  GameUpdater(World& world);
  ~GameUpdater();
  
  void		process(void);
  
private:
  World&		_world;
};