
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
  if (!player.initPlayer() || !interface.initText())
    // for alien pass window through function, not class init

    for (auto & i : alien)
    {
      alien->initAlien(window);
    }



    return false;
  return true;
}

void Game::update(float dt)
{
  if (gamestate == PLAYGAME)
  {
    player.getSprite()->move(
      player.direction.x * dt,0);
    collision.windowCheck(player, window);
    player.bulletUpdate(dt);
  }
}

void Game::render()
{
  switch(gamestate)
  {
    case (MAINMENU):
    {
      window.draw(interface.main_text);
      break;
    }
    case (PLAYGAME):
    {
      window.draw(*player.getSprite());
      for (auto & i : player.bullet)
      {
        if (i.visible)
        {
          window.draw(*i.getSprite());
        }
      }
      break;
    }
    case (GAMELOSS):
    {
      break;
    }
    case (GAMEWIN):
    {
      break;
    }
    default:
    {
      break;
    }
  }
}

void Game::keyPressed(sf::Event event)
{
  if (gamestate == PLAYGAME)
  {
    player.move(event);
    player.shoot(event);
  }
  if (gamestate == MAINMENU)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      gamestate = PLAYGAME;
    }
  }
}

void Game::keyReleased(sf::Event event)
{
  if (gamestate == PLAYGAME)
  {
    player.stop(event);
  }
}
