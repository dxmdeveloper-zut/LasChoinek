#pragma once
#include <Shapes/Shape.hpp>

class Triangle : public Shape {
    public:
    Triangle(size_t height, size_t width, int rotation, RGB color, int relX = 0, int relY = 0, char symbol = '#');
    private:
    int rotation = 0; // angle = 180 * rotation
    size_t h = 0, w = 0; /** @property w - length of base */
};