#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    float x, y;

    /**
     * Vector2 creation
     * @param x
     * @param y
     */
    Vector2();
    Vector2(float _x);
    Vector2(float _x, float _y);

    /**
     * Operators on Vector2
     * @return a Vector2
     */
    Vector2 operator+(const Vector2 &v) const;
    Vector2 operator-(const Vector2 &v) const;
    Vector2 operator*(float a) const;
    Vector2 operator/(float a) const;
    Vector2 normalize() const;

    /**
     * Operators on Vector2
     * @return a scalar
     */
    float dot(const Vector2 &v) const;
    float norme() const;
};

#endif /* VECTOR2_H */