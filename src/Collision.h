#ifndef SPACEINVADERSSFML_COLLISION_H
#define SPACEINVADERSSFML_COLLISION_H

#include "GameObject.h"

class Collision
{
 public:
  Collision();
  ~Collision();
  bool collisionCheck(GameObject& affector, GameObject& affected);
 private:
  bool deflectCheck()
};

#endif // SPACEINVADERSSFML_COLLISION_H
