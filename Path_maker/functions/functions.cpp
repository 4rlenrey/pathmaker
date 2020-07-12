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

void generating_seed(int how_many_seeds)
{
    fstream file;
    file.open("Seeds/seeds.txt", ios::out | ios::trunc);

    int number;

    if (file.is_open())
    {
        while (how_many_seeds) // 1 seed per iteration
        {
              for (int i = 0; i < 20; i++)
              {
                  number = (rand() % 4) + 1;
                  file << number;
              }
              file << "\n"; // end of the seed
              how_many_seeds--;
        }
        file.close();
    }
    else
        cout << "Can't open the file" << endl;
}

void Path_Image::seed_to_class()
{
  fstream file("Seeds/seeds.txt");
  string line;
  generating_seed(how_many_images);

  if (file.is_open())
  {
    for (int i = 0; i < how_many_images; i++)
    {
              getline(file, line);
              seeds.push_back(line); //storing all the seeds in a vector
              break;
    }

      file.close();
  }
  else
      cout << "Can't open the file" << endl;
}

void Path_Image::generate_images()
{
  size_x = 1024;
  size_y = 1024;

  sf::Image logo;

  for(int i = 0; i < how_many_images; i++)
    {
              logo.create(size_x, size_y, sf::Color::Black);
              logo.saveToFile(name);

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

    }
}

void menu()
{
  srand(time(NULL));

  cout << "generating program v 0.001" << "\n";
  Path_Image generation;
  generation.seed_to_class();
  generation.generate_images();

}

void test()
{
    char answ;
    //generating_seed();
    //reading_seed();
    Path_Image immage;

    sf::Image logo;
    logo.create(1000, 1000, sf::Color::Black);
    logo.saveToFile("Generated/Path_00.png");

    Path path_1("Generated/Path_00.png", "14143223343221213133");
    path_1.seed_to_directions();
    path_1.drawing_path();
/*
    std::cout << "G - graphical / C - Console / ";
    std::cout << "x - quit" << std::endl;

    while (answ != 'x')
    {
        std::cin >> answ;
        if (answ == 'G')
        {
            thread windowt(ifwindow);
            thread tconsole(console);

            windowt.join();
            tconsole.join();
        }

        else if (answ == 'C')

            console();

        std::cout << " " << std::endl;
    }
*/
    std::cout << "Quitting... " << std::endl;
}

void ifwindow()
{

    Graphically window1;
    window1.set_variables();
    window1.update("Generated/Path_00.png");
    window1.keepalive();
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
    std::string seed; //!!!!!TO DO

    while (How_many)
    {
        logo.create(size_x, size_y, sf::Color::Black);
        logo.saveToFile(name);

        Path path_1(name, "14143223343221213133");
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
