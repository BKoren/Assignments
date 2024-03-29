#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
    window.setFramerateLimit(60);

    Cvijet cvijet(&window);
    cvijet.set_size(100);
    cvijet.set_thickness_size(10);
    cvijet.set_position(300.0, 240.0);
    cvijet.set_radius(150);
    cvijet.set_angle(0);
    //cvijet.generate();

    sf::Clock clock; 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        cvijet.set_color();
        cvijet.set_bool();
        cvijet.set_thickness_bool();
        cvijet.adjust_size();
        cvijet.adjust_thickness();

        window.clear();
        cvijet.animate(clock, window);
        window.display();
    }

    return 0;
}
