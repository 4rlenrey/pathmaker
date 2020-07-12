#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "path.h"

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

    length = rand() % (size_x * 5);

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
  for (int i = 0; i < 20; i++)
  {
    x = i;
    directions.push_back(seed[i]);
    for (int j = 0; j < (int)seed[i]; j++)
      {
        if(x+1 > seed.size())
          x = 1;
        else if (x+2 > seed.size())
          x = 0;

        x = x + 2;

       directions.push_back(seed[x]);
       if (directions.size() >= 50)
          return;
      }
  }
}

void Path::drawing_path()
{
    logo.loadFromFile(name);

    std::cout << "Generating " << name << std::endl;

    for (int i = 0; i < directions.size(); i++) // drawing
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
                logo.setPixel(pixel_x + i, pixel_y + j, color);

    }

    logo.saveToFile(name);
}
