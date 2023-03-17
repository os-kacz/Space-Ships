#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Collision.h"
#include "Player.h"
#include "Alien.h"
#include "Interface.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;
  Interface interface;
  Player player;
  Collision collision;
  const static int column = 14;
  const static int row = 5;
  Alien* alien[column*row];
  int alien_grid = 0;
  int score = 0;
  enum
  { MAINMENU,
    OPTIONS,
    PLAYGAME,
    GAMELOSS,
    GAMEWIN,
  } gamestate;
  int pattern_choice;
  void spawnAlien();
};

#endif // SPACEINVADERS_GAME_H
