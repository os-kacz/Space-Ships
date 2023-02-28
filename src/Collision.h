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
  };
  bool collisionCheck(GameObject& affector, GameObject& affected);
  Type windowCheck(GameObject& affector, sf::RenderWindow& window);
 private:
  bool deflectCheck();
};

#endif // SPACEINVADERSSFML_COLLISION_H
