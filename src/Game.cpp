
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window), interface(window), player(window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  player.initPlayer();
  return interface.initText();
}

void Game::update(float dt)
{
  player.getSprite()->move(
    player.direction.x * dt,0);
  collision.windowCheck(player, window);
}

void Game::render()
{
  window.draw(interface.main_text);
  window.draw(*player.getSprite());
}

void Game::keyPressed(sf::Event event)
{
  player.move(event);
  player.shoot(event);
}

void Game::keyReleased(sf::Event event)
{
  player.stop(event);
}
