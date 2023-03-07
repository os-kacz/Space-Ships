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
    (window.getSize().y - getSprite()->getGlobalBounds().height) - 45);
  getSprite()->setScale(0.5,0.5);

  for (auto & i : bullet)
  {
    i.initialiseSprite(
      bullet_texture,
      "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
    bullet_count++;
    i.visible = false;
  }

  initialiseSprite(player_texture,
    "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");

  return true;
}

void Player::update()
{
  if (collision.windowCheck(*this,window) == Collision::Type::LEFT)
  {
    getSprite()->setPosition(0,getSprite()->getPosition().y);
  }
  if (collision.windowCheck(*this,window) == Collision::Type::RIGHT)
  {
    getSprite()->setPosition(
      window.getSize().x - getSprite()->getGlobalBounds().width,
      getSprite()->getPosition().y);
  }
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
  if (event.key.code == sf::Keyboard::Space)
  {
    if (bullet_count > 0)
    {
      bullet_count--;
      bullet[bullet_count].visible = true;
      shot_elapsed_time = 0;
    }
  }
}

void Player::bulletUpdate(float dt)
{
  shot_elapsed_time += dt;
  if (shot_elapsed_time > 0.3)
  {
    bullet_count++;
    if (bullet_count > max_ammo)
    {
      bullet_count = max_ammo;
    }
    shot_elapsed_time = 0;
  }
  for (auto & i : bullet)
  {
    if (collision.windowCheck(i, window) == Collision::Type::TOP)
    {
      i.visible = false;
      bullet_count++;
    }
    if (!i.visible)
    {
      i.getSprite()->setPosition(
        getSprite()->getPosition().x, getSprite()->getPosition().y);
    }
    if (i.visible)
    {
      i.getSprite()->move(0,-10);
    }
  }
}