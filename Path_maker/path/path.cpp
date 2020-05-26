#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "path.h"

void Path::set_variables(std::string n)
{
    name = n;

    logo.loadFromFile(name);

    x = rand() % 10;

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

    direction = (rand() % 8) + 1;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
}


void Path::drawing_path()
{
    logo.loadFromFile(name);

    std::cout << "Generating " << name << std::endl;

    for (int i = 0; i < length; i++) // drawing
    {

        switch (direction)
        {
            case 1: // up
                pixel_y += x;
                return;

            case 2: // down
                pixel_y -= x;
                return;

            case 3: // left
                pixel_x -= x;
                return;

            case 4: // right
                pixel_x += x;
                return;
        }

        for (int i = 0; i < x; i++) // this paint x*x block
            for (int j = 0; j < x; j++)
                logo.setPixel(pixel_x + i, pixel_y + j, color);


        direction = (rand() % 8) + 1;
    }

    logo.saveToFile(name);
}
