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
    i.initialiseSprite(
      bullet_texture,
      "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
    bullet_count++;
    i.visible = false;
    std::cout << bullet_count << " bullet created\n";
  }

  initialiseSprite(player_texture,
    "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");

  return true;
}

void Player::move(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    direction.x = -1;
    direction.x *= speed;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    direction.x = 1;
    direction.x *= speed;
  }
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
  if (bullet_count >= 0)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      //bullet[bullet_count].getSprite()->setPosition((getSprite()->getPosition().x),50);
      bullet[bullet_count].visible = true;
      bullet_count--;
      std::cout << "spacebar registered\n";
      std::cout << bullet_count << std::endl;
    }
  }
}

void Player::bulletUpdate()
{
  for (auto & i : bullet)
  {
    if (!i.visible)
    {
      i.getSprite()->setPosition(
        getSprite()->getPosition().x,
        getSprite()->getPosition().y);
    }
    else
    {
      i.getSprite()->move(0,-25);
    }
  }
}