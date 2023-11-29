#include "Light.h"
#include <fstream>
#include <iostream>

Light::Light(Color _color) : color(_color) {}
Point_Light::Point_Light(Point3 _point, Color color) : point(_point), Light(color){};
