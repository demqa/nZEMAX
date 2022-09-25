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
    double t = 0, deltaT = 0.01;

    Vector origin(200, 200);
    Vector pupa(100, 100);
    CoordinateSystem cs{window, origin};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        pupa.setX(radius * cos(omega * t));
        pupa.setY(radius * sin(omega * t));
        cs.draw(pupa);

        t += deltaT;

        window.display();
   }

    return 0;
}
