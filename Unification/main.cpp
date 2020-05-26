#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
  int r, g, b;
  int r2, g2, b2;
  sf::Image image;
  sf::Color changed_color;

  int compare = 2;
  int change = 5;

  image.loadFromFile("/input/image.png");

  int size_x = image.getSize().x;
  int size_y = image.getSize().y;


int x = 0;

for(int j = 0; j < size_y; j = j + compare)
{
  for(int i = 0; i < size_x; i = i + compare)
  {


    r = 0; g = 0; b = 0;
    for(int z = 0; j < compare; z++)
    {
    r = r + image.getPixel(i, j).r;
    g = g + image.getPixel(i, j).g;
    b = b + image.getPixel(i, j).b;
    }

    r /= compare;
    g /= compare;
    b /= compare;

    for(int z = 0; j < compare; z++)
    {

      r2 = r + image.getPixel(i, j).r;
      g2 = g + image.getPixel(i, j).g;
      b2 = b + image.getPixel(i, j).b;

      if(r2 < r || r2 == r)
       r2 += change;
      if(r2 > r)
       r2 += change;

      if(r2 >= 255)
         r2 = 255;
      if(r2 <= 0)
         r2 = 0;

         if(g2 < g || g2 == g)
          g2 += change;
         if(g2 > g)
          g2 += change;

         if(g2 >= 255)
            g2 = 255;
         if(g2 <= 0)
            g2 = 0;


      changed_color.r = r2;
      changed_color.g = g2;
      changed_color.b = b2;

      image.setPixel(changed_color);

    }

      image.setPixel(i, j )






  }
}

  //TO DO: petla unormowywująca kolory czy cos



  return 0;
}
