#include "Interface.h"

Interface::Interface(sf::RenderWindow& game_window) : window(game_window)
{

}

Interface::~Interface()
{

}

bool Interface::initText()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Could not load font\n";
    return false;
  }

  main_text.setString("Press Enter to play Space Invaders");
  main_text.setFont(font);
  main_text.setCharacterSize(60);
  main_text.setFillColor(sf::Color::White);
  main_text.setPosition(
    (window.getSize().x / 2) - (main_text.getGlobalBounds().width / 2),
    (window.getSize().y / 2) - (main_text.getGlobalBounds().height / 2));

  score.setString("Score: 0");
  score.setFont(font);
  score.setCharacterSize(65);
  score.setFillColor(sf::Color::White);
  score.setPosition(
    (window.getSize().x / 2) - (main_text.getGlobalBounds().width / 2),
    (window.getSize().y / 2) - (main_text.getGlobalBounds().height / 2));

  return true;
}
