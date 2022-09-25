#pragma once

#include "../vector/vector.h"
#include <SFML/Graphics.hpp>

class CoordinateSystem
{
    Vector origin_;
    Vector e1_, e2_;
    sf::RenderWindow &window_;

public:
    CoordinateSystem(sf::RenderWindow &window):
        window_(window),
        origin_(),
        e1_(1, 0),
        e2_(0, 1)
    {}

    CoordinateSystem(sf::RenderWindow &window, Vector &origin):
        window_(window),
        origin_(origin),
        e1_(1, 0),
        e2_(0, 1)
    {}

    CoordinateSystem(sf::RenderWindow &window, Vector &origin, Vector &e1, Vector &e2):
        window_(window),
        origin_(origin),
        e1_(e1),
        e2_(e2)
    {}

    void draw(const Vector &vec, const sf::Color &color = sf::Color::Red) const;
};
