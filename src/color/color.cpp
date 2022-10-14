#include "color.h"
#include <cmath>

Color Color::operator * (const Color &color) const
{
    double R = color.getX() * getX();
    double G = color.getY() * getY();
    double B = color.getZ() * getZ();
    return Color(R, G, B);
}

double clamp(double color)
{
    if (color > 1) return 1;
    if (color < 0) return 0;
    return color;
}

Color& Color::clamp()
{
    setX(::clamp(getX()));
    setY(::clamp(getY()));
    setZ(::clamp(getZ()));
    alpha_ = ::clamp(alpha_);
    return *this;
}

Color& Color::setAlpha(double alpha)
{
    alpha_ = alpha;
    return *this;
}

unsigned int Color::RGBAcolor() const
{
    unsigned int result = 0;

    result += std::floor(alpha_ * 0xFF);
    result <<= 8;

    result += std::floor(getX() * 0xFF);
    result <<= 8;

    result += std::floor(getY() * 0xFF);
    result <<= 8;

    result += std::floor(getZ() * 0xFF);

    return result;
}
