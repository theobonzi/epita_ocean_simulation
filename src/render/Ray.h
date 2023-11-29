#ifndef RAY_H
#define RAY_H

#include "../math/Vector3.h"
#include <iostream>

class Ray
{
public:
    Point3 origin;
    Vector3 direction;

    /**
     * Create a ray
     * @param origin
     * @param direction
     */
    Ray();
    Ray(const Point3 &_origin, const Vector3 &_direction);
};

#endif /* RAY_H */