#pragma once
#include <Shapes/Shape.hpp>
#include <vector>
#include <stdlib.h>

/* abstract class */
class Drawable {
    public:
    void shapesPtrsCpy(std::vector<Shape*> &vec);
    ~Drawable();

    protected:
    Drawable(size_t shapesArrSize);

    private:
    size_t shapesArrSize;
    Shape **shapesArr = nullptr;
};