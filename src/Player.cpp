#include "Player.h"

Player::Player(sf::RenderWindow& game_window) : window(game_window)
{
  speed *= speed_multiplier;
}

Player::~Player()
{

}

bool Player::initPlayer()
{
  getSprite()->setPosition(
    (window.getSize().x / 2) - getSprite()->getGlobalBounds().width,
    (window.getSize().y - getSprite()->getGlobalBounds().height) + 15);
  getSprite()->setScale(0.5,0.5);

  for (auto & i : bullet)
  {
    i.initialiseSprite(bullet_texture,
   "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
    bullet_off_screen++;
  }

  return initialiseSprite(player_texture,
    "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");
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
  if (event.key.code == sf::Keyboard::Space)
  {
    if (bullet_off_screen > 0)
    {
      bullet[bullet_off_screen].getSprite()->setPosition(
        getSprite()->getPosition().x +
          (getSprite()->getGlobalBounds().width / 2),
        getSprite()->getPosition().y);
      bullet_off_screen--;
    }
  }
}
