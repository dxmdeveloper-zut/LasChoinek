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
    void draw(int ** arr, size_t arr_w, size_t arr_h, int interp1sAs, int posRelToX = 0, int posRelToY = 0);
    virtual ~Shape(); 
    // Accessors
    int getPosX();
    int getPosY();
    size_t getMatrixHeight();
    size_t getMatrixWidth();
    void setSymbol(char symbol);
    char getSymbol();
    void setColor(RGB color);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    RGB getColor();

    // debug methods
    void dbg_printMatrix();
    

    protected:
    Shape(size_t mat_width, size_t mat_height, RGB color, int relX = 0, int relY = 0, char symbol='#');
    bool ** matrix;

    private:
    //virtual void drawMatrix() = 0;
    RGB color = {0};
    char symbol = '#';
    size_t mat_height = 0, mat_width = 0;
    int posX = 0, posY = 0;
};