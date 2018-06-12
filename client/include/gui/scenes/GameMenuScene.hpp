//
// GameMenuScene.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/scenes/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  2 16:06:43 2016 Adrien Vasseur
// Last update Wed Dec 14 11:38:13 2016 Adrien Vasseur
//

#pragma		once

#include    "gui/sfml/SFMLText.hpp"
#include    "gui/IMusic.hpp"
#include	"gui/scenes/AScene.hpp"
#include	"gui/anim/KeyAnimation.hpp"
#include	"gui/anim/FadeAnimation.hpp"

class		GameMenuScene : public AScene
{
public:
  GameMenuScene(SFMLWindow &);
  ~GameMenuScene();

  bool		create();
  void		display();
  void		destroy();

  void      onJoystickButtonReleased();
  void		onKeyReleased();

private:
  KeyAnimation	_rAnimation;
  KeyAnimation	_rTypeAnimation;
  FadeAnimation	_hudAnimations[6];

  IMusic        *_beginMusic;
  IMusic        *_loopMusic;
  bool          _beginHasPlayed;

  SFMLText      _playersLabel;

  std::string   _readyMsg[2];

  bool		initHud();
  void		displayHud();
  void      updateSounds();
  void      updateAnimations();
  void      updateGame();
};
