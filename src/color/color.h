#pragma once

#include "vector.h"

class Color: Vector {
public:
    Color(double x = 0, double y = 0, double z = 0): Vector(x, y, z) {};

    Color(unsigned int RGBcolor):
        Vector(RGBcolor & 0xFF, (RGBcolor >> 8) & 0xFF, (RGBcolor >> 16) & 0xFF)
    {}

    Color& clamp();
    Color operator * (const Color& color) const;
};
