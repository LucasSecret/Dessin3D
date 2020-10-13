#pragma once
#include "Face.h"

class Cube
{
private :
	SquareFace* faces;
	int numberOfFace = 6;

public :
	Cube();
	Cube(vector<SquareFace> faces);
	Cube(SquareFace face1, SquareFace face2, SquareFace face3, SquareFace face4, SquareFace face5, SquareFace face6);
	Cube(SquareFace* squareFace);

	SquareFace* getFaces();

	void translate(int xOffset, int yOffset, int zOffset);
	void rotate(int alpha, int beta, int gamma);

	void displayEdgesOn(Ppm& image);
	void displayFullOn(Ppm& image);


};

