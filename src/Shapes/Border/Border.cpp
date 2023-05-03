#include "Border.hpp"

Border::Border(size_t width, size_t height, RGB color, int posX, int posY, char symbol) 
       : Rectangle(width, height, color, posX, posY, symbol){
    for(size_t y = 1; y < height - 1; y++)
        for(size_t x = 1; x < width - 1; x++)
            this->matrix[y][x] = false;
}