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

  direction.x = 1;
  direction.y = 1;

  return initialiseSprite(
    texture,
    "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyRed1.png");
}

void Alien::update(float dt)
{
  x_axis = getSprite()->getPosition().x;
  y_axis = getSprite()->getPosition().y;
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
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x *= -1;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x *= -1;
  }
}
void Alien::moveGravity(float dt)
{
  direction.y = pow(1.0013, x_axis);
  getSprite()->move(direction.x * dt * speed, direction.y * dt * speed);
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x *= -1;
    x_axis = getSprite()->getPosition().x;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x *= -1;
    x_axis = window.getSize().x - getSprite()->getPosition().x;
  }
}
void Alien::moveQuadratic(float dt)
{
  y_axis = ((-0.0007*x_axis*x_axis) + (0.78*x_axis));
  getSprite()->setPosition(x_axis+direction.x, y_axis);
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x *= -1;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x *= -1;
  }
}
void Alien::moveSine(float dt)
{
  float a, b;
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x *= -1;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x *= -1;
  }
}