#include "sphere.h"
#include <cmath>

#include <cassert>

static const double eps = 1e-7;

double Sphere::radius() const
{
    return radius_;
}

const Vector& Sphere::origin() const
{
    return origin_;
}

const Color& Sphere::color() const
{
    return color_;
}

bool Sphere::contains(const Vector &p) const
{
    double d_x = p.getX() - origin_.getX();
    double d_y = p.getY() - origin_.getY();
    double d_z = p.getZ() - origin_.getZ();

    return std::abs(d_x * d_x + d_y * d_y + d_z * d_z - radius_ * radius_) < eps;
}

bool Sphere::inside(const Vector &p) const
{
    double d_x = p.getX() - origin_.getX();
    double d_y = p.getY() - origin_.getY();
    double d_z = p.getZ() - origin_.getZ();

    return d_x * d_x + d_y * d_y + d_z * d_z < radius_ * radius_;
}

Vector Sphere::normal(const Vector &p) const
{
    assert(contains(p));

    return p - origin_;
}
