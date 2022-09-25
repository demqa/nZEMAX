#pragma once

#include "../vector/vector.h"
#include <SFML/Graphics.hpp>

class CoordinateSystem
{
    Vector origin_;
    Vector e1_{1, 0, 0}, e2_{0, 1, 0}, e3_{0, 0, 1};
    sf::RenderWindow &window_;

public:
    const Vector& e1() const;
    const Vector& e2() const;
    const Vector& e3() const;

    CoordinateSystem(sf::RenderWindow &window):
        window_(window),
        origin_()
    {}

    CoordinateSystem(sf::RenderWindow &window, Vector &origin):
        window_(window),
        origin_(origin)
    {}

    void draw(const Vector &vec, const sf::Color &color = sf::Color::Red) const;
};
