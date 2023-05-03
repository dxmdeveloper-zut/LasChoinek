#include "House.hpp"
#include "Shapes/Border/Border.hpp"
#include "Shapes/Rectangle/Rectangle.hpp"
#include "Shapes/Triangle/Triangle.hpp"

struct sizes {
    size_t width;
    size_t height;
};

House::House(int posX, int posY) : Drawable(6, posX, posY){
    const sizes roofSizes {42, 10};
    const sizes borderSizes {roofSizes.width - 8, 12};
    Triangle * roof = new Triangle(roofSizes.height, roofSizes.width, 0, {255, 51, 0}, 0, 0, '^');
    Border * border = new Border(borderSizes.width, borderSizes.height, {255,255,255}, 4, roofSizes.height, '#');
    Rectangle * body = new Rectangle(borderSizes.width - 2, borderSizes.height - 2,{255, 163, 0},5, roofSizes.height + 1, '@');
    Rectangle * windows[2] {
        new Rectangle(5,5, {25,25, 255}, body->getPosX() + 5, body->getPosY() + 1,'#'), 
        new Rectangle(5,5, {25,25, 255}, body->getPosX() + body->getMatrixWidth() - 10, body->getPosY() + 1,'#')
    };

    this->shapesArr[0] = roof;
    this->shapesArr[1] = border;
    this->shapesArr[2] = body;
    this->shapesArr[3] = windows[0];
    this->shapesArr[4] = windows[1];
}