#ifndef SPACEINVADERSSFML_ALIEN_H
#define SPACEINVADERSSFML_ALIEN_H

#include "GameObject.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Alien : public GameObject
{
 public:
  Alien(sf::RenderWindow& window);
  ~Alien();
  bool initAlien();
  enum
  { STRAIGHT,
    GRAVITY,
    QUADRATIC,
    SINE,
  } pattern;
  void update(float dt);
  float step;
  float initial_pos;
 private:
  void moveStraight(float dt);
  void moveGravity(float dt);
  void moveQuadratic(float dt);
  void moveSine(float dt);
  sf::Texture texture;
  float speed_multiplier = 2;
  sf::RenderWindow& window;
  Collision collision;
  float x_axis;
  float y_axis;
};

#endif // SPACEINVADERSSFML_ALIEN_H
