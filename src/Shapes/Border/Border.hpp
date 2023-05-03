#pragma once
#include <Shapes/Rectangle/Rectangle.hpp>

class Border : public Rectangle {
    public:
    Border(size_t width, size_t height, RGB color,  int posX = 0, int posY = 0, char symbol='#');
};
