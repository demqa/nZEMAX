#include "coordinate_system.h"

void coordinate_system_t::draw(const vector_t &vec, const sf::Color &color) const
{

    sf::Vertex line[2];

    double x0 = origin_.x();
    double y0 = origin_.y();
    line[0].position = sf::Vector2f(x0, y0);
    line[1].position = sf::Vector2f(x0 + vec.x(), y0 + vec.y());
    line[0].color = line[1].color = color;

    window_.draw(line, 2, sf::Lines);
}
