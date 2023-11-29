#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    float r, g, b;

    /**
     * Color Red, Green, Blue
     * @param r
     * @param g
     * @param b
     */
    Color();
    Color(float _r, float _g, float _b);

    /**
     * Operators on Color
     * @return Color
     */
    Color operator*(Color color);
    Color operator+(Color color);
    Color operator*(float s);
    Color operator/(float s);

    /**
     * Clamp one channel color
     * @return float x, 0 or 255
     */
    float my_clamp(float x);

    /**
     * Clamp color (3 chanels)
     * @return Color
     */
    Color clamp();
};

#endif /* COLOR_H */