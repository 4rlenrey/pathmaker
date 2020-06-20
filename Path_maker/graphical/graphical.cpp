#include <SFML/Graphics.hpp>
#include <iostream>

void graphical()
{
    sf::RenderWindow window(sf::VideoMode(900, 800), "Path_Maker", sf::Style::Default);

    window.setActive(true);
    bool running = true;

     sf::Image image;
     if (!(image.loadFromFile("Generated/Path_00.png")))
             std::cout << "Cannot load image";   //Load Image

     sf::Texture texture;
     texture.loadFromImage(image);  //Load Texture from image

     sf::Sprite sprite;
     sprite.setTexture(texture);

    while (running)
    {
        sf::Event event;

        window.setVerticalSyncEnabled(true);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                running = false;
        }

               window.clear();
               window.draw(sprite);
               window.display();
    }
}
