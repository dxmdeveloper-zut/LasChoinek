#pragma once
#include <Shapes/Shape.hpp>
#include <vector>
#include <stdlib.h>

/* abstract class */
class Drawable {
    public:
    void shapesCpy(std::vector<Shape*> &vec, int ** matrix, size_t mat_width, size_t mat_height);
    ~Drawable();

    protected:
    Drawable(size_t shapesArrSize, int posX = 0, int posY = 0);
    Shape **shapesArr = nullptr;
    int posX = 0, posY = 0;

    private:
    size_t shapesArrSize;
};