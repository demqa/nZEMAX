#include "vector.h"
#include <cmath>

// kernel
Vector& Vector::operator += (const Vector &vec)
{
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
    return *this;
}

// kernel
Vector& Vector::operator -= (const Vector &vec)
{
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
    return *this;
}

// kernel
Vector& Vector::operator *= (double multiplier)
{
    x_ *= multiplier;
    y_ *= multiplier;
    z_ *= multiplier;
    return *this;
}

// kernel
Vector Vector::operator - ()
{
    return Vector(-x_, -y_, -z_);
}

// kernel
double Vector::getX() const
{
    return x_;
}

// kernel
double Vector::getY() const
{
    return y_;
}

// kernel
double Vector::getZ() const
{
    return z_;
}

// kernel
void Vector::setX(double x)
{
    x_ = x;
}

// kernel
void Vector::setY(double y)
{
    y_ = y;
}

// kernel
void Vector::setZ(double z)
{
    z_ = z;
}

// interface
double Vector::length() const
{
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

// interface
double Vector::cos(const Vector &vec) const
{
    return (vec * *this) / (vec.length() * length());
}

// interface
double Vector::operator * (const Vector &vec) const
{
    return vec.x_ * x_ + vec.y_ * y_ + vec.z_ * z_;
}

// interface
Vector Vector::operator * (double multiplier) const
{
    Vector result{*this};
    return result *= multiplier;
}

// interface
Vector Vector::operator + (const Vector &vec) const
{
    Vector result{*this};
    return result += vec;
}

// interface
Vector Vector::operator - (const Vector &vec) const
{
    Vector result{*this};
    return result -= vec;
}
