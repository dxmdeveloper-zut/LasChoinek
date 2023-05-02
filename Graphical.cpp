#include "Graphical.hpp"


void Graphical::shapesPtrsCpy(std::vector<Shape *> &vec){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        vec.push_back(this->shapesArr[i]);
    }
}
Graphical::Graphical(size_t shapesArrSize){
    this->shapesArrSize = shapesArrSize;
    this->shapesArr = new Shape* [shapesArrSize];
}

Graphical::~Graphical(){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        if(this->shapesArr[i])
            delete this->shapesArr[i];
    }
    delete [] this->shapesArr;
}