#ifndef SPACEINVADERSSFML_PLAYER_H
#define SPACEINVADERSSFML_PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{
 public:
  Player(sf::RenderWindow& window);
  ~Player();
  bool initPlayer();
  void move(sf::Event& event);
  void stop(sf::Event& event);
  void shoot(sf::Event& event);
  int lives;
  sf::Texture texture;
 private:
  float speed_multiplier = 4;
  sf::RenderWindow& window;
};

#endif // SPACEINVADERSSFML_PLAYER_H

