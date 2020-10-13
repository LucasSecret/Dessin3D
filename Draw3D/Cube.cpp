#include "Cube.h"

Cube::Cube()
{
	faces = new SquareFace[numberOfFace];
}

Cube::Cube(vector<SquareFace> faces)
{
	this->faces = new SquareFace[numberOfFace];
	for (int i = 0; i < numberOfFace; i++)
		this->faces[i] = faces[i];
}

Cube::Cube(SquareFace face1, SquareFace face2, SquareFace face3, SquareFace face4, SquareFace face5, SquareFace face6)
{
	this->faces = new SquareFace[numberOfFace];
	faces[0] = face1;
	faces[1] = face2;
	faces[2] = face3;
	faces[3] = face4;
	faces[4] = face5;
	faces[5] = face6;
}

Cube::Cube(SquareFace* squareFace)
{
	this->faces = new SquareFace[numberOfFace];
	for (int i = 0; i < numberOfFace; i++)
		this->faces[i] = faces[i];
}

SquareFace* Cube::getFaces() { return faces; }

void Cube::translate(int xOffset, int yOffset, int zOffset)
{
	for (int i = 0; i < numberOfFace; i++)
		faces[i].translate(xOffset, yOffset, zOffset);
	
}

void Cube::rotate(int alpha, int beta, int gamma)
{
	for (int i = 0; i < numberOfFace; i++)
		faces[i].rotate(alpha, beta, gamma);
}

void Cube::displayEdgesOn(Ppm& image)
{
	for (int i = 0; i < numberOfFace; i++)
		faces[i].displayEdgesOn(image);

	cout << "---Cube edges displayed" << endl;

}

void Cube::displayFullOn(Ppm& image)
{
	for (int i = 0; i < numberOfFace; i++)
		faces[i].displayFullFaceOn(image);
	cout << "---Cube displayed" << endl;
}

