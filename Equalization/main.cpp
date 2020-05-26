//In progress!

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
  int r, g, b;
  int r2, g2, b2;
  sf::Image image;
  sf::Color changed_color;

  int compare = 1;
  int change = 1;

  cout << "Insert how many pixels needs to be compared in iteration\n";
  cin >> compare;
  cout << "Insert how much you want to change these pixels\n";
  cin >> change;

  image.loadFromFile("Input/image.png");

  int size_x = image.getSize().x;
  int size_y = image.getSize().y;


int x = 0;

for(int j = 1; j < size_y; j++)
{

  for(int i = 1; i < size_x; i = i + compare)
  {

    r = 0; g = 0; b = 0;
    r2 = 0; g2 = 0; b2 = 0;


    for(int z = 1; z < compare; z++)
    {
    r = r + image.getPixel(z, j).r;
    g = g + image.getPixel(z, j).g;
    b = b + image.getPixel(z, j).b;
    }
    cout << r<<" " << g <<" " << b << endl;

    r /= compare;
    g /= compare;
    b /= compare;
    cout << r<<" " << g <<" " << b << endl;

    for(int z = 0; z < compare; z++)
    {

      r2 = r + image.getPixel(z, j).r;
      g2 = g + image.getPixel(z, j).g;
      b2 = b + image.getPixel(z, j).b;

      if(r2 < r || r2 == r)
       r2 += change;
      if(r2 > r)
       r2 += change;

      if(r2 > 255)
         r2 = 255;
      if(r2 < 0)
         r2 = 0;

         if(g2 < g || g2 == g)
          g2 += change;
         if(g2 > g)
          g2 += change;

         if(g2 > 255)
            g2 = 255;
         if(g2 < 0)
            g2 = 0;

            if(b2 < b || b2 == b)
             b2 += change;
            if(b2 > b)
             b2 += change;

            if(b2 > 255)
               b2 = 255;
            if(b2 < 0)
               b2 = 0;


      changed_color.r = r2;
      changed_color.g = g2;
      changed_color.b = b2;


      image.setPixel(z, j, changed_color);

    }


  }
}

image.saveToFile("output/image.png");



  return 0;
}
