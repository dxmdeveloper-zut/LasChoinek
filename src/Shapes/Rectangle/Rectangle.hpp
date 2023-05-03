#pragma once
#include <Shapes/Shape.hpp>

class Rectangle : public Shape {
    public:
    Rectangle(size_t width, size_t height, RGB color,  int posX = 0, int posY = 0, char symbol='#');
};