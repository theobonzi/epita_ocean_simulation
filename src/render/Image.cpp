#include "Image.h"
#include "Color.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

Image::Image(int _width) : width(_width), pixels(width * height)
{
    ratio = 16.0 / 9.0;
    height = static_cast<int>(width / ratio);
    viewport_height = 2.0;
    viewport_width = ratio * viewport_height;
    focal_length = 1.0;
}

Image::Image(int _width, int _height) : width(_width), height(_height), pixels(_width * _height) {}

Color &Image::getPixel(int x, int y)
{
    return pixels[x + y * width];
}

void Image::setPixel(int x, int y, const Color &color)
{
    pixels[x + y * width] = color;
}

void Image::savePPM(const std::string &filename)
{
    std::fstream file;
    file.open(filename, std::ios::out);

    if (!file)
    {
        std::cout << "Error: Could not open file \"" << filename << "\" for writing." << std::endl;
        return;
    }
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            Color &color = getPixel(x, y);
            file << static_cast<int>(color.r * 255.999) << " "
                 << static_cast<int>(color.g * 255.999) << " "
                 << static_cast<int>(color.b * 255.999) << std::endl;
        }
    }
    std::cout << "Image save in out.ppm" << std::endl;
    file.close();
}