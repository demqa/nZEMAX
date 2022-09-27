#include "coordinate_system.h"

const Vector& CoordinateSystem::e1() const
{
    return e1_;
}

const Vector& CoordinateSystem::e2() const
{
    return e2_;
}

const Vector& CoordinateSystem::e3() const
{
    return e3_;
}

void CoordinateSystem::draw(const Vector &vec, const sf::Color &color) const
{
    sf::Vertex line[2];

    double x0 = origin_.getX();
    double y0 = origin_.getY();
    line[0].position = sf::Vector2f(x0, y0);
    line[1].position = sf::Vector2f(x0 + vec.getX(), y0 + vec.getY());
    line[0].color = line[1].color = color;

    window_.draw(line, 2, sf::Lines);
}
