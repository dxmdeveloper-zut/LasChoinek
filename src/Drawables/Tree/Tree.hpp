#include <Drawables/Drawable.hpp>

class Tree : public Drawable {
    public:
    Tree(size_t height, RGB color, int posX = 0, int posY = 0, char symbol='#');
};