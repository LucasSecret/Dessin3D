#pragma once
#include <iostream>
#include <math.h>
#include "ColorDefinition.h"
#include "ppm.h"

using namespace std;

class Point
{
private :
	double** getXRotationMatrix(double angle);
	double** getYRotationMatrix(double angle);
	double** getZRotationMatrix(double angle);
	void rotateWithMatrix(double** matrix);

protected:
	int xAxis;
	int yAxis;
	int zAxis;
	int color;
	bool isDisplayed;


public:
	Point();
	Point(SHORT x, SHORT y, SHORT z);
	Point(SHORT x, SHORT y, SHORT z, int color);
	Point(SHORT x, SHORT y, int color);
	Point(SHORT x, SHORT y);
	Point(const Point& copy);


	int getXaxis();
	int getYaxis();
	int getZaxis();
	int   getColor();
	bool isAlreadyDisplayed();
	void setXaxis(int x);
	void setYaxis(int y);
	void setZaxis(int z);
	void setColor(int color);

	bool isOutOfBounds(Ppm& image);

	void homotethia(double ratio);

	void rotate(double alpha, double beta, double gamma);
	void Xrotation(double angle);
	void Yrotation(double angle);
	void Zrotation(double angle);

	void translate(float xOffset, float yOffset, float zOffset);

	Point getNorthNeighbor();
	Point getEastNeighbor();
	Point getSouthNeighbor();
	Point getWestNeighbor();


	Point& operator+(Point& point);
	bool operator==(const Point& point) const;

	void displayOn(Ppm& image);
	friend ostream& operator<<(ostream& stream, Point& point);
};

