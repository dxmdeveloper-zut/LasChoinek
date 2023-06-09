#pragma once
#include <vector>
#include <Shapes/Shape.hpp>
#include <Drawables/Drawable.hpp>

class Forest
{
public:
	~Forest();
	Forest(size_t width, size_t height);
	void addTree(size_t height, RGB color, char symbol, int x, int y);
	void printForest();

private:
	void rebuildShapesVec(); // ! NOT IMPLEMENTED YET
	void recreateMatrix(); // ! NOT IMPLEMENTED YET

	size_t width, height;
	int ** matrix;
	std::vector<Shape*> shapesVec;
	std::vector<Drawable*> graphicalObjectsVec;
};

