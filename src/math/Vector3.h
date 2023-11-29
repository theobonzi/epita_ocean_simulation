#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
    float x, y, z;

    /**
     * Vector3 creation
     * @param x
     * @param y
     * @param z
     */
    Vector3();
    Vector3(float _x, float _y, float _z);

    /**
     * Operators on Vector3
     * @return a Vector3
     */
    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(float s) const;
    Vector3 operator/(float s) const;
    Vector3 operator-() const;
    Vector3 normalize() const;
    Vector3 &operator+=(const Vector3 &v);
    Vector3 &operator-=(const Vector3 &v);
    Vector3 &operator*=(float s);
    Vector3 &operator/=(float s);

    /**
     * Operators on Vector3
     * @return a scalar
     */
    float dot(const Vector3 &v) const;
    float norme() const;

    /**
     * Operators on Vector3
     * @return a boolean
     */
    bool operator==(const Vector3 &v) const;
};

using Point3 = Vector3;

#endif /* VECTOR3_H */