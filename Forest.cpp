#include "Forest.hpp"
#include "terminal.hpp"
#include <iostream>

// public:
//

Forest::Forest(size_t width, size_t height): width{width}, height{height}{
	//this->trees = std::vector<Choinka*>();
	this->matrix = new int * [height];
	for(size_t y = 0; y < height; y++)
		this->matrix[y] = new int [width];
}

void Forest::addTree(size_t height, RGB color, char symbol, int x, int y) {
	Choinka* tree = new Choinka(height, color, symbol);
	tree->setPosition(x, y);
	tree->matcpy(this->matrix, this->width, this->height, this->trees.size());

	this->trees.push_back(tree);
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
				Choinka * tree = this->trees.at(val-1);
				if(buffVal != val){
					std::cout << terminal::setTextColorEsc(tree->getColor());
				}
				std::cout << tree->getSymbol();
			}
		}
		std::cout << std::endl;
	}
	std::cout << terminal::resetStylesEsc();
}

Forest::~Forest(){
	for (auto &tree : trees) {
		delete tree;
	}
	if(this->matrix){
		for(size_t y = 0; y < this->height; y++) 
			delete[] this->matrix[y];
		delete [] this->matrix;
	}
}

// private:
//

void Forest::prepareMatrix(){
	int i = 1;
	for(auto tree : this->trees){
		tree->matcpy(this->matrix, this->width, this->height, i);
		i++;
	}
}