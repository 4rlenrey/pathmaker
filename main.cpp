#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
 srand(time(NULL));

 int size_x, size_y;
 int length;
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

 std::cout << "How big should your path be?" << std::endl;
 std::cin >> length;



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
          
 std::cout << "Generating paths :D" << std::endl;

 int direction = (rand() % 8) +1; 

  int pixel_x = (size_x/2), pixel_y = (size_y/2);

 while (How_many)
 {
  name[7]++;
  
  sf::Image logo;
  
   logo.create(size_x, size_y, sf::Color::Black);

 for (int i = 0; i < length; i++)  //drawing
  {

   switch (direction)
   {
   	case 1: //up
    pixel_y++;
    pixel_y++;
   	break;

   	case 2: //down
   	pixel_y--;
    pixel_y--;
   	break;

   	case 3: //left
   	pixel_x--;
   	pixel_x--;
   	break;

	case 4: //right
   	pixel_x--;
    pixel_x--; 	   	
   	break;

   	case 5: //up, left
    pixel_y++;  
   	pixel_x--;
   	break;

   	case 6: //up, right
  	pixel_y++;  
   	pixel_x++;   	   	   	
   	break;

   	case 7: //down, left
   	pixel_y--;
   	pixel_x--;
   	break;

   	case 8: //down, right
   	pixel_y--;
   	pixel_x++;   	   	   	
   	break;
   }

  
   logo.setPixel(pixel_x, pixel_y, sf::Color::Green);       // This part paints 2x2 pixel "block"
   logo.setPixel(pixel_x + 1, pixel_y, sf::Color::Green);
   logo.setPixel(pixel_x, pixel_y + 1, sf::Color::Green);
   logo.setPixel(pixel_x + 1, pixel_y + 1, sf::Color::Green);
 
   direction = (rand() % 8) +1;
   
 }
 
 
logo.saveToFile(name);

 How_many--;
}
    return 0;
}
