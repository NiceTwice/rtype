//
// LoadingScene.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/scenes/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:30:38 2016 Adrien Vasseur
// Last update Mon Dec 12 23:21:37 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/scenes/AScene.hpp"
#include	"gui/anim/FrameAnimation.hpp"
#include	"gui/anim/KeyAnimation.hpp"

class		LoadingScene : public AScene
{
public:
  LoadingScene(SFMLWindow &);
  ~LoadingScene();

  bool		create();
  void		display();
  void		destroy();

private:
  FrameAnimation	*_animation;

  void		loadAsset();
  void		internalInit();
  void		displayHud();
};
