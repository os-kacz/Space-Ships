
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) // theres gotta be a better way than 30 windows!!!!!
  : window(game_window), interface(window), player(window)
{
  srand(time(nullptr));
  //paul said i can put a for loop in here for the alien{window} initialisation but idk how :(
}

Game::~Game()
{

}

bool Game::init()
{
  gamestate = MAINMENU;
  if (!player.initPlayer() || !interface.initText())
    return false;

  for (auto & _alien : alien)
  {
    _alien.initAlien(window);
  }
  return true;
}

void Game::update(float dt)
{
  if (gamestate == PLAYGAME)
  {
    interface.score.setString("Score: " + std::to_string(score));
    interface.shot_count.setString("Shots: " + std::to_string(
                                                 player.bullet_count));

    collision.windowCheck(player, window);
    player.getSprite()->move(
      player.direction.x * dt,0);

    player.update();
    player.bulletUpdate(dt);

    for (auto & _alien : alien)
    {
      if (pattern_choice == 1)
        _alien.pattern = Alien::STRAIGHT;
      if (pattern_choice == 2)
        _alien.pattern = Alien::GRAVITY;
      if (pattern_choice == 3)
        _alien.pattern = Alien::QUADRATIC;
      if (pattern_choice == 4)
        _alien.pattern = Alien::SINE;

      _alien.update(dt);
      if (collision.gameobjectCheck(_alien,player) && _alien.visible
          || collision.windowCheck(_alien, window)
                 == Collision::Type::BOTTOM && _alien.visible)
      {
        gamestate = GAMELOSS;
      }
      for (auto & _bullet : player.bullet)
      {
        if (collision.gameobjectCheck(_bullet, _alien)
            && _alien.visible && _bullet.visible)
        {
          _alien.visible = false;
          _bullet.visible = false;
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
    for (auto & _alien : alien)
    {
      _alien.step = 0;
      _alien.direction.x = 1;
      _alien.visible = true;
    }
    for (auto & _bullet : player.bullet)
    {
      _bullet.visible = false;
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
      interface.main_text.setString("Press Enter to play Space Invaders");
      window.draw(interface.main_text);
      break;
    }
    case (OPTIONS):
    {
      interface.main_text.setString("Choose Alien Pattern");
      interface.shot_count.setString("1. Straight\n2. Gravity\n3. Quadratic\n4. Sine Wave");
      window.draw(interface.main_text);
      window.draw(interface.shot_count);
      break;
    }
    case (PLAYGAME):
    {
      window.draw(*player.getSprite());
      window.draw(interface.score);
      window.draw(interface.shot_count);
      for (auto & _bullet : player.bullet)
      {
        if (_bullet.visible)
        {
          window.draw(*_bullet.getSprite());
        }
      }
      for (auto & _alien : alien)
      {
        if (_alien.visible)
        {
          window.draw(*_alien.getSprite());
        }
      }
      break;
    }
    case (GAMELOSS):
    {
      interface.main_text.setString("You Lose :(");
      interface.shot_count.setString("ENTER to play again\nESC to Main Menu");
      window.draw(interface.main_text);
      window.draw(interface.shot_count);
      break;
    }
    case (GAMEWIN):
    {
      interface.main_text.setString("You Win!");
      interface.shot_count.setString("ENTER to play again\nESC to Main Menu");
      window.draw(interface.main_text);
      window.draw(interface.shot_count);
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
  if (gamestate == MAINMENU)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      gamestate = OPTIONS;
    }
    if (event.key.code == sf::Keyboard::Escape)
    {
      window.close();
    }
  }
  if (gamestate == OPTIONS)
  {
    if (event.key.code == sf::Keyboard::Num1)
    {
      pattern_choice = 1;
      gamestate = PLAYGAME;
    }
    if (event.key.code == sf::Keyboard::Num2)
    {
      pattern_choice = 2;
      gamestate = PLAYGAME;
    }
    if (event.key.code == sf::Keyboard::Num3)
    {
      pattern_choice = 3;
      gamestate = PLAYGAME;
    }
    if (event.key.code == sf::Keyboard::Num4)
    {
      pattern_choice = 4;
      gamestate = PLAYGAME;
    }
  }
  if (gamestate == PLAYGAME)
  {
    player.move(event);
    player.shoot(event);
    if (event.key.code == sf::Keyboard::Escape)
    {
      gamestate = MAINMENU;
    }
  }
  if (gamestate == GAMEWIN || gamestate == GAMELOSS)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      gamestate = PLAYGAME;
    }
    if (event.key.code == sf::Keyboard::Escape)
    {
      gamestate = MAINMENU;
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
      alien[c+alien_grid].initial_pos =
        alien[c+alien_grid].getSprite()->getPosition().y;
    }
    alien_grid += column;
  }
}