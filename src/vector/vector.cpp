#include "vector.h"

double Vector::cos(Vector &vec)
{
    return (vec * *this) / (vec.length() * length());
}

double Vector::operator * (const Vector &vec) const
{
    return vec.x_ * x_ + vec.y_ * y_ + vec.z_ * z_;
}

Vector Vector::operator + (const Vector &vec) const
{
    Vector newVec(x_ + vec.x_, y_ + vec.y_, z_ + vec.z_);
    return newVec;
}

Vector Vector::operator - (const Vector &vec) const
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

Vector& Vector::operator += (Vector &vec)
{
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
    length_ = NAN;
    return *this;
}

Vector& Vector::operator -= (Vector &vec)
{
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
    length_ = NAN;
    return *this;
}

Vector& Vector::operator *= (double multiplier)
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
    // idk what the hell, but isnan doesn't work.
    length_ = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);

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
