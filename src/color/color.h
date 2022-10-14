#pragma once

#include "config.h"
#include "vector.h"

// TODO: remove
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

    // TODO: remove it
    void dump() const {
        std::cout << "Color dump: (" << getX() << ", " << getY() << ", " << getZ() << "); alpha = " << alpha_ << "\n";
    }

    Color(nZemax::Colors RGBcolor, double alpha = 1):
        Vector(
            Vector(
                (((unsigned int) RGBcolor >>  0) & 0xFF) / double(0xFF),
                (((unsigned int) RGBcolor >>  8) & 0xFF) / double(0xFF),
                (((unsigned int) RGBcolor >> 16) & 0xFF) / double(0xFF)
            )
        ),
        alpha_(alpha)
    {}

    unsigned int RGBAcolor() const;

    Color& setAlpha(double alpha);
    Color& clamp();

    Color& operator *= (const Color& color);
    Color& operator += (const Color& color);
    Color& operator *= (double multiplier);

    Color  operator * (const Color& color) const;
    Color  operator * (double multiplier) const;
};

double clamp(double color);
