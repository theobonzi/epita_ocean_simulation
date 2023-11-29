#ifndef OBJECT_H
#define OBJECT_H

#include "../math/Vector3.h"
#include "../render/Color.h"
#include "../render/Ray.h"
#include <cmath>

class Object
{
public:
    Color color;

    Object(Color _color) : color(_color) {}

    virtual float intersect(const Ray &ray) const = 0;
    virtual Vector3 getNormal(const Point3 &point) const = 0;
};

class Sphere : public Object
{
public:
    Sphere(const Point3 _center, float _radius, Color _color);

    float intersect(const Ray &ray) const override
    {
        Vector3 oc = ray.origin - center;
        auto a = ray.direction.norme();
        auto half_b = oc.dot(ray.direction);
        auto c = oc.norme() - radius * radius;
        auto discriminant = half_b * half_b - a * c;
        if (discriminant < 0)
            return -1.0;
        else
            return (-half_b - sqrt(discriminant)) / a;
    }
    Vector3 getNormal(const Point3 &point) const override
    {
        return (point - center) / ((point - center).norme());
    }
    Point3 center;
    float radius;
};

#endif // OBJECT_H
