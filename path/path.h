#include <SFML/Graphics.hpp>
#include <iostream>

class Path
{
 private:

   std::string name;
   sf::Image logo;
   sf::Color color;

   int length;
   int pixel_x, pixel_y;
   int size_x, size_y;
   int direction;
   int x;

  public:
    void set_variables(std::string n);
    void drawing_path();

};
