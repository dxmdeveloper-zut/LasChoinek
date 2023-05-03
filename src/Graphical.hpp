#pragma once
#include <Shapes/Shape/Shape.hpp>
#include <vector>
#include <stdlib.h>

/* abstract class */
class Graphical {
    public:
    void shapesPtrsCpy(std::vector<Shape*> &vec);
    ~Graphical();

    protected:
    Graphical(size_t shapesArrSize);

    private:
    size_t shapesArrSize;
    Shape **shapesArr = nullptr;
};