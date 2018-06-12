//
// GameBoardScene.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 14 16:14:17 2016 Adrien Vasseur
// Last update Fri Dec 30 15:19:28 2016 Adrien Vasseur
//

#include <gui/gfx/MobDrawable.hpp>
#include    "gui/MainWindow.hpp"
#include    "gui/gfx/InsideShipBackground.hpp"
#include    "gui/gfx/InsideMineBackground.hpp"
#include    "gui/gfx/PlayerDrawable.hpp"
#include    "gui/gfx/ImageDrawable.hpp"
#include    "gui/scenes/GameBoardScene.hpp"
#include    "gui/res/ResPool.hpp"
#include    "core/GameCore.hpp"

GameBoardScene::GameBoardScene(SFMLWindow &win) : AScene(win)
{
  this->_backgrounds.push_back(new BlueStarsBackground());
  this->_backgrounds.push_back(new InsideShipBackground());
  this->_backgrounds.push_back(new InsideMineBackground());
  this->_drawable.push_back(new PlayerDrawable());
  this->_drawable.push_back(new PlayerDrawable());
  this->_drawable.push_back(new PlayerDrawable());
  this->_drawable.push_back(new PlayerDrawable());
  this->_drawable.push_back(new ImageDrawable("missiles-0x0", "Shoot"));
  this->_drawable.push_back(new MobDrawable(1));
  this->_drawable.push_back(new MobDrawable(2));
  this->_drawable.push_back(new MobDrawable(3));
  this->_music = NULL;
}

GameBoardScene::~GameBoardScene()
{
  for (std::vector<ABackground *>::iterator ite = this->_backgrounds.begin(); ite != this->_backgrounds.end(); ite++)
    delete *ite;
  this->_backgrounds.clear();
  for (std::vector<ADrawable *>::iterator ite = this->_drawable.begin(); ite != this->_drawable.end(); ite++)
    delete *ite;
  this->_drawable.clear();
}

bool        GameBoardScene::initStaticMeshs()
{
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-0x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-1x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-2x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-3x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-0x1"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-1x1"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-2x1"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-3x1"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-0x2"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-1x2"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-2x2"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-0x3"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-1x3"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-1-2x3"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-2-0x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-2-1x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-3-0x0"));
  this->_staticMeshs.push_back(ResPool::getInstance().getImage("static-meshs-3-0x1"));
  for (std::vector<SFMLImage *>::iterator ite = this->_staticMeshs.begin(); ite != this->_staticMeshs.end(); ite++)
    if (*ite == NULL)
    {
      this->_staticMeshs.clear();
      return (false);
    }
  return (true);
}

bool        GameBoardScene::create()
{
  if (init())
  {
    if ((this->_music = ResPool::getInstance().getMusic("RType-Game-Loop")) == NULL)
      return (false);
    this->_music->start();
    for (std::size_t ite = 0; ite < this->_backgrounds.size(); ite++)
    {
      if (!this->_backgrounds.at(ite)->create())
        return (false);
    }
    if (GameCore::getInstance().getMap() != NULL)
    {
      MainWindow::getInstance().setWidth((unsigned int) GameCore::getInstance().getMap()->getViewport().getX());
      MainWindow::getInstance().setHeight((unsigned int) GameCore::getInstance().getMap()->getViewport().getY());
    }
    if (ResPool::getInstance().getFont("VCR") != NULL)
    {
      this->_creditsLabel.setFont(ResPool::getInstance().getFont("VCR"));
      this->_creditsLabel.setPosition(Vector2f(5, 5));
      this->_endLabel.setFont(ResPool::getInstance().getFont("VCR"));
      this->_endLabel.setSize(32);
      this->_endLabel.setPosition(Vector2f(20, 20));
    }
    return (initStaticMeshs());
  }
  return (false);
}

void        GameBoardScene::displayBackground(std::int64_t posX, std::uint32_t width, std::uint8_t id)
{
  ABackground   *background = this->_backgrounds.at(0);

  if (id >= 0 && id < this->_backgrounds.size())
    background = this->_backgrounds.at(id);
  background->setWidth(width);
  background->setOffset(posX);
  background->display();
}

void        GameBoardScene::displayBackgrounds(std::int64_t mapOffset)
{
  std::int64_t posX = 0;

  for (std::size_t ite = 0; ite < GameCore::getInstance().getMap()->getChunks().size(); ite++)
  {
    if (posX + GameCore::getInstance().getMap()->getChunks().at(ite)->getWidth() >= mapOffset)
      this->displayBackground(posX - mapOffset, GameCore::getInstance().getMap()->getChunks().at(ite)->getWidth(), GameCore::getInstance().getMap()->getChunks().at(ite)->getBackground());
    posX += GameCore::getInstance().getMap()->getChunks().at(ite)->getWidth();
  }
}

void        GameBoardScene::displayStaticMesh(std::int64_t offset, const MapEntity *entity)
{
  if (entity->getSprite() < this->_staticMeshs.size())
  {
    this->_staticMeshs.at(entity->getSprite())->setPosition(Vector2f(entity->getPosition().getX() + offset, entity->getPosition().getY()));
    this->_staticMeshs.at(entity->getSprite())->display();
  }
}

void        GameBoardScene::displayStaticMeshs(std::int64_t mapOffset)
{
  std::int64_t posX = 0;

  for (std::size_t ite = 0; ite < GameCore::getInstance().getMap()->getChunks().size(); ite++)
  {
    if (posX + GameCore::getInstance().getMap()->getChunks().at(ite)->getWidth() >= mapOffset)
    {
      for (std::size_t entities = 0; entities < GameCore::getInstance().getMap()->getChunks().at(ite)->getEntities().size(); entities++)
        this->displayStaticMesh(posX - mapOffset, GameCore::getInstance().getMap()->getChunks().at(ite)->getEntities().at(entities));
    }
    posX += GameCore::getInstance().getMap()->getChunks().at(ite)->getWidth();
  }
}

void        GameBoardScene::displayEntities()
{
  std::map<std::uint64_t, MovableEntity *> *entities;
  std::map<std::uint64_t, MovableEntity *>::iterator ite;

  entities = GameCore::getInstance().getEntities();
  for (ite = entities->begin(); ite != entities->end(); ite++)
  {
    if (this->_entities.find(ite->first) != this->_entities.end())
    {
      this->_entities.at(ite->first)->display();
      if (ite->second->getDeleted())
      {
        delete this->_entities.at(ite->first);
        this->_entities.erase(ite->first);
      }
    }
    else if (ite->second->getSprite() < this->_drawable.size() && !ite->second->getDeleted())
    {
      this->_entities[ite->first] = this->_drawable.at(ite->second->getSprite())->clone(ite->second);
      this->_entities[ite->first]->create();
    }
    else
    {
      if (ResPool::getInstance().getImage("unknown-0x0") != NULL && !ite->second->getDeleted())
      {
        ResPool::getInstance().getImage("unknown-0x0")->setPosition(ite->second->getPosition());
        ResPool::getInstance().getImage("unknown-0x0")->display();
      }
    }
  }
}

void        GameBoardScene::updateUserEvents()
{
  Vector2f  dir;

  dir.setX((1.0f * (float) (getEvent().isKeyPressed(Event::RIGHT)) - 1.0f * (float) (getEvent().isKeyPressed(Event::LEFT))) * 100.0f);
  if (getEvent().getAxisValue(Event::X_AXIS) < -25.0f ||
      getEvent().getAxisValue(Event::X_AXIS) > 25.0f)
    dir.setX(dir.getX() + getEvent().getAxisValue(Event::X_AXIS));
  dir.setY((1.0f * (float) (getEvent().isKeyPressed(Event::DOWN)) - 1.0f * (float) (getEvent().isKeyPressed(Event::UP))) * 100.0f);
  if (getEvent().getAxisValue(Event::Y_AXIS) < -25.0f ||
      getEvent().getAxisValue(Event::Y_AXIS) > 25.0f)
    dir.setY(dir.getY() + getEvent().getAxisValue(Event::Y_AXIS));
  dir.normalize();
  GameCore::getInstance().setPlayerDir(dir);
  GameCore::getInstance().setFiring(getEvent().isKeyPressed(Event::SPACE));
}

void        GameBoardScene::display()
{
  std::uint64_t mapOffset = GameCore::getInstance().getMapOffset();

  if (GameCore::getInstance().getMap() != NULL)
  {
    this->displayBackgrounds((std::int64_t) mapOffset);
    this->displayStaticMeshs((std::int64_t) mapOffset);
    this->displayEntities();
    this->updateUserEvents();
  }
  this->_creditsLabel.setString(std::to_string(GameCore::getInstance().getLife() - 1) + " credits");
  this->_creditsLabel.display();
  if (GameCore::getInstance().getEnd() == 2)
    this->_endLabel.setString("GAME OVER");
  else if (GameCore::getInstance().getEnd() == 1)
    this->_endLabel.setString("VICTORY");
  this->_endLabel.display();
}

void        GameBoardScene::destroy()
{
  for (std::size_t ite = 0; ite < this->_backgrounds.size(); ite++)
    this->_backgrounds.at(ite)->destroy();
  if (this->_music)
  {
    this->_music->stop();
    this->_music = NULL;
  }
}

void        GameBoardScene::onKeyReleased()
{
  if (getEvent().getKeyboardKey() == Event::ESCAPE)
    MainWindow::getInstance().close();
}