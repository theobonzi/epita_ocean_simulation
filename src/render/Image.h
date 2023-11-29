#ifndef IMAGE_H
#define IMAGE_H

#include "Color.h"
#include "../math/Vector3.h"
#include <fstream>
#include <vector>

class Image
{
public:
    int width;
    int height;
    std::vector<Color> pixels;
    float ratio;
    float viewport_height;
    float viewport_width;
    float focal_length;

    /**
     * Image creation
     * @param width
     * @param height
     * @param pixels
     */
    Image(int _width);
    Image(int _width, int _height);

    /**
     * Get a color of pixel
     * @return a Color
     */
    Color &getPixel(int x, int y);

    /**
     * Set pixel(x, y) with color
     */
    void setPixel(int x, int y, const Color &color);

    /**
     * Save image in PPM format
     */
    void savePPM(const std::string &filename);
};

#endif /* IMAGE_H */