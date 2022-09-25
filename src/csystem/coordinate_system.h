#pragma once

#include "../vector/vector.h"
#include <SFML/Graphics.hpp>

class coordinate_system_t
{
    vector_t origin_;
    vector_t e1_, e2_;
    sf::RenderWindow &window_;

public:
    coordinate_system_t(sf::RenderWindow &window):
        window_(window),
        origin_(),
        e1_(1, 0),
        e2_(0, 1)
    {}

    coordinate_system_t(sf::RenderWindow &window, vector_t &origin):
        window_(window),
        origin_(origin),
        e1_(1, 0),
        e2_(0, 1)
    {}

    coordinate_system_t(sf::RenderWindow &window, vector_t &origin, vector_t &e1, vector_t &e2):
        window_(window),
        origin_(origin),
        e1_(e1),
        e2_(e2)
    {}

    void draw(const vector_t &vec, const sf::Color &color = sf::Color::Red) const;
};
