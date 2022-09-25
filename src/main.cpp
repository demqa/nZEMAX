#include "csystem/coordinate_system.h"
#include "vector/vector.h"
#include "sphere/sphere.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "This will be something incredible... one day...");

    Vector origin(200, 200);
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

        window.display();
   }

    return 0;
}
