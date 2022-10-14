#include "color.h"
#include <cmath>

Color& Color::operator *= (const Color &color)
{
    setX(color.getX() * getX());
    setY(color.getY() * getY());
    setZ(color.getZ() * getZ());
    return *this;
}

Color& Color::operator += (const Color &color)
{
    setX(color.getX() + getX());
    setY(color.getY() + getY());
    setZ(color.getZ() + getZ());
    return *this;
}

Color& Color::operator *= (double multiplier)
{
    setX(getX() * multiplier);
    setY(getY() * multiplier);
    setZ(getZ() * multiplier);
    return *this;
};

Color Color::operator * (const Color &color) const
{
    Color result{*this};
    return result *= color;
}

Color Color::operator * (double multiplier) const
{
    Color result{*this};
    return result *= multiplier;
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
