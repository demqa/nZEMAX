#include "vector.h"

vector_t vector_t::operator + (vector_t &vec)
{
    vector_t new_vec(x_ + vec.x_, y_ + vec.y_, z_ + vec.z_);
    return new_vec;
}

vector_t vector_t::operator - (vector_t &vec)
{
    vector_t new_vec(x_ - vec.x_, y_ - vec.y_, z_ - vec.z_);
    return new_vec;
}

vector_t vector_t::operator = (const vector_t &vec)
{
    x_ = vec.x_;
    y_ = vec.y_;
    z_ = vec.z_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator += (vector_t &vec)
{
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator -= (vector_t &vec)
{
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator *= (double multiplier)
{
    x_ *= multiplier;
    y_ *= multiplier;
    z_ *= multiplier;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator - ()
{
    vector_t new_vec(-x_, -y_, -z_);
    return new_vec;
}

double vector_t::length()
{
    if (std::isnan(length_))
        length_ = sqrt(x_ * x_ + y_ * y_);

    return length_;
}

double vector_t::x() const
{
    return x_;
}

double vector_t::y() const
{
    return y_;
}

double vector_t::z() const
{
    return z_;
}

void vector_t::set_x(double x)
{
    x_ = x;
}

void vector_t::set_y(double y)
{
    y_ = y;
}

void vector_t::set_z(double z)
{
    z_ = z;
}
