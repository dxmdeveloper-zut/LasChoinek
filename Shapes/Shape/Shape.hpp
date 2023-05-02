#pragma once
#include <stdlib.h>
#include <rgb.hpp>
#include <memory>
#include <functional>

/**
 @brief abstract class
*/
class Shape {
    public:
    void matcpy(int ** arr, size_t arr_w, size_t arr_h, int interp1sAs);
    virtual ~Shape(); 

    protected:
    Shape(size_t mat_width, size_t mat_height, RGB color, char symbol='#');
    bool ** matrix;

    private:
    virtual void drawMatrix() = 0;
    RGB color = {0};
    char symbol = '#';
    size_t mat_height = 0, mat_width = 0;
};