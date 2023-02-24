#ifndef SPACEINVADERSSFML_ALIEN_H
#define SPACEINVADERSSFML_ALIEN_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Alien : public GameObject
{
 public:
  Alien(/*sf::RenderWindow& window*/);
  ~Alien();
  bool initAlien();
  void move();
 private:
  sf::Texture texture;
  float speed_multiplier = 2;
  //sf::RenderWindow& window;
};

#endif // SPACEINVADERSSFML_ALIEN_H
