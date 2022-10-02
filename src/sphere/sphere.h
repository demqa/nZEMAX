#pragma once
#include "vector.h"

class Sphere
{
    Vector origin_;
    double radius_;

public:
    double radius() const;
    const Vector& origin() const;

    Sphere(double radius, const Vector& origin = Vector()):
        origin_(origin),
        radius_(radius)
    {}

    bool contains(const Vector& point) const;
    bool inside  (const Vector& point) const;

    Vector normal(const Vector& point) const;
};
