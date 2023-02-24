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
  GameObject bullet[5];
 private:
  sf::Texture player_texture;
  sf::Texture bullet_texture;
  float speed_multiplier = 4;
  sf::RenderWindow& window;
  int bullet_off_screen = -1;
};

#endif // SPACEINVADERSSFML_PLAYER_H

