//
// GameBoardScene.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 14 16:10:22 2016 Adrien Vasseur
// Last update Wed Dec 14 16:10:22 2016 Adrien Vasseur
//

#pragma     once

#include    <vector>
#include    "gui/sfml/SFMLText.hpp"
#include    "gui/IMusic.hpp"
#include    "gui/scenes/AScene.hpp"
#include    "gui/gfx/ADrawable.hpp"
#include    "gui/sfml/SFMLWindow.hpp"
#include    "gui/gfx/BlueStarsBackground.hpp"
#include    "game/map/MapEntity.hpp"

class       GameBoardScene : public AScene
{
public:
  GameBoardScene(SFMLWindow &);
  ~GameBoardScene();

  bool      create();
  void      display();
  void      destroy();

  void      onKeyReleased();

private:
  void      displayBackground(std::int64_t, std::uint32_t, std::uint8_t);
  void      displayBackgrounds(std::int64_t);

  void      displayStaticMesh(std::int64_t, const MapEntity *);
  void      displayStaticMeshs(std::int64_t);

  void      displayEntities();

  void      updateUserEvents();

  bool      initStaticMeshs();

  std::vector<ABackground *>  _backgrounds;
  std::vector<ADrawable *>    _drawable;
  std::map<std::uint64_t, ADrawable *>  _entities;
  std::vector<SFMLImage *>    _staticMeshs;

  IMusic                      *_music;

  SFMLText                    _creditsLabel;
  SFMLText                    _endLabel;
};