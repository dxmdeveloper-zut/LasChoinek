#include "Shape.hpp"
#include <algorithm>
#include <iostream>

//Accessors
int Shape::getPosX(){return this->posX;}
int Shape::getPosY(){return this->posY;}
size_t Shape::getMatrixHeight(){return this->mat_height;}
size_t Shape::getMatrixWidth(){return this->mat_width;}
RGB Shape::getColor(){return this->color;}
char Shape::getSymbol(){return this->symbol;}
void Shape::setSymbol(char symbol){
    this->symbol = symbol;
}
void Shape::setColor(RGB color){ 
    this->color = color; 
}
void Shape::setColor(uint8_t red, uint8_t green, uint8_t blue){
    this->color = {red, green, blue};
}


void Shape::draw(int **arr, size_t arr_w, size_t arr_h, int interp1sAs, int posRelToX, int posRelToY){
    size_t mh = this->getMatrixHeight(), mw = this->getMatrixWidth();
    int posX = posRelToX + this->getPosX(), posY = posRelToY + this->getPosY();

    for(size_t y = std::max(posY, 0); y < std::min(posY + mh, arr_h); y++){
        for(size_t x = std::max(posX, 0); x < std::min(posX + mw, arr_w); x++){
            
            arr[y][x] = this->matrix[y - posY][x - posX] ? interp1sAs : arr[y][x];
        }
    }
}

Shape::Shape(size_t mat_width, size_t mat_height, RGB color,int relX, int relY, char symbol) 
    : mat_width{mat_width}, mat_height{mat_height}, color{color}, posX{relX}, posY{relY}, symbol{symbol}{
    bool * matrixContent = new bool[mat_height * mat_width]();
    this->matrix = new bool*[mat_height]();
    for(size_t h = 0; h < mat_height; h++){
        this->matrix[h] = &matrixContent[h * mat_width];
    }
}

Shape::~Shape() {
    delete [] this->matrix[0];
    delete [] this->matrix;
}

#if DEBUG==1
    #include <iostream>
    void Shape::dbg_printMatrix(){
        for(size_t y = 0; y < mat_height; y++){
            for(size_t x = 0; x < mat_width; x++)
                std::cout << this->matrix[y][x];
            std::cout << std::endl;
        }
    }
#else
    void Shape::dbg_printMatrix(){}
#endif
