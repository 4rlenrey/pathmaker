#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphical.h"

void Graphically::set_variables()
{
    window.create(sf::VideoMode(800, 600), "My window");
}

void Graphically::update(std::string n)
{
  sf::Texture texture;
   if (!(texture.loadFromFile(n)))
           std::cout << "Cannot load image";

  sf::Sprite sprite;
  sprite.setTexture(texture);

  window.clear();
  window.draw(sprite);
  window.display();
}

void Graphically::keepalive()
{
  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }
        sf::sleep(sf::milliseconds(2000));
      Graphically::update("Generated/Path_00.png");

  }
}
