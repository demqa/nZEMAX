#include <cmath>
#include <cstdlib>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <new>

#include "config.h"
#include "coordinate_system.h"
#include "vector.h"
#include "sphere.h"
#include "color.h"

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

std::ostream& operator<<(std::ostream &os, const Vector& vec) {
    return os << "(" << vec.getX() << " " << vec.getY() << " " << vec.getZ() << ")\n";
}

void rayCasting(const Vector& light, const Color& lightColor, const Sphere& sphere, unsigned int* pixels) {
    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            // TODO: make this convertion member of color class
            //                                      order: A B G R
            //  HAHA I use that grey RGB == BGR HAHHAHAHHAHA
            pixels[y * nZemax::windowWidth + x] = (0xFFu << 24) + (unsigned int) nZemax::Colors::grey;
        }
    }

    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            if (sphere.inside(Vector(x, y)))
            {
                 double r  = sphere.radius();
                 double dx = sphere.origin().getX() - x;
                 double dy = sphere.origin().getY() - y;

                 double z = std::sqrt(r * r - dx * dx - dy * dy);

                 Vector point(x, y, z);

                 Vector normal  = sphere.normal(point);
                 Vector toLight = light - point;

                 double cos = normal.cos(toLight);

                 Vector reflected = (normal * 2 * cos) - toLight;

                 double reflCos  = normal.cos(reflected);

                 double diffuse  = clamp(cos);
                 double ambient  = 0.2;
                 double specular = std::pow(clamp(reflCos), 25);

                 Color spec = Color(lightColor) * specular;

                 Color color = sphere.color() * lightColor;
                 color *= (diffuse + ambient);

                 color += spec;

                 color.clamp();

                 pixels[y * nZemax::windowWidth + x] = color.RGBAcolor();
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(nZemax::windowWidth, nZemax::windowHeight), "This will be something incredible... one day...");

    Vector origin{nZemax::windowWidth / 2.f, nZemax::windowHeight / 2.f};
    // CoordinateSystem cs{window, origin};
    Sphere sphere{nZemax::sphereRadius, Color(nZemax::Colors::cherry), origin};

    unsigned int pixels[nZemax::windowWidth * nZemax::windowHeight];

    // TODO: maybe one day it will be nice to allocate it in heap.
    // unsigned int *pixels = nullptr;
    // try {
    //     pixels = new unsigned int [nZemax::windowWidth * nZemax::windowHeight];
    // }
    // catch (std::bad_alloc) {
    //     fprintf(stderr, "nZemax: cannot allocate enough memory.\n");
    //     return EXIT_FAILURE;
    // }
    //
    // delete [] pixels;

    // TODO: make it another class Light.
    Vector light{100, 100, 300};
    Color lightColor(nZemax::Colors::white);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        rayCasting(light, lightColor, sphere, pixels);
        drawPixels(window, pixels);

        window.display();
    }

    return 0;
}
