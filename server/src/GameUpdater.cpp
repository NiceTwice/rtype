#include	"GameUpdater.hpp"

GameUpdater::GameUpdater(World& world) : _world(world)
{
  
}

GameUpdater::~GameUpdater()
{
  
}

void		GameUpdater::process(void)
{
  this->_world.update();
}