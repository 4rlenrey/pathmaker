#include <SFML/Graphics.hpp>
#include "functions.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


void drawing_path(int size_x, int size_y, int length, std::string name)
{
    srand(time(NULL));
    sf::Image logo;
    logo.loadFromFile(name);

    int more_random = (rand() % 8) + 1;
    int direction = (((rand() % 8) + 1) + more_random)/2;
    int pixel_x = (size_x / 2), pixel_y = (size_y / 2);

    for (int i = 0; i < length; i++) // drawing
    {

        switch (direction)
        {
            case 1: // up
                pixel_y++;
                pixel_y++;
                break;

            case 2: // down
                pixel_y--;
                pixel_y--;
                break;

            case 3: // left
                pixel_x--;
                pixel_x--;
                break;

            case 4: // right
                pixel_x--;
                pixel_x--;
                break;

            case 5: // up, left
                pixel_y++;
                pixel_x--;
                break;

            case 6: // up, right
                pixel_y++;
                pixel_x++;
                break;

            case 7: // down, left
                pixel_y--;
                pixel_x--;
                break;

            case 8: // down, right
                pixel_y--;
                pixel_x++;
                break;
        }


        logo.setPixel(pixel_x, pixel_y, sf::Color::Green); // This part paints 2x2 pixel "block"
        logo.setPixel(pixel_x + 1, pixel_y, sf::Color::Green);
        logo.setPixel(pixel_x, pixel_y + 1, sf::Color::Green);
        logo.setPixel(pixel_x + 1, pixel_y + 1, sf::Color::Green);

        direction = (rand() % 8) + 1;
    }
    std::cout << "Generating path :D" << std::endl;
    logo.saveToFile(name);
}
