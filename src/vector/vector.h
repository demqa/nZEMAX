#pragma once

#include <cmath>

class vector_t
{
    double x_, y_, z_;
    double length_ = NAN;

public:
    vector_t(double x = 0, double y = 0, double z = 0):
        x_(x),
        y_(y),
        z_(z),
        length_(length())
    {}

    vector_t(const vector_t &vec):
        vector_t(vec.x_, vec.y_, vec.z_)
    {}

    double x() const;
    double y() const;
    double z() const;
    double length();

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    vector_t operator + (vector_t &vec);
    vector_t operator - (vector_t &vec);
    vector_t operator = (const vector_t &vec);

    vector_t operator += (vector_t &vec);
    vector_t operator -= (vector_t &vec);
    vector_t operator *= (double multiplier);

    vector_t operator - ();
};
