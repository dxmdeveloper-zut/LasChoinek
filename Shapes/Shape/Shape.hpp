#pragma once
#include <stdlib.h>
#include <rgb.hpp>

/**
 @brief polimorphic base class
    handles all dynamic allocation for derived classes.
    subclasses must handle drawing (on Shape::matrix) on its own.
*/
class Shape {
    public:
    void matcpy(int ** arr, size_t arr_w, size_t arr_h, int interp1sAs);
    ~Shape(); //deletes matrix

    protected:
    Shape(size_t mat_width, size_t mat_height, RGB color, char symbol='#');
    char **matrix = nullptr; // TODO: protected operator [], matrix itself should be private 

    private:
    RGB color = {0};
    char symbol = '#';
    size_t mat_height = 0, mat_width = 0;
};