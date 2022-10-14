#include <cmath>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <ostream>
#include <type_traits>

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

void print(const Vector &vec)
{
    std::cout << "(" << vec.getX() << " " << vec.getY() << " " << vec.getZ() << ")\n";
}

// std::ostream& operator<<(std::ostream &os, const Color& vec) {
//     return os << "(" << vec.() << " " << vec.getY() << " " << vec.getZ() << ")\n";
// }

// double clamp(double intensity)
// {
//     if (intensity > 1) return 1;
//     if (intensity < 0) return 0;
//     return intensity;
// }

void rayCasting(const Vector& light, const Color& lightColor, const Sphere& sphere, unsigned int* pixels) {
    for (size_t x = 0; x < nZemax::windowWidth; ++x)
    {
        for (size_t y = 0; y < nZemax::windowHeight; ++y) {
            // TODO: make this convertion member of color class
            //                                      order: A B G R
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

                 // double diffuse  = 0;
                 double diffuse  = clamp(cos);
                 double ambient  = 0.2;
                 // TODO: specular component
                 double specular = 0;

                 double intensity = clamp(diffuse + ambient + specular);

                 auto color = sphere.color() * lightColor;
                 color *= intensity;

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

    unsigned int *pixels = (unsigned int *) calloc(nZemax::windowWidth * nZemax::windowHeight, 4);
    if (pixels == nullptr) {
        fprintf(stderr, "nZemax: cannot allocate enough memory.\n");
        return EXIT_FAILURE;
    }

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
