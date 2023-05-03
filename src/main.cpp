#include <iostream>
#include "Forest.hpp"
#include "terminal.hpp"
#include <random>
#include <Shapes/Triangle/Triangle.hpp>

#define FOREST_HEIGHT 80
#define FOREST_WIDTH 160

typedef uint8_t u8;

template<typename T>
T genRand(T min, T max){
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<T> dist(min, max);
    return dist(mt);
}

int main(int argc, char * argv[]){
    // ! UNIT TESTS !
    Triangle triangle(20, 40, 0 /*rotation to implement*/, {255, 0, 0}, '#');
    triangle.dbg_printMatrix();

    // ! ---------- !


    Forest forest(FOREST_WIDTH, FOREST_HEIGHT);
    const char symbols[] = {'#', '@', '#', '$', '^'};
    
    for(int i = 0; i < genRand(30, 45); i++){
        RGB color = {genRand<u8>(20, 255), genRand<u8>(100, 255), genRand<u8>(0, 255)};
        forest.addTree(genRand(5, 15), color, symbols[genRand(0, (int)sizeof(symbols)-1)], genRand(-2, FOREST_WIDTH-5), genRand(-2, FOREST_HEIGHT-5));
    }
    
    forest.printForest();

    return EXIT_SUCCESS;
}