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

void Collision::windowCheck(GameObject& affector, sf::RenderWindow& window)
{
  if (affector.getSprite()->getPosition().x >
      (window.getSize().x - affector.getSprite()->getGlobalBounds().width))
  {
    affector.getSprite()->setPosition(
      window.getSize().x - affector.getSprite()->getGlobalBounds().width,
      affector.getSprite()->getPosition().y);
  }

  if (affector.getSprite()->getPosition().x < 0)
  {
    affector.getSprite()->setPosition(
      0,
      0);
  }

  if (affector.getSprite()->getPosition().y >
      (window.getSize().y - affector.getSprite()->getGlobalBounds().height))
  {
    affector.getSprite()->setPosition(
      affector.getSprite()->getPosition().x,
      (window.getSize().y - affector.getSprite()->getGlobalBounds().height));
  }

  if (affector.getSprite()->getPosition().y < 0)
  {
    affector.getSprite()->setPosition(
      0,
      0);
  }
}

bool Collision::deflectCheck()
{
  return false;
}