
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) // theres gotta be a better way than 30 windows!!!!!
  : window(game_window), interface(window), player(window), alien{window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window, window}
{
  srand(time(nullptr));

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
  spawnAlien();
  return true;
}

void Game::update(float dt)
{
  if (gamestate == PLAYGAME)
  {
    interface.score.setString("Score: " + std::to_string(score));
    collision.windowCheck(player, window);
    player.getSprite()->move(
      player.direction.x * dt,0);

    player.update();
    player.bulletUpdate(dt);

    for (auto & falien : alien)
    {
      falien.update(dt);
      if (collision.gameobjectCheck(falien,player) && falien.visible)
      {
        gamestate = GAMELOSS;
      }
      for (auto & fbullet : player.bullet)
      {
        if (collision.gameobjectCheck(fbullet,falien)
            && falien.visible && fbullet.visible)
        {
          falien.visible = false;
          fbullet.visible = false;
          score++;
          if (score == (column*row))
          {
            gamestate = GAMEWIN;
            score = 0;
          }
        }
      }
    }
  }
  if (gamestate != PLAYGAME)
  {
    for (auto & falien : alien)
    {
      falien.visible = true;
    }
    spawnAlien();
    score = 0;
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
      window.draw(interface.score);
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
      interface.main_text.setString("You Lose :(");
      window.draw(interface.main_text);
      break;
    }
    case (GAMEWIN):
    {
      interface.main_text.setString("You Win!");
      window.draw(interface.main_text);
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
  if (gamestate != PLAYGAME)
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

void Game::spawnAlien()
{
  alien_grid = 0;
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < column; c++)
    {
      alien[c+alien_grid].getSprite()->setPosition(
        ((window.getSize().x / column) * c) + 20,25 + (r*70));
      alien[c+alien_grid].direction.x = 1 * alien->speed;
    }
    alien_grid += column;
  }
}