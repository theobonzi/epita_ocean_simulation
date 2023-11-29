#include "Color.h"
#include <fstream>
#include <iostream>

Color::Color() : r(0), g(0), b(0) {}
Color::Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}

Color Color::operator*(float s)
{
    return Color(r * s, g * s, b * s).clamp();
}

Color Color::operator*(Color color)
{
    return Color(r * color.r, g * color.g, b * color.b).clamp();
}

Color Color::operator+(Color color)
{
    return Color(r + color.r, g + color.g, b + color.b).clamp();
}

Color Color::operator/(float s)
{
    return Color(r / s, g / s, b / s).clamp();
}

float Color::my_clamp(float x)
{
    return (x > 1 ? 1 : (x < 0 ? 0 : x));
}

Color Color::clamp()
{
    return {my_clamp(r), my_clamp(g), my_clamp(b)};
}