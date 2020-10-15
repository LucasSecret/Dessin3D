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
		this->faces[i] = squareFace[i];
}

Cube::Cube(Cube& copy)
{
	faces = new SquareFace[numberOfFace];
	for (int i = 0; i < numberOfFace; i++)
		faces[i] = copy.faces[i];
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

void Cube::sortFaces()
{
	for (int i = 0; i < numberOfFace; i++)
		cout << faces[i].getDepthAverage() << " ";

	for (int i = 0; i < numberOfFace; i++)
	{
		int minZcenter = faces[0].getDepthAverage();
		int position = 0;
		for (int j = 0; j < numberOfFace - i; j++)
		{
			if (faces[j].getDepthAverage() <= minZcenter)
			{
				//Find minimum depth
				minZcenter = faces[j].getDepthAverage();
				position = j;
			}
		}
		//And put it in the end of the tab
		SquareFace tempFace(faces[numberOfFace - i - 1]);
		faces[numberOfFace - i - 1] = faces[position];
		faces[position] = tempFace;
	}
	cout << endl;
	for (int i = 0; i < numberOfFace; i++)
		cout << faces[i].getDepthAverage() << " ";
	cout << endl;
}

void Cube::displayEdgesOn(Ppm& image)
{
	for (int i = 0; i < numberOfFace; i++)
		faces[i].displayEdgesOn(image);

	cout << "---Cube edges displayed" << endl;
}

void Cube::displayFullOn(Ppm& image)
{
	sortFaces();
	for (int i = 0; i < numberOfFace; i++)
	{
		faces[i].displayFullFaceOn(image);
		faces[i].displayEdgesOn(image);
	}
	cout << "---Cube displayed" << endl;
}

