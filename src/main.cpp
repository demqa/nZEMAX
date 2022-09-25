#include "csystem/coordinate_system.h"
#include "vector/vector.h"
#include "sphere/sphere.h"
#include "config.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

void drawPixels(sf::RenderWindow &window, const unsigned int *pixels)
{
    sf::Image     image;
    sf::Sprite   sprite;
    sf::Texture texture;

    image.create(nZemax::windowWidth, nZemax::windowHeight, (unsigned char *) pixels);
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    window.draw(sprite);
}

void rayCasting(const Sphere &sphere, unsigned int *pixels) {
    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            //                                       A B G R
            pixels[y * nZemax::windowWidth + x] = 0xFF808080;
        }
    }

    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            if (sphere.inside(Vector(x, y)))
                pixels[y * nZemax::windowWidth + x] = 0xFFFFFFFF;
        }
    }
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(nZemax::windowWidth, nZemax::windowHeight), "This will be something incredible... one day...");

    Vector origin{nZemax::windowWidth / 2.f, nZemax::windowHeight / 2.f};
    CoordinateSystem cs{window, origin};
    Sphere sphere{100, origin};

    unsigned int *pixels = (unsigned int *) calloc(nZemax::windowWidth * nZemax::windowHeight, 4);
    if (pixels == nullptr) {
        fprintf(stderr, "nZemax: cannot allocate enough memory.\n");
        return EXIT_FAILURE;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        rayCasting(sphere, pixels);
        drawPixels(window, pixels);

        window.display();
   }

    return 0;
}
