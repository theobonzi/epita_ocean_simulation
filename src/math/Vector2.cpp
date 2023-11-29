#include "Vector2.h"
#include <cmath>
#include <iostream>

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float _x) : x(_x), y(_x) {}
Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

Vector2 Vector2::operator+(const Vector2 &v) const
{
    return {x + v.x, y + v.y};
}

Vector2 Vector2::operator-(const Vector2 &v) const
{
    return {x - v.x, y - v.y};
}

Vector2 Vector2::operator*(float a) const
{
    return {x * a, y * a};
}

Vector2 Vector2::operator/(float a) const
{
    return {x / a, y / a};
}

float Vector2::dot(const Vector2 &v) const
{
    return v.x * x + v.y * y;
}

float Vector2::norme() const
{
    return sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() const
{
    return Vector2(x, y) / this->norme();
}
