#include "Alien.h"

Alien::Alien(sf::RenderWindow& game_window) : window(game_window)
{

}

Alien::~Alien()
{

}

bool Alien::initAlien()
{
  initialiseSprite(
    texture,
    "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyRed1.png");
  getSprite()->setScale(0.5,0.5);
  return true;
}