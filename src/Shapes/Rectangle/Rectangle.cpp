#include "Rectangle.hpp"

Rectangle::Rectangle(size_t width, size_t height, RGB color,  int posX , int posY , char symbol) 
          : Shape(width, height, color, posX, posY, symbol){
    for(size_t y = 0; y < height; y++)
        for(size_t x = 0; x < width; x++) 
            this->matrix[y][x] = true;
}