#include "Shape.hpp"
#include <algorithm>


Shape::Shape(size_t mat_width, size_t mat_height, RGB color, char symbol) 
    : mat_width{mat_width}, mat_height{mat_height}, color{color}, symbol{symbol}{
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
