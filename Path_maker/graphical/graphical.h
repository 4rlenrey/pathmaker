#include <SFML/Graphics.hpp>
#include <iostream>

class Graphically
{
public:
    sf::Color color;
    sf::RenderWindow window;
    sf::Image logo;


  void set_variables();
  void keepalive();
  void update(std::string n);

};
