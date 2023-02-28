#include "Collision.h"

Collision::Collision()
{

}

Collision::~Collision()
{

}

bool Collision::collisionCheck(GameObject& affector, GameObject& affected)
{
  return false;
}

Collision::Type
Collision::windowCheck(GameObject& affector, sf::RenderWindow& window)
{
  if (affector.getSprite()->getPosition().x >
      (window.getSize().x - affector.getSprite()->getGlobalBounds().width))
  {
    affector.getSprite()->setPosition(
      window.getSize().x - affector.getSprite()->getGlobalBounds().width,
      affector.getSprite()->getPosition().y);
    return Type::RIGHT;
  }

  if (affector.getSprite()->getPosition().x < 0)
  {
    affector.getSprite()->setPosition(
      0,
      affector.getSprite()->getPosition().y);
    return Type::LEFT;
  }

  if (affector.getSprite()->getPosition().y >
      (window.getSize().y - affector.getSprite()->getGlobalBounds().height))
  {
    return Type::BOTTOM;
  }

  if (affector.getSprite()->getPosition().y < 0)
  {
    return Type::TOP;
  }
}

bool Collision::deflectCheck()
{
  return false;
}