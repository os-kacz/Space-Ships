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

  direction.x = 10;
  direction.y = 7;
  direction.normalise();

  return initialiseSprite(
    texture,
    "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyRed1.png");
}

void Alien::update(float dt)
{
  switch (pattern)
  {
    case (STRAIGHT):
    {
      moveStraight(dt);
      break;
    }
    case (GRAVITY):
    {
      moveGravity(dt);
      break;
    }
    case (QUADRATIC):
    {
      moveQuadratic(dt);
      break;
    }
    case (SINE):
    {
      moveSine(dt);
      break;
    }
    default:
    {
      moveStraight(dt);
      break;
    }
  }
}

void Alien::moveStraight(float dt)
{
  getSprite()->move(direction.x * dt * speed, direction.y * dt * speed);
  if (alienWindowCheck())
  {
    direction.x *= -1;
  }
}
void Alien::moveGravity(float dt)
{
  direction.y = pow(1.0013, getSprite()->getPosition().x);
  getSprite()->move(direction.x * dt * speed, direction.y * dt * speed);
  if (alienWindowCheck())
  {
    direction.x *= -1;
  }
}
void Alien::moveQuadratic(float dt)
{
  direction.y = pow((0.01*getSprite()->getPosition().x),2);
  getSprite()->move(direction.x * dt * speed, direction.y * dt * speed);
  if (alienWindowCheck())
  {
    direction.x *= -1;
  }
}
void Alien::moveSine(float dt)
{
  if (alienWindowCheck())
  {
    direction.x *= -1;
  }
}
bool Alien::alienWindowCheck()
{
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT
      || collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    return true;
  }
  return false;
}