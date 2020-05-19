#include <SFML/Graphics.hpp>
#include "functions.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


void drawing_path(int size_x, int size_y, std::string name)
{
    sf::Image logo;
    logo.loadFromFile(name);

    sf::Color color;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;

    int x = rand() % 10; // i have no idea how to call this 'radius'?

    int length = rand() % (size_x * 5);
    int more_random = (rand() % 8) + 1;
    int direction = (((rand() % 8) + 1) + more_random) / 2;
    int pixel_x = (size_x / 2), pixel_y = (size_y / 2);

    for (int i = 0; i < length; i++) // drawing
    {

        switch (direction)
        {
            case 1: // up
                pixel_y += x;
                break;

            case 2: // down
                pixel_y -= x;
                break;

            case 3: // left
                pixel_x -= x;
                break;

            case 4: // right
                pixel_x += x;
                break;
        }

        for (int i = 0; i < x; i++) //this paint x*x block
            for (int j = 0; j < x; j++)
                logo.setPixel(pixel_x + i, pixel_y + j, color);


        direction = (rand() % 8) + 1;
    }
    std::cout << "Generating " << name << std::endl;
    logo.saveToFile(name);
}
