#include "color.h"

Color Color::operator * (const Color &color) const
{
    double R = color.getX() * getX() / 0xFF;
    double G = color.getY() * getY() / 0xFF;
    double B = color.getZ() * getZ() / 0xFF;
    return Color(R, G, B);
}

static double clamp(double color)
{
    if (color > 0xFF) return 0xFF;
    if (color < 0x00) return 0x00;
    return color;
}

Color& Color::clamp()
{
    setX(::clamp(getX()));
    setY(::clamp(getY()));
    setZ(::clamp(getZ()));
    return *this;
}
