#include "Shape.hpp"

Shape::Shape(size_t mat_width, size_t mat_height, RGB color, char symbol) 
    : mat_width{mat_width}, mat_height{mat_height}, color{color}, symbol{symbol}{
    this->matrix = new char * [mat_height];
    for(size_t h = 0; h < mat_height; h++)
        this->matrix[h] = new char[mat_width]();
}

Shape::~Shape(){
    for(size_t h = 0; h < mat_height; h++)
        delete [] this->matrix[h];
    delete [] this->matrix;
}