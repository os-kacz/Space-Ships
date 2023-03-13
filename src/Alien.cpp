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
  switch (pattern)
  {
    case (STRAIGHT):
    {
      y_axis = 1;
      move(dt);
      break;
    }
    case (GRAVITY):
    {
      y_axis = pow(1.004, x_axis);
      move(dt);
      break;
    }
    case (QUADRATIC):
    {
      y_axis = ((-0.0007*x_axis*x_axis) + (0.78*x_axis));
      move(dt);
      break;
    }
    case (SINE):
    {
      y_axis = (70 * sin(0.01 * x_axis) + 100);
      move(dt);
      break;
    }
    default:
    {
      move(dt);
      break;
    }
  }
}

void Alien::move(float dt)
{
  getSprite()->setPosition(x_axis + direction.x * dt * speed, y_axis + step + initial_pos);
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    direction.x *= -1;
    step += 50;
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    direction.x *= -1;
    step += 50;
  }
}
