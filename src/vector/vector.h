#pragma once

#include <cmath>

class Vector
{
    double x_, y_, z_;
    double length_ = NAN;

public:
    Vector(double x = 0, double y = 0, double z = 0):
        x_(x),
        y_(y),
        z_(z),
        length_(length())
    {}

    Vector(const Vector &vec):
        Vector(vec.x_, vec.y_, vec.z_)
    {}

    double x() const;
    double y() const;
    double z() const;
    double length();
    double cos(Vector &vec);

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double operator * (const Vector &vec) const;
    Vector operator + (const Vector &vec) const;
    Vector operator - (const Vector &vec) const;
    Vector operator = (const Vector &vec);

    Vector& operator += (Vector &vec);
    Vector& operator -= (Vector &vec);
    Vector& operator *= (double multiplier);

    Vector operator - ();
};
