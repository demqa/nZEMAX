#include "vector.h"

vector_t vector_t::operator + (vector_t &vec)
{
    return {x_ + vec.x_, y_ + vec.y_};
}

vector_t vector_t::operator - (vector_t &vec)
{
    return {x_ - vec.x_, y_ - vec.y_};
}

vector_t vector_t::operator -= (vector_t &vec)
{
    x_ -= vec.x_;
    y_ -= vec.y_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator += (vector_t &vec)
{
    x_ += vec.x_;
    y_ += vec.y_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator - ()
{
    x_ = - x_;
    y_ = - y_;
    length_ = NAN;
    return *this;
}

vector_t vector_t::operator * (double multiplier)
{
    x_ *= multiplier;
    y_ *= multiplier;
    length_ = NAN;
    return *this;
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
