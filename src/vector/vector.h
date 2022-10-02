#pragma once

class Vector
{
private:
    double x_, y_, z_;

public:
    Vector(double x = 0, double y = 0, double z = 0):
        x_(x),
        y_(y),
        z_(z)
    {}

    // kernel getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // kernel setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // kernel operators
    Vector& operator += (const Vector &vec);
    Vector& operator -= (const Vector &vec);
    Vector& operator *= (double multiplier);

    Vector operator - ();

    // make if interface functions
    double length() const;
    double cos(const Vector &vec) const;

    // make it interface operators
    double operator * (const Vector &vec) const; // scalar product
    Vector operator + (const Vector &vec) const;
    Vector operator - (const Vector &vec) const;
};
