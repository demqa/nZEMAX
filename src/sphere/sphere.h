#pragma once
#include "../vector/vector.h"

class Sphere
{
    Vector origin_;
    double radius_;

public:
    Sphere(double radius, const Vector &origin = Vector()):
        origin_(origin),
        radius_(radius)
    {}

    bool contains(const Vector &point) const;
    bool inside  (const Vector &point) const;
};
