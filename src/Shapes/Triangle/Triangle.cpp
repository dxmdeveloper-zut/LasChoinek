#include "Triangle.hpp"
#include <cmath>
#include <rgb.hpp>
#include <stdexcept>

Triangle::Triangle(size_t height, size_t width, int rotation, RGB color, char symbol) 
 : Shape(width, height, color, symbol){

    for(size_t y = 0; y < height; y++){
        size_t filledSpace = std::round((float)(y+1) / height * width);
        size_t freeSpace = width - filledSpace;
        size_t x = freeSpace/2;
        for(size_t s = 0; s < filledSpace; s++, x++) this->matrix[y][x] = true;
    }
}