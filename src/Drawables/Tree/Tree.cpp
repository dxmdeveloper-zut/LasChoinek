#include "Tree.hpp"
#include <Shapes/Triangle/Triangle.hpp>

Tree::Tree(size_t height, RGB color, int posX, int posY, char symbol) : Drawable(1, posX, posY){
    Triangle* triangle = new Triangle(height, 2 * height - 1, 0, color, 0,0, symbol);
    this->shapesArr[0] = triangle;
}