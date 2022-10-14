#pragma once

#include "vector.h"
#include "color.h"

class Sphere
{
    Vector origin_;
    Color  color_;
    double radius_;

public:
    double radius() const;
    const Vector& origin() const;
    const Color& color() const;

    Sphere(double radius, const Color& color, const Vector& origin = Vector()):
        origin_(origin),
        color_ (color),
        radius_(radius)
    {}

    bool contains(const Vector& point) const;
    bool inside  (const Vector& point) const;

    Vector normal(const Vector& point) const;
};
