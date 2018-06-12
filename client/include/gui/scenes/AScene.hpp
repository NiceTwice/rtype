//
// AScene.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/scenes/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Mon Dec 12 23:20:38 2016 Adrien Vasseur
// Last update Mon Dec 12 23:22:49 2016 Adrien Vasseur
//

#pragma		once

#include	"gui/IView.hpp"
#include	"gui/sfml/SFMLInputHandler.hpp"

class		AScene : public IView, public SFMLInputHandler
{
public:
  AScene(SFMLWindow &);
  ~AScene();
};
