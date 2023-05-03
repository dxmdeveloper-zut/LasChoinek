#include "Triangle.hpp"
#include <cmath>
#include <rgb.hpp>
#include <stdexcept>

Triangle::Triangle(size_t height, size_t width, int rotation, RGB color, int relX, int relY, char symbol) 
 : Shape(width, height, color, relX, relY, symbol){
    if(height == 0 || width == 0) return;

    bool invY = rotation % 4 == 2 || rotation % 4 == 1;
    bool swapXY = rotation % 2;
    size_t h = swapXY ? width : height;
    size_t w = swapXY ? height : width;

    size_t filledSpace = 0;
    for(size_t y = 0; y < h; y += 1){
        
        if(invY) filledSpace = (1 - (float)y / h) * w;
        else filledSpace = (float)(y+1) / h * w;
        
        size_t freeSpace = w - filledSpace;
        size_t x = freeSpace/2;
        for(size_t s = 0; s < filledSpace; s++,  x += 1){
            if(!swapXY) this->matrix[y][x] = true;
            else this->matrix[x][y] = true;
        }
    }

}