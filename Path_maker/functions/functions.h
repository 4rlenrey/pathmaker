#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef FUNCT
#define FUNCT

class Path_Image
{
  private:
    sf::Image logo;
    std::vector <std::string> seeds;
    std::string name;
    int size_x, size_y;
    char answer;
    int how_many_images = 10;


  public:
    void generating_seed();
    void seed_to_class();
    void generate_images();
};

void menu();

#endif
