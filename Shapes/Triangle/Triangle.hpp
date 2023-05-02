#pragma once
#include <Shapes/Shape/Shape.hpp>

class Triangle : public Shape {
    public:
    Triangle(size_t height, size_t width, int rotation, RGB color, char symbol);
    private:
    int rotation = 0; // angle = 180 * rotation
    size_t h = 0, w = 0;
};