#include "Drawable.hpp"


void Drawable::shapesPtrsCpy(std::vector<Shape *> &vec){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        vec.push_back(this->shapesArr[i]);
    }
}
Drawable::Drawable(size_t shapesArrSize){
    this->shapesArrSize = shapesArrSize;
    this->shapesArr = new Shape* [shapesArrSize];
}

Drawable::~Drawable(){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        if(this->shapesArr[i])
            delete this->shapesArr[i];
    }
    delete [] this->shapesArr;
}