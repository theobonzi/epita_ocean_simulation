#ifndef LIGHT_H
#define LIGHT_H

#include "../render/Color.h"
#include "../math/Vector3.h"

class Light
{
public:
    Color color;

    /**
     * Light
     * @param color
     */
    Light(Color _color);
};

class Point_Light : public Light
{
public:
    Point3 point;

    /**
     * Point light
     * @param point
     * @param color
     */
    Point_Light(Point3 _point, Color color);
};

#endif /* LIGHT_H */