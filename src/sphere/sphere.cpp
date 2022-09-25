#include "sphere.h"

bool Sphere::contains(const Vector &p) const
{
    const double eps = 1e-7;

    double d_x = p.x() - origin_.x();
    double d_y = p.y() - origin_.y();
    double d_z = p.z() - origin_.z();

    return std::abs(d_x * d_x + d_y * d_y + d_z * d_z - radius_ * radius_) < eps;
}
