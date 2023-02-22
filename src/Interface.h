#ifndef SPACEINVADERSSFML_INTERFACE_H
#define SPACEINVADERSSFML_INTERFACE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Interface
{
 public:
  Interface(sf::RenderWindow& game_window);
  ~Interface();
  bool initText();
  sf::Text main_text;
  sf::Text score;
 private:
  sf::RenderWindow& window;
  sf::Font font;

};

#endif // SPACEINVADERSSFML_INTERFACE_H
