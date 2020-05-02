#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
 srand(time(NULL));

 int size_x, size_y;
 int jakadlugosc;
 char odp;
 std::string nazwa = "Wzor_nr0.png";

 std::cout << "Czy chcesz okreslic rozmiar obrazu? (T/N)" << std::endl;
 std::cin >> odp;

 if (odp == 'T')
 {
 std::cout << "Jaki chcesz rozmiar x twojego obrazu?" << std::endl;
 std::cin >> size_x;
 std::cout << "Jaki chcesz rozmiar y twojego obrazu?" << std::endl; 
 std::cin >> size_y;
 }
   else 
   {
   	size_x = 500;
   	size_y = 500;
   }

 std::cout << "Jak dlugi ma byc twoj wonsz?" << std::endl;
 std::cin >> jakadlugosc;



 std::cout << "Czy chcesz wygenerowac wiecej wenszy? (T/N)" << std::endl;
 std::cin >> odp;

 int ile;
 
 if (odp == 'T')
     {
      std::cout << "Ile? ";
      std::cin >> ile;
     }
     else 
      ile = 1;
          
 std::cout << "Generuje wensze :D" << std::endl;

 int kierunek = (rand() % 8) +1; 

  int pixel_x = (size_x/2), pixel_y = (size_y/2);

 while (ile)
 {
  nazwa[7]++;
  
  sf::Image logo;
  
   logo.create(size_x, size_y, sf::Color::Black);

 for (int i = 0; i < jakadlugosc; i++)  //rysowanie
  {

   switch (kierunek)
   {
   	case 1: //gora
    pixel_y++;
    pixel_y++;
   	break;

   	case 2: //dol
   	pixel_y--;
    pixel_y--;
   	break;

   	case 3: //lewo
   	pixel_x--;
   	pixel_x--;
   	break;

	case 4: //prawo
   	pixel_x--;
    pixel_x--; 	   	
   	break;

   	case 5: //gora lewo
    pixel_y++;  
   	pixel_x--;
   	break;

   	case 6: //gora prawo
  	pixel_y++;  
   	pixel_x++;   	   	   	
   	break;

   	case 7: //dol lewo
   	pixel_y--;
   	pixel_x--;
   	break;

   	case 8: //dol prawo
   	pixel_y--;
   	pixel_x++;   	   	   	
   	break;
   }

  
   logo.setPixel(pixel_x, pixel_y, sf::Color::Green);       // to jest jakby kolorowalo kostke 2x2 pixele
   logo.setPixel(pixel_x + 1, pixel_y, sf::Color::Green);
   logo.setPixel(pixel_x, pixel_y + 1, sf::Color::Green);
   logo.setPixel(pixel_x + 1, pixel_y + 1, sf::Color::Green);
 
   kierunek = (rand() % 8) +1;
   
 }
 
 
logo.saveToFile(nazwa);

 ile--;
}
    return 0;
}
//g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
