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

double clamp(double intensity)
{
    if (intensity > 1) return 1;
    if (intensity < 0) return 0;
    return intensity;
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
                 unsigned int sphereColor = nZemax::royalBlue;

                 double r  = sphere.radius();
                 double dx = sphere.origin().x() - x;
                 double dy = sphere.origin().y() - y;

                 double z = std::sqrt(r * r - dx * dx - dy * dy);

                 Vector point(x, y, z);

                 Vector normal  = sphere.normal(point);
                 Vector toLight = light - point;

                 double cos = normal.cos(toLight);
                 double diffuse  = clamp(cos);
                 double ambient  = clamp(1);
                 // double specular = 0;

                 double intensity = clamp(diffuse * 0.9 + ambient * 0.1);

                 unsigned int alpha = std::floor(0xFF * intensity);

                 pixels[y * nZemax::windowWidth + x] = (alpha << 24) + sphereColor;
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(nZemax::windowWidth, nZemax::windowHeight), "This will be something incredible... one day...");

    Vector origin{nZemax::windowWidth / 2.f, nZemax::windowHeight / 2.f};
    CoordinateSystem cs{window, origin};
    Sphere sphere{nZemax::sphereRadius, origin + Vector(100)};

    unsigned int *pixels = (unsigned int *) calloc(nZemax::windowWidth * nZemax::windowHeight, 4);
    if (pixels == nullptr) {
        fprintf(stderr, "nZemax: cannot allocate enough memory.\n");
        return EXIT_FAILURE;
    }

    Vector light{100, 100, 300};

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
