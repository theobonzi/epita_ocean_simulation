#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : real(0), imag(0) {}
Complex::Complex(float _real, float _imag) : real(_real), imag(_real) {}

Complex Complex::operator+(const Complex &c) const
{
    return {real + c.real, imag + c.imag};
}

Complex Complex::operator-(const Complex &c) const
{
    return {real - c.real, imag - c.imag};
}

Complex Complex::operator*(const Complex &c) const
{
    return {real * c.real - imag * c.imag, real * c.imag + c.real * imag};
}

Complex Complex::Conjugate() const
{
    return {real, -imag};
}