#include <SFML/Graphics.hpp>
#include <iostream>
#include "functions.h"

int main()
{
 int length;
 int size_x, size_y;
 char answer;
 std::string name = "Wzor_nr0.png";


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
   	size_x = 500;
   	size_y = 500;
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

      std::cout << "How big should your path be?" << std::endl;
      std::cin >> length;

 while (How_many)
 {
    name[7]++;
    drawing_path(size_x, size_y, length, name);
    How_many--;
 }
    return 0;
}
