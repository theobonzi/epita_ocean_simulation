#include "Ray.h"
#include <fstream>

Ray::Ray() {}

Ray::Ray(const Point3 &_origin, const Vector3 &_direction) : origin(_origin), direction(_direction) {}