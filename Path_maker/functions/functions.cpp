#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"
#include "../path/path.h"
#include "../graphical/graphical.h"


void menu()
{
    srand(time(NULL));
    char answ;

    std::cout << "G - graphical / C - Console / ";
    std::cout << "x - quit" << std::endl;

    while (answ != 'x')
    {
        std::cin >> answ;
        if (answ == 'G')
            graphical();

        else if (answ == 'C')
            console();

        std::cout << " " << std::endl;
    }
    std::cout << "Quitting... " << std::endl;
}

void console()
{

    int size_x, size_y;
    char answer;
    std::string name = "Generated/Path_00.png";

    std::cout << "Do you want to specify size of your image? (Y/N)" << std::endl;
    std::cin >> answer;

    if (answer == 'Y')
    {
        std::cout << "What width should your image be?" << std::endl;
        std::cin >> size_x;
        std::cout << "What height should your image be?" << std::endl;
        std::cin >> size_y;
    }
    else
    {
        size_x = 1024;
        size_y = 1024;
    }
    std::cout << "Do you want to generate more images? (Y/N)" << std::endl;
    std::cin >> answer;

    int How_many;

    if (answer == 'Y')
    {
        std::cout << "How many? ";
        std::cin >> How_many;
    }
    else
        How_many = 1;

    sf::Image logo;

    while (How_many)
    {
        logo.create(size_x, size_y, sf::Color::Black);
        logo.saveToFile(name);

        Path path_1(name);
        path_1.drawing_path();


        if (name[16] == '9')
        {
            name[15]++;
            name[16] = '0';
        }
        else
            name[16]++;

        How_many--;
    }
}
