#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphical.h"

void Graphically::set_variables()
{
    window.create(sf::VideoMode(800, 600), "My window");
    window.isOpen();
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
