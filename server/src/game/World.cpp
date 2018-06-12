#include	<algorithm>
#include	"game/World.hpp"
#include	"game/component/Position.hpp"
#include	"game/component/Direction.hpp"
#include	"game/component/Sprite.hpp"
#include  "game/component/Velocity.hpp"
#include  "packet/PacketSender.hpp"
#include  "game/map/MapPool.hpp"
#include  "packet/protocol/ReadyPacket.hpp"
#include  "packet/protocol/PacketIdentifier.hpp"
#include  "game/system/MovementSystem.hpp"
#include  "game/system/CollisionSystem.hpp"
#include  "game/system/RemovingSystem.hpp"
#include  "game/system/HealthSystem.hpp"
#include  "game/component/PlayerCollidable.hpp"


World::World(uint16_t limit) : m_playerLimit(limit), _systemManager(*this), _spawner(*this), _ended(false)
{
  std::cerr << "[INFO] New world created" << std::endl;
  this->_player_count = 0;
  this->_running = false;
  this->_map = MapPool::getInstance().getMap();
  this->_offset = 0;
  this->_update = false;

  std::uint32_t posX = 0;
  for (std::size_t chunks = 0; chunks < this->_map->getChunks().size(); chunks++)
  {
    for (std::size_t entities = 0; entities < this->_map->getChunks().at(chunks)->getEntities().size(); entities++)
      this->_factory.createStaticMesh(*this, this->_map->getChunks().at(chunks)->getEntities().at(entities), posX);
    posX += this->_map->getChunks().at(chunks)->getWidth();
  }
}

World::~World()
{
}

void        World::addEntity(Entity* entity)
{
  if (entity == nullptr)
    return ;
  this->_entityList.push_back(entity);
  this->_systemManager.registerEntity(entity);
}

void		World::destroyEntity(Entity* entity)
{
  std::vector<Entity *>::const_iterator item;

  if (entity == nullptr)
    return ;
	item = std::find(this->_entityList.begin(), this->_entityList.end(), entity);
	if (item == this->_entityList.end())
		return;
  for (Converter *player: this->_playerList) {
    if (player->getPlayer().getEntity() == entity) {
      player->getPlayer().removeLife();
      player->getPlayer().setEntity(nullptr);
    }
  }
  this->_entityList.erase(item);
  this->_systemManager.unregisterEntity(entity);
  //delete entity;
}

void		World::run()
{
  this->_running = true;
  this->_clock = std::chrono::steady_clock::now();
}

bool	World::isRunning() const
{
  return (this->_running);
}

void    World::insertEntity(PacketSerializer &packet, Entity *entity)
{
    packet << (uint64_t)entity->getID();
    packet << ((Component::Sprite *)(entity->getComponent(Component::Type::SPRITE)))->id;
    packet << ((Component::Velocity *)(entity->getComponent(Component::Type::VELOCITY)))->val;
    packet << Vector2f(((Component::Position *)(entity->getComponent(Component::Type::POSITION)))->val.getX(),
           ((Component::Position *)(entity->getComponent(Component::Type::POSITION)))->val.getY());
    packet << Vector2f(((Component::Direction *)(entity->getComponent(Component::Type::DIRECTION)))->val.getX(),
           ((Component::Direction *)(entity->getComponent(Component::Type::DIRECTION)))->val.getY());
}

void		World::respawn(Converter *player)
{
  PacketSerializer serializer;
  Entity *ship = this->_factory.createPlayer((*this));

  player->setPlayerEntity(ship);
  serializer << player->getPlayer().getLife();
  PacketSender::set(NetworkCommunicationType::UDP, player, PacketIdentifier::SPAWN_PACKET, serializer);
}

void		World::spawnHandling(std::chrono::steady_clock::time_point const& now)
{
  for (Converter *player: this->_playerList) {
    if (player->getPlayer().getEntity() == nullptr && player->getPlayer().getLife() > 0 &&
	std::chrono::duration_cast<std::chrono::milliseconds>(now - player->getPlayer().getDeadTime()).count() > RESPAWN_DELAY * 1000)
      this->respawn(player);
    else if (player->getPlayer().getEntity() != nullptr && player->getPlayer().getEntity()->getComponent(Component::Type::COLLIDABLE) == nullptr &&
	     std::chrono::duration_cast<std::chrono::milliseconds>(now - player->getPlayer().getSpawnTime()).count() > INVINCIBILITY_DURATION * 1000)
      player->getPlayer().getEntity()->addComponent(new Component::PlayerCollidable(*(player->getPlayer().getEntity())));
  }
}

bool		World::endGame(void)
{
  bool end = false;
  bool victory = false;
  bool anyAlive = false;

  if (this->_playerList.size() == 0)
    return (false);
  for (Converter *player: this->_playerList) {
    if (player->getPlayer().getLife() > 0) {
      anyAlive = true;
      break;
    }
  }
  if ((end = !anyAlive) == false) {
    uint64_t offset = 0;

    for (auto& chunk: this->getMap()->getChunks())
      offset += chunk->getWidth();
    if ((end = (this->_offset > (offset/* - this->getMap()->getViewport().getX()*/))) == true)
      victory = true;
  }
  if (end == true) {
    PacketSerializer serializer;

    serializer << victory;
    for (Converter *player: this->_playerList) {
      PacketSender::set(NetworkCommunicationType::TCP, player, PacketIdentifier::ENDGAME_PACKET, serializer);
    }
  }
  return (end);
}

void		World::update()
{
  std::chrono::steady_clock::time_point	now = std::chrono::steady_clock::now();
  double elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_clock).count();
  PacketSerializer playersPacket;
  uint16_t playersSize = 0;
  PacketSerializer *objPacket;
  std::vector<PacketSerializer *> objectsPacket;
  uint16_t objectsSize = 0;
  PacketSerializer tmp;
  PacketSerializer *tmp2;

  this->_update = true;
  this->_offset += 1.0f * elapsed_time / 15.0f;
  this->_spawner.spawnMob(this->_offset, elapsed_time);
  this->_systemManager.update(elapsed_time);
  playersPacket << (uint64_t)this->_offset;

  objPacket = new PacketSerializer;
  *objPacket << (uint64_t)this->_offset;
  tmp2 = new PacketSerializer;
  if (this->_ended == true)
    return ;
  this->_mutex.lock();

  if (this->endGame() == false) {
    this->spawnHandling(now);
    for (auto& entity : this->_entityList)
    {
      if (entity->getType() == Entity::PLAYER)
	{
	  this->insertEntity(tmp, entity);
	  playersSize++;
	}
      else if (entity->getType() != Entity::DECORATIVE)
	{
	  this->insertEntity(*tmp2, entity);
	  objectsSize++;
	  if (objectsSize >= 16)
	    {
	      *objPacket << objectsSize;
	      *objPacket << *tmp2;
	      delete tmp2;
	      tmp2 = new PacketSerializer;
	      objectsPacket.push_back(objPacket);
	      objPacket = new PacketSerializer;
	      *objPacket << (uint64_t)this->_offset;
	      objectsSize = 0;
	    }
	}
    }

    this->_mutex.unlock();
    playersPacket << playersSize;
    playersPacket << tmp;
    *objPacket << objectsSize;
    *objPacket << *tmp2;
    delete tmp2;
    objectsPacket.push_back(objPacket);
    this->_mutex.lock();
    for (auto& player : this->_playerList)
      {
	if (player->getClient()->hasUDP())
	  {
	    if (playersSize > 0)
	      PacketSender::set(NetworkCommunicationType::UDP, player, PacketIdentifier::ENTITY_PACKET, playersPacket);
	    for (PacketSerializer *tmpPacket: objectsPacket)
	      {
		if (objectsSize > 0)
		  PacketSender::set(NetworkCommunicationType::UDP, player, PacketIdentifier::ENTITY_PACKET, *tmpPacket);
	      }
	  }
      }
      for (PacketSerializer *tmpPacket: objectsPacket) {
	delete tmpPacket;
      }
  }
  else
    this->_ended = true;
  this->_mutex.unlock();
  this->_clock = std::chrono::steady_clock::now();
  this->_update = false;
}

bool    World::inUpdate()
{
  return (this->_update);
}

bool	World::createPlayer(Converter *player)
{
  if (this->full() == true)
    return (false);

  player->getPlayer().setWorld(this);
  this->respawn(player);
  this->_playerList.push_back(player);
  this->_player_count += 1;
  return (true);
}

void  World::disconnectPlayer(Converter *player)
{
  std::vector<Converter *>::const_iterator item;

  this->_mutex.lock();
  item = std::find(this->_playerList.begin(), this->_playerList.end(), player);
  if (item == this->_playerList.end()) {
    this->_mutex.unlock();
		return;
  }
  player->lock();
  this->destroyEntity(player->getPlayer().getEntity());
  player->setPlayerEntity(nullptr);
  player->unlock();
  this->_playerList.erase(item);
  this->_player_count -= 1;
  this->_mutex.unlock();
  //if (this->_player_count == 0)
  //  this->_running = false;
  ReadyPacket::broadcast(*this);
}

uint64_t  World::getOffset()
{
  return (this->_offset);
}

const std::vector<Converter *> &World::getPlayerList() const
{
  return (this->_playerList);
}

unsigned int	World::getPlayerCount() const
{
  return (this->_player_count);
}

unsigned int  World::getPlayerReady()
{
  unsigned int i = 0;

  this->_mutex.lock();
  for (auto &player : this->_playerList)
  {
    if (player->getPlayer().isReady())
      i++;
  }
  this->_mutex.unlock();
  return (i);
}

EntityFactory   &World::getFactory()
{
  return (this->_factory);
}

const Map *World::getMap() const
{
  return (this->_map);
}

uint16_t World::getNextSpriteId(void) const
{
  uint16_t count;
  std::map<uint16_t, bool> spriteIds;
  Component::Sprite *component;

  for (count = 0; count < this->m_playerLimit; ++count) {
    spriteIds[count] = false;
  }
  for (auto& entity : this->_entityList)
  {
    if (entity->getType() == Entity::PLAYER)
      if ((component = reinterpret_cast<Component::Sprite *>(entity->getComponent(Component::Type::SPRITE))) != nullptr)
        spriteIds[component->id] = true;
  }
  for (count = 0; count < this->m_playerLimit; ++count) {
    if (spriteIds[count] == false)
      return (count);
  }
  return (this->m_playerLimit);
}

bool World::full(void) const
{
  return (this->_player_count == this->m_playerLimit);
}

bool World::empty(void) const
{
  return (this->_player_count == 0);
}

void World::lock()
{
  this->_mutex.lock();
}

void World::unlock()
{
  this->_mutex.unlock();
}