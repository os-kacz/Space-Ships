#ifndef SPACEINVADERSSFML_PLAYER_H
#define SPACEINVADERSSFML_PLAYER_H

#include "GameObject.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{
 public:
  Player(sf::RenderWindow& window);
  ~Player();
  bool initPlayer();
  void update();
  void move(sf::Event& event);
  void stop(sf::Event& event);
  void shoot(sf::Event& event);
  void bulletUpdate(float dt);
  int const static max_ammo = 6;
  GameObject bullet[max_ammo];
  int bullet_count = 0;
 private:
  Collision collision;
  sf::Texture player_texture;
  sf::Texture bullet_texture;
  sf::RenderWindow& window;
  float speed_multiplier = 4;
  float shot_elapsed_time = 0;
};

#endif // SPACEINVADERSSFML_PLAYER_H

