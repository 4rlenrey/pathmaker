#include <SFML/Graphics.hpp>
#include <iostream>

class Graphically
{
public:
    sf::Color color;
    sf::RenderWindow window;

  void set_variables();
  void update(std::string n);

};
