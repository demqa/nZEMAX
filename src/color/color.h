#pragma once

#include "config.h"
#include "vector.h"

// TODO: remove this debug header
#include <iostream>

class Color: Vector {
    double alpha_ = 1;

public:
    Color(double x = 0, double y = 0, double z = 0, double alpha = 1):
        Vector(x, y, z),
        alpha_(alpha)
    {
        clamp();
    };

    Color(nZemax::Colors RGBcolor, double alpha = 1):
        Vector(
            Vector(
                 ((unsigned int) RGBcolor        & 0xFF) / double(0xFF),
                (((unsigned int) RGBcolor >> 8)  & 0xFF) / double(0xFF),
                (((unsigned int) RGBcolor >> 16) & 0xFF) / double(0xFF)
            )
        ),
        alpha_(alpha)
    {
        std::cout << "Color initialized: (" << getX() << ", " << getY() << ", " << getZ() << "); alpha = " << alpha << "\n";
    }

    // TODO: remove it
    void dump() const {
        std::cout << "Color dump: (" << getX() << ", " << getY() << ", " << getZ() << "); alpha = " << alpha_ << "\n";
    }

    unsigned int RGBAcolor() const;

    Color& setAlpha(double alpha);
    Color& clamp();

    Color  operator * (const Color& color) const;
    Color& operator *= (double multiplier)
    {
        setX(getX() * multiplier);
        setY(getY() * multiplier);
        setZ(getZ() * multiplier);
        return *this;
    };
};

double clamp(double color);
