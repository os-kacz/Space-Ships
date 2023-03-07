
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) // theres gotta be a better way than 30 windows!!!!!
  : window(game_window), interface(window), player(window), alien{window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window}
{
  srand(time(NULL));

}

Game::~Game()
{

}

bool Game::init()
{
  gamestate = MAINMENU;
  if (!player.initPlayer() || !interface.initText())
    return false;

  for (auto & i : alien)
  {
    i.initAlien();
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < column; c++)
    {
      alien[c+alien_grid].getSprite()->setPosition(
        ((window.getSize().x / column) * c) + 20,25 + (r*70));
    }
    alien_grid += column;
  }
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
      for (auto & j : alien)
      {
        if (j.visible)
        {
          window.draw(*j.getSprite());
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
