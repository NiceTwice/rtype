//
// GameMenuScene.cpp for rtype in /home/lanquemar/rendu/rtype/client/src/gui/scenes/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Dec  2 18:03:15 2016 Adrien Vasseur
// Last update Wed Dec 14 13:35:09 2016 Adrien Vasseur
//

#include	<cstdlib>
#include	"gui/scenes/GameMenuScene.hpp"
#include	"gui/res/ResPool.hpp"
#include	"gui/MainWindow.hpp"
#include    "core/GameCore.hpp"

GameMenuScene::GameMenuScene(SFMLWindow &win) : AScene(win)
{
  this->_beginMusic = NULL;
  this->_loopMusic = NULL;
  this->_beginHasPlayed = false;
  this->_readyMsg[0] = "[NOT READY]";
  this->_readyMsg[1] = "[READY]";
}

GameMenuScene::~GameMenuScene()
{

}

bool		GameMenuScene::initHud()
{
  for (unsigned int i = 0; i < 6; i++)
    {
      if (ResPool::getInstance().getImage("menuhud-0x" + std::to_string(i)) == NULL)
		return (false);
      this->_hudAnimations[i].setImage(ResPool::getInstance().getImage("menuhud-0x" + std::to_string(i)));
      this->_hudAnimations[i].setRepeated(false);
      this->_hudAnimations[i].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x0")->getSize().getX(), ResPool::getInstance().getImage("menuhud-0x0")->getSize().getY() * i));
    }
  this->_hudAnimations[0].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x0")->getSize().getX() - 5, 5));
  this->_hudAnimations[1].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x1")->getSize().getX() - 5, ResPool::getInstance().getImage("menuhud-0x0")->getSize().getY() + 10));
  this->_hudAnimations[2].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x2")->getSize().getX() - 5, ResPool::getInstance().getImage("menuhud-0x0")->getSize().getY() + 10 + ResPool::getInstance().getImage("menuhud-0x1")->getSize().getY() + 35));
  this->_hudAnimations[3].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x3")->getSize().getX() - 5, MainWindow::getInstance().getHeight() - ResPool::getInstance().getImage("menuhud-0x4")->getSize().getY() - 10 - ResPool::getInstance().getImage("menuhud-0x3")->getSize().getY()));
  this->_hudAnimations[4].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x4")->getSize().getX() - 5, MainWindow::getInstance().getHeight() - ResPool::getInstance().getImage("menuhud-0x4")->getSize().getY() - 5));
  this->_hudAnimations[5].setPosition(Vector2f(MainWindow::getInstance().getWidth() - ResPool::getInstance().getImage("menuhud-0x5")->getSize().getX() - 5, ResPool::getInstance().getImage("menuhud-0x0")->getSize().getY() + 10 + ResPool::getInstance().getImage("menuhud-0x1")->getSize().getY() + 85));
  this->_hudAnimations[5].setRepeated(true);
  if (ResPool::getInstance().getFont("VCR") != NULL)
  {
    this->_playersLabel.setFont(ResPool::getInstance().getFont("VCR"));
    this->_playersLabel.setPosition(Vector2f(5, 5));
  }
  else
    return (false);
  return (true);
}

bool		GameMenuScene::create()
{
  if (ResPool::getInstance().getImage("r-0x0") == NULL ||
      ResPool::getInstance().getImage("r-type-0x0") == NULL ||
      ResPool::getInstance().getImage("menuhud-0x0") == NULL ||
      !this->initHud())
    return (false);
  this->_rAnimation.setImage(ResPool::getInstance().getImage("r-0x0"));
  this->_rAnimation.addKey(Vector2f((float) MainWindow::getInstance().getWidth(), (float) MainWindow::getInstance().getHeight() / 2 - ResPool::getInstance().getImage("r-0x0")->getSize().getY()));
  this->_rAnimation.addKey(Vector2f(- ResPool::getInstance().getImage("r-0x0")->getSize().getX(), MainWindow::getInstance().getHeight() / 2 - ResPool::getInstance().getImage("r-0x0")->getSize().getY()));
  this->_rAnimation.setInterval(1000);
  this->_rAnimation.setRepeated(false);
  this->_rAnimation.start();
  this->_rTypeAnimation.setImage(ResPool::getInstance().getImage("r-type-0x0"));
  this->_rTypeAnimation.addKey(Vector2f(- ResPool::getInstance().getImage("r-type-0x0")->getSize().getX(), MainWindow::getInstance().getHeight() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getY()));
  this->_rTypeAnimation.addKey(Vector2f(- ResPool::getInstance().getImage("r-type-0x0")->getSize().getX(), MainWindow::getInstance().getHeight() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getY()));
  this->_rTypeAnimation.addKey(Vector2f(MainWindow::getInstance().getWidth() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getX() / 2, MainWindow::getInstance().getHeight() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getY()));
  this->_rTypeAnimation.addKey(Vector2f(MainWindow::getInstance().getWidth() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getX() / 2, MainWindow::getInstance().getHeight() / 2 + ResPool::getInstance().getImage("r-type-0x0")->getSize().getY() / 2));
  this->_rTypeAnimation.setInterval(1000);
  this->_rTypeAnimation.setRepeated(false);
  this->_rTypeAnimation.start();
  if ((this->_beginMusic = ResPool::getInstance().getMusic("RType-Menu-Begin")) == NULL ||
      (this->_loopMusic = ResPool::getInstance().getMusic("RType-Menu-Loop")) == NULL)
    return (false);
  this->_loopMusic->setLoop(true);
  return (init());
}

void		GameMenuScene::displayHud()
{

  for (unsigned int i = 0; i < 6; i++)
    {
      if (!this->_hudAnimations[i].isRunning())
        this->_hudAnimations[i].start();
      this->_hudAnimations[i].display();
    }
  this->_playersLabel.setColor(255, 255, 255, (unsigned char) (this->_hudAnimations[0].getAlpha() * 255.0f));
  this->_playersLabel.setString(this->_readyMsg[(int) GameCore::getInstance().isReady()] + "\nPlayers: " + std::to_string(GameCore::getInstance().getReadyPlayers()) + " / " + std::to_string(GameCore::getInstance().getPlayers()));
  this->_playersLabel.display();
}

void        GameMenuScene::updateSounds()
{
  if (!this->_beginHasPlayed && !this->_beginMusic->isRunning())
  {
    this->_beginMusic->start();
    this->_beginHasPlayed = true;
  }
  else if (this->_beginHasPlayed && !this->_beginMusic->isRunning() && !this->_loopMusic->isRunning())
    this->_loopMusic->start();
}

void      GameMenuScene::updateAnimations()
{
  if (!this->_rAnimation.isOnLastKey())
    this->_rAnimation.display();
  else if (!this->_rTypeAnimation.isOnLastKey())
    this->_rTypeAnimation.display();
  else if (ResPool::getInstance().getImage("r-type-0x0"))
  {
    ResPool::getInstance().getImage("r-type-0x0")->setPosition(Vector2f(MainWindow::getInstance().getWidth() / 2 - ResPool::getInstance().getImage("r-type-0x0")->getSize().getX() / 2, MainWindow::getInstance().getHeight() / 2 + ResPool::getInstance().getImage("r-type-0x0")->getSize().getY() / 2));
    ResPool::getInstance().getImage("r-type-0x0")->display();
    this->displayHud();
  }
}

void      GameMenuScene::updateGame()
{
  if (GameCore::getInstance().isNetReady() && GameCore::getInstance().isGameReady())
    MainWindow::getInstance().getSceneManager().setScene("GameBoardScene");
}

void		GameMenuScene::display()
{
  this->updateSounds();
  this->updateAnimations();
  this->updateGame();
}

void		GameMenuScene::destroy()
{
  this->_rAnimation.destroy();
  this->_rTypeAnimation.destroy();
  for (std::size_t i = 0; i < 6; i++)
    this->_hudAnimations[i].destroy();
  this->_beginMusic->stop();
  this->_loopMusic->stop();
}

void        GameMenuScene::onJoystickButtonReleased()
{
  if (getEvent().getJoystickKey() == Event::SPACE &&
      this->_rTypeAnimation.isOnLastKey())
    GameCore::getInstance().ready();
}

void		GameMenuScene::onKeyReleased()
{
  if (((getEvent().getKeyboardKey() == Event::SPACE) ||
          (getEvent().getKeyboardKey() == Event::RETURN)) &&
          (this->_rTypeAnimation.isOnLastKey()))
    GameCore::getInstance().ready();
  else if (getEvent().getKeyboardKey() == Event::ESCAPE)
    MainWindow::getInstance().close();
}