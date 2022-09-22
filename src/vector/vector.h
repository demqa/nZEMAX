#pragma once

#include <cmath>

class vector_t
{
    double x_, y_;
    double length_ = NAN;

public:
    vector_t(double x = 0, double y = 0):
        x_(x),
        y_(y),
        length_(length())
    {}

    vector_t(const vector_t &vec):
        vector_t(vec.x_, vec.y_)
    {}

    double x() const;
    double y() const;
    double length();

    vector_t operator + (vector_t &vec);
    vector_t operator - (vector_t &vec);
    vector_t operator = (const vector_t &vec);

    vector_t operator += (vector_t &vec);
    vector_t operator -= (vector_t &vec);
    vector_t operator *= (double multiplier);

    vector_t operator - ();
};
