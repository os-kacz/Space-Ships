#include "Player.h"

Player::Player(sf::RenderWindow& game_window)
  : window(game_window)
{
  speed *= speed_multiplier;
}

Player::~Player()
{

}

void Player::initPlayer()
{
  initialiseSprite(texture,
    "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");
  getSprite()->setPosition(
    (window.getSize().x / 2) - getSprite()->getGlobalBounds().width,
    (window.getSize().y - getSprite()->getGlobalBounds().height) + 15);
  getSprite()->setScale(0.6,0.6);
}

void Player::move(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    direction.x = -1;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    direction.x = 1;
  }
  direction.x *= speed;
}

void Player::stop(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A && direction.x < 0)
  {
    direction.x = 0;
  }
  if (event.key.code == sf::Keyboard::D && direction.x > 0)
  {
    direction.x = 0;
  }
}

void Player::shoot(sf::Event& event)
{

}