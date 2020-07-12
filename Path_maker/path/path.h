#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Path
{
private:
    std::vector<char> directions;
    std::string name;
    sf::Image logo;
    std::string seed;
    sf::Color color;

    int length;
    int pixel_x, pixel_y;
    int size_x, size_y;
    int direction;
    int x; // something like radius

public:
    Path(std::string n, std::string s) // constructor
    {
        set_variables(n, s); //"n" is a name of the file and "s" is a seed
    }

    void set_variables(std::string n, std::string s);
    void seed_to_directions();
    void drawing_path();
};
