#include "choinka.hpp"
#include "rgb.hpp"
#include "terminal.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>

Choinka::Choinka(size_t height, RGB color, char symbol)
: color{color}, height{height}, symbol{symbol}{
    this->matrix = nullptr;
    this->createMatrix();
}

Choinka::~Choinka(){
    this->deleteMatrix();
}

void Choinka::createMatrix(){
    size_t lineWidth = this->getHeight() * 2 - 1;
    size_t height = this->getHeight();

    // memory alloc
    if(this->matrix) this->deleteMatrix();
    this->matrix = new char * [height];
    for(size_t y = 0; y < height; y++){
        this->matrix[y] = new char [lineWidth];
    }

    for(size_t i = 0, x = 0; i < this->getHeight(); i++, x=0){
        unsigned freeSpace = lineWidth - 1 - i * 2;
        for(size_t s = 0; s < freeSpace / 2; s++, x++) this->matrix[i][x] = 0;
        for(size_t s = 0; s < i * 2 + 1; s++, x++)     this->matrix[i][x] = 1;
        for(size_t s = 0; s < freeSpace / 2; s++, x++) this->matrix[i][x] = 0;
    } 

}



// Accessors
void Choinka::setColor(RGB color){ 
    this->color = color; 
}
void Choinka::setColor(uint8_t red, uint8_t green, uint8_t blue){
    this->color = {red, green, blue};
}
RGB Choinka::getColor(){ 
    return this->color;
}

void Choinka::setHeight (size_t height)  { 
    this->height = height;
    this->createMatrix();
}
size_t Choinka::getHeight(){
    return this->height;
}
void Choinka::setSymbol(char symbol){
    this->symbol = symbol;
}
char Choinka::getSymbol(){
    return this->symbol;
}

int Choinka::getPosX(){
	return this->x;
}
int Choinka::getPosY() {
	return this->y;
}
void Choinka::setPosition(int x, int y) {
	this->x = x; this->y = y;
}

void Choinka::matcpy(int ** arr,  size_t arr_w, size_t arr_h,  int interp1sAs){
    for(size_t y = std::max(this->getPosY(), 0); y < std::min(this->getPosY() + this->getHeight(), arr_h); y++){
        for(size_t x = std::max(this->getPosX(), 0); x < std::min(this->getPosX() + this->getHeight() * 2 - 1, arr_w); x++){
            
            arr[y][x] = this->matrix[y - this->getPosY()][x - this->getPosX()] ? interp1sAs : arr[y][x];
        }
    }
}

// protected methods
void Choinka::deleteMatrix(){
    if(!this->matrix) return;
    for(size_t y = 0; y < this->height; y++){
        delete [] this->matrix[y];
    }
    delete [] this->matrix;
}
