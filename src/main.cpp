#include "csystem/coordinate_system.h"
#include "vector/vector.h"
#include "sphere/sphere.h"
#include "config.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

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

void print(const Vector &vec)
{
    std::cout << "(" << vec.x() << " " << vec.y() << " " << vec.z() << ")\n";
}

void rayCasting(const Vector &light, const Sphere &sphere, unsigned int *pixels) {
    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            //                                      A B G R
            pixels[y * nZemax::windowWidth + x] = 0x80808080;
        }
    }

    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            if (sphere.inside(Vector(x, y)))
            {
                 unsigned int color = 0xe16941;

                 double r  = sphere.radius();
                 double dx = sphere.origin().x() - x;
                 double dy = sphere.origin().y() - y;

                 double z = std::sqrt(r * r - dx * dx - dy * dy);

                 Vector point(x, y, z);

                 Vector normal  = sphere.normal(point);
                 Vector toLight = light - point;

                 double cos = normal.cos(toLight);
                 if (cos < 0) cos = 0;

                 unsigned int alpha = std::floor(0xFF * cos);

                 pixels[y * nZemax::windowWidth + x] = (alpha << 24) + color;
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(nZemax::windowWidth, nZemax::windowHeight), "This will be something incredible... one day...");

    Vector origin{nZemax::windowWidth / 2.f, nZemax::windowHeight / 2.f};
    CoordinateSystem cs{window, origin};
    Sphere sphere{nZemax::sphereRadius, origin};

    unsigned int *pixels = (unsigned int *) calloc(nZemax::windowWidth * nZemax::windowHeight, 4);
    if (pixels == nullptr) {
        fprintf(stderr, "nZemax: cannot allocate enough memory.\n");
        return EXIT_FAILURE;
    }

    Vector light{400, 100, 600};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        rayCasting(light, sphere, pixels);
        drawPixels(window, pixels);

        window.display();
   }

    return 0;
}
