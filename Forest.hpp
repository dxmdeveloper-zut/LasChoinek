#pragma once
#include <vector>
#include "choinka.hpp"
class Forest
{
public:
	~Forest();
	Forest(size_t width, size_t height);
	void addTree(size_t height, RGB color, char symbol, int x, int y);
	void printForest();

private:
	void prepareMatrix();

	size_t width, height;
	int ** matrix;
	std::vector<Choinka*> trees;
};

