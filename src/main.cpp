#include <iostream>
#include "csystem/coordinate_system.h"
#include "vector/vector.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "This will be something incredible... one day...");

    const double omega = 0.01;
    const double radius = 100;
    double t = 0, delta_t = 0.01;

    vector_t origin(200, 200);
    vector_t pupa(100, 100);
    coordinate_system_t cs{window, origin};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        pupa.set_x(radius * cos(omega * t));
        pupa.set_y(radius * sin(omega * t));
        cs.draw(pupa);

        t += delta_t;

        window.display();
   }

    return 0;
}
