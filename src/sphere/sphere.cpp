#include "sphere.h"
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

bool Sphere::contains(const Vector &p) const
{
    double d_x = p.x() - origin_.x();
    double d_y = p.y() - origin_.y();
    double d_z = p.z() - origin_.z();

    return std::abs(d_x * d_x + d_y * d_y + d_z * d_z - radius_ * radius_) < eps;
}

bool Sphere::inside(const Vector &p) const
{
    double d_x = p.x() - origin_.x();
    double d_y = p.y() - origin_.y();
    double d_z = p.z() - origin_.z();

    return d_x * d_x + d_y * d_y + d_z * d_z < radius_ * radius_;
}

Vector Sphere::normal(const Vector &p) const
{
    assert(contains(p));

    return p - origin_;
}
