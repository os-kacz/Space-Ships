#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  bool visible = true;
  int health;
  float speed = 100;
  Vector2 direction = Vector2(0, 0);

  void getBoundingBox();
  float top_l_x;
  float top_r_x;
  float top_l_y;
  float bot_l_y;

 private:
  sf::Sprite* sprite = nullptr;

};

#endif // SPACEINVADERS_GAMEOBJECT_H
