#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "path.h"
#include "../functions/functions.h"


using namespace std;

void Path::set_variables(std::string n, std::string s)
{
    name = n;
    seed = s;

    logo.loadFromFile(name);

    int y = (int)seed[3];
    x = ((y*3)%11)+1;

    int r1 = (int)seed[0];
    int r2 = (int)seed[1];
    int r3 = (int)seed[2];
    r1 = ((r1*100) + (r2*10) + (r3));

    int g1 = (int)seed[3];
    int g2 = (int)seed[4];
    int g3 = (int)seed[5];
    g1 = ((g1*100) + (g2*10) + (g3));

    int b1 = (int)seed[6];
    int b2 = (int)seed[7];
    int b3 = (int)seed[8];
    b1 = ((b1*100) + (b2*10) + (b3));

    size_x = logo.getSize().x;
    size_y = logo.getSize().y;

    max_length = size_x * 3;

    if (size_x % 2 > 0)
        pixel_x = ((size_x - 1) / 2);
    else
        pixel_x = (size_x / 2);

    if (size_y % 2 > 0)
        pixel_y = ((size_y - 1) / 2);
    else
        pixel_y = (size_y / 2);

    color.r = r1 % 255;
    color.g = g1 % 255;
    color.b = b1 % 255;
}

void Path::seed_to_directions()
{
  directions.clear();
  int x;
  int now = 1;

  std::string this_seed = seed;

  int seed_size = (int)this_seed.size();
  for (int i = 0; i < seed_size; i++)
    {
      x = i;
      directions.push_back(this_seed[x]);
      now = (int)this_seed[i];
          directions.push_back(seed[i]);
          if (directions.size() > max_length)
           return;
    }
  directions_length = directions.size();
}

void Path::drawing_path()
{
    logo.loadFromFile(name);

    std::cout << "Generating: " << name << std::endl;

    for (int i = 0; i < directions_length; i++) // drawing
    {
        switch (directions[i])
        {
            case '1': // up
                pixel_y += x;
                break;

            case '2': // down
                pixel_y -= x;
                break;

            case '3': // left
                pixel_x -= x;
                break;

            case '4': // right
                pixel_x += x;
                break;
        }

        for (int i = 0; i < x; i++) // this paint x*x block
            for (int j = 0; j < x; j++)
                {
                  logo.setPixel(pixel_x + i, pixel_y + j, color);
                }
    }
    logo.saveToFile(name);
    std::cout << "Generated: " << name << std::endl; //logic error after that????
}
