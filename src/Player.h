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
  void bulletUpdate();
  GameObject bullet[5];
  int lives;
 private:
  sf::Texture player_texture;
  sf::Texture bullet_texture;
  int bullet_count = -1;
  float speed_multiplier = 4;
  sf::RenderWindow& window;
};

#endif // SPACEINVADERSSFML_PLAYER_H

