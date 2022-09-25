#include "vector.h"

Vector Vector::operator + (Vector &vec)
{
    Vector newVec(x_ + vec.x_, y_ + vec.y_, z_ + vec.z_);
    return newVec;
}

Vector Vector::operator - (Vector &vec)
{
    Vector newVec(x_ - vec.x_, y_ - vec.y_, z_ - vec.z_);
    return newVec;
}

Vector Vector::operator = (const Vector &vec)
{
    x_ = vec.x_;
    y_ = vec.y_;
    z_ = vec.z_;
    length_ = NAN;
    return *this;
}

Vector Vector::operator += (Vector &vec)
{
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
    length_ = NAN;
    return *this;
}

Vector Vector::operator -= (Vector &vec)
{
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
    length_ = NAN;
    return *this;
}

Vector Vector::operator *= (double multiplier)
{
    x_ *= multiplier;
    y_ *= multiplier;
    z_ *= multiplier;
    length_ = NAN;
    return *this;
}

Vector Vector::operator - ()
{
    Vector newVec(-x_, -y_, -z_);
    return newVec;
}

double Vector::length()
{
    if (std::isnan(length_))
        length_ = sqrt(x_ * x_ + y_ * y_);

    return length_;
}

double Vector::x() const
{
    return x_;
}

double Vector::y() const
{
    return y_;
}

double Vector::z() const
{
    return z_;
}

void Vector::setX(double x)
{
    x_ = x;
}

void Vector::setY(double y)
{
    y_ = y;
}

void Vector::setZ(double z)
{
    z_ = z;
}
