#ifndef _CHOINKA_H_ 
#define _CHOINKA_H_ 1
#include <string>
#include "rgb.hpp"

class Choinka {
    public:
    Choinka(size_t height, RGB color, char symbol='#');
    ~Choinka();
    void print();

    // Accessors
    void setSymbol(char symbol);
    char getSymbol();
    void setColor(RGB color);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    RGB getColor();
    int getPosX();
	int getPosY();
	void setPosition(int x, int y);
    void setHeight(size_t height);
    size_t getHeight();

    void matcpy(int ** arr, size_t arr_w, size_t arr_h, int interp1sAs);

    protected:
    void createMatrix();
    void deleteMatrix();

    int x, y;
    char ** matrix;
    char symbol;
    RGB color;
    size_t height;
};

#endif