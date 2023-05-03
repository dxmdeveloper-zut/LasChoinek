#include "Forest.hpp"
#include <Drawables/Tree/Tree.hpp>
#include <Drawables/House/House.hpp>
#include "terminal.hpp"
#include <iostream>

// public:
//

Forest::Forest(size_t width, size_t height): width{width}, height{height}{
	//this->trees = std::vector<Choinka*>();
	this->matrix = new int * [height];
	for(size_t y = 0; y < height; y++)
		this->matrix[y] = new int [width];

	House * house = new House(25, 25);
	house->shapesCpy(this->shapesVec, this->matrix, this->width, this->height);
}

void Forest::addTree(size_t height, RGB color, char symbol, int x, int y) {
	Tree * tree = new Tree(height, color, x, y, symbol);
	tree->shapesCpy(this->shapesVec, this->matrix, this->width, this->height);
}

void Forest::printForest(){
	int buffVal = 0;
	//prepareMatrix();
	for(size_t y = 0; y < this->height; y++){
		for(size_t x = 0; x < this->width; x++){
			int val = this->matrix[y][x];
			if(val == 0) {
				std::cout << " ";
				if(!buffVal){
					std::cout << terminal::resetStylesEsc();
					buffVal = 0;
				}
			}
			else {
				Shape* shape = this->shapesVec.at(val-1);
				if(shape == nullptr) {std::cout << " "; continue;}
				if(buffVal != val){
					std::cout << terminal::setTextColorEsc(shape->getColor());
				}
				std::cout << shape->getSymbol();
			}
		}
		std::cout << std::endl;
	}
	std::cout << terminal::resetStylesEsc();
}

Forest::~Forest(){
	for (auto drawablep : graphicalObjectsVec) {
		delete drawablep;
	}
	if(this->matrix){
		for(size_t y = 0; y < this->height; y++) 
			delete[] this->matrix[y];
		delete [] this->matrix;
	}
}

// private:
//

/*
void Forest::prepareMatrix(){
	int i = 1;
	for(auto tree : this->trees){
		tree->matcpy(this->matrix, this->width, this->height, i);
		i++;
	}
}
*/