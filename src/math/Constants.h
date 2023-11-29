#ifndef CONSTANS_H
#define CONSTANS_H
#include "Vector2.h"

constexpr int RESOLUTION = 500;
constexpr float PATCH_SIZE = 256.0f;

constexpr float WIND_SPEED = 4.5f;
constexpr float GRAVITY = 9.81f;
Vector2 WIND_DIRECTION = Vector2(-1, -1).normalize();

#endif /* CONSTANS_H */