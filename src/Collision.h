#ifndef SPACEINVADERSSFML_COLLISION_H
#define SPACEINVADERSSFML_COLLISION_H

#include "GameObject.h"

class Collision
{
 public:
  Collision();
  ~Collision();
  enum class Type
  {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    NONE,
  };
  bool gameobjectCheck(GameObject& affector, GameObject& affected);
  Type windowCheck(GameObject& affector, sf::RenderWindow& window);
};

#endif // SPACEINVADERSSFML_COLLISION_H
