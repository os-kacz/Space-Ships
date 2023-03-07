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
  const static int column = 10;
  const static int row = 3;
  Alien alien[column*row];
  int alien_grid = 0;
  Collision collision;
  enum
  { MAINMENU = 0,
    PLAYGAME = 1,
    GAMELOSS = 2,
    GAMEWIN  = 3,
  } gamestate;
  bool yn;
};

#endif // SPACEINVADERS_GAME_H
