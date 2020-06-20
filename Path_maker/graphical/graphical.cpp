#include <SFML/Graphics.hpp>
#include <iostream>

void graphical()
{
    sf::Window window(sf::VideoMode(900, 800), "Path_Maker", sf::Style::Default);

    window.setActive(true);
    bool running = true;

    while (running)
    {
        sf::Event event;

        window.setVerticalSyncEnabled(true);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                running = false;
        }
    }
}
