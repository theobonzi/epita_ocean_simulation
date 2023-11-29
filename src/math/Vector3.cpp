#include "Vector3.h"
#include <cmath>
#include <iostream>

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Vector3 Vector3::operator+(const Vector3 &v) const
{
    return {x + v.x, y + v.y, z + v.z};
}

Vector3 Vector3::operator-(const Vector3 &v) const
{
    return {x - v.x, y - v.y, z - v.z};
}

Vector3 Vector3::operator*(float s) const
{
    return {x * s, y * s, z * s};
}

Vector3 Vector3::operator/(float s) const
{
    return {x / s, y / s, z / s};
}

Vector3 Vector3::operator-() const
{
    return {-x, -y, -z};
}

Vector3 Vector3::normalize() const
{
    return Vector3(x, y, z) / this->norme();
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3 &Vector3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Vector3 &Vector3::operator/=(float s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

float Vector3::dot(const Vector3 &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

float Vector3::norme() const
{
    return sqrt(x * x + y * y + z * z);
}

bool Vector3::operator==(const Vector3 &v) const
{
    return x == v.x && y == v.y && z == v.z;
}