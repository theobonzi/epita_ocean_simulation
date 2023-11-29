#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    float real;
    float imag;

    /**
     * Complex creation
     * @param real
     * @param imag
     */
    Complex();
    Complex(float _real, float _imag);

    /**
     * Operators on Vector3
     * @return a Vector3
     */
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;

    Complex Conjugate() const;
};
#endif /* COMPLEX_H */