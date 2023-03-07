#ifndef SPACEINVADERSSFML_ALIEN_H
#define SPACEINVADERSSFML_ALIEN_H

#include "GameObject.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>

class Alien : public GameObject
{
 public:
  Alien(sf::RenderWindow& window);
  ~Alien();
  bool initAlien();
  void update(float dt);
 private:
  sf::Texture texture;
  float speed_multiplier = 2.5;
  sf::RenderWindow& window;
  Collision collision;
};

#endif // SPACEINVADERSSFML_ALIEN_H
