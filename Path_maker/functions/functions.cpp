#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <fstream>
#include "functions.h"
#include "../path/path.h"
#include "../graphical/graphical.h"

using namespace std;

void Path_Image::generating_seed()
{
    ofstream file;
    file.open("Seeds/seeds.txt", ios::out | ios::trunc);

    int number;

    if (file.is_open())
    {
      for (int j = 0; j < how_many_images; j++)
      {
       for (int i = 0; i < 20; i++)
        {
            number = (rand() % 4) + 1;
            file << number;
        }
        file << "\n"; // end of the seed
      }
      file.close();
    }
    else
        cout << "Can't open the file" << "\n";
}

void Path_Image::seed_to_class()
{
    ifstream file("Seeds/seeds.txt");
    string line;

    if (file.is_open())
    {
        for (int i = 0; i < how_many_images; i++)
        {
            getline(file, line);
            seeds.push_back(line); // storing all seeds in a vector
        }
        file.close();
    }
    else
        cout << "Can't open the file" << "\n";
}

void Path_Image::generate_images()
{
    name = "Generated/Path_00.png";
    size_x = 1024;
    size_y = 1024;

    cout << "Generating " << how_many_images << " images" << "\n";

    generating_seed(); //generate random seeds to .txt file
    seed_to_class(); //add these seeds to a seeds array

    for (int i = 0; i < how_many_images; i++) //one image generated per iteration
    {

        logo.create(size_x, size_y, sf::Color::Black);
        logo.saveToFile(name);
        cout << "=============================================" << "\n";
        cout << "NAME: " << name << "\n";
        cout << "SEED: " << seeds[i] << "\n";

        Path path_1(name, seeds[i]);
        path_1.seed_to_directions();
        path_1.drawing_path();

        if (name[16] == '9')
        {
            name[15]++;
            name[16] = '0';
        }
        else
            name[16]++;

        cout << "=============================================" << "\n";
    }
}

void menu()
{
    srand(time(NULL));

    cout << "generating program v 0.001" << "\n";
    Path_Image generation;
    generation.generate_images();
    cout << "Quitting" << "\n";
}
