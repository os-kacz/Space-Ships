#include "Alien.h"

Alien::Alien(sf::RenderWindow& game_window) : window(game_window)
{
  speed *= speed_multiplier;
}

Alien::~Alien()
{

}

bool Alien::initAlien()
{
  getSprite()->setScale(0.5,0.5);

  direction.x = 1 * speed;

  return initialiseSprite(
    texture,
    "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyRed1.png");
}

void Alien::update(float dt)
{
  getSprite()->move(direction.x * dt, 0);
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x = 1;
    direction.x *= speed;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x = -1;
    direction.x *= speed;
  }
}