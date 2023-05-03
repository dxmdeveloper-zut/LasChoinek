#include "Drawable.hpp"


void Drawable::shapesCpy(std::vector<Shape *> &vec, int ** matrix, size_t mw, size_t mh){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        if(!this->shapesArr[i]) continue;
        this->shapesArr[i]->draw(matrix, mw, mh, vec.size() + 1, this->posX, this->posY);
        vec.push_back(this->shapesArr[i]);

    }
}
Drawable::Drawable(size_t shapesArrSize, int posX, int posY) : posX{posX}, posY{posY}{
    this->shapesArrSize = shapesArrSize;
    this->shapesArr = new Shape* [shapesArrSize]();
}

Drawable::~Drawable(){
    for(size_t i = 0; i < this->shapesArrSize; i++){
        if(this->shapesArr[i])
            delete this->shapesArr[i];
    }
    delete [] this->shapesArr;
}