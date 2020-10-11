#pragma once
#include <iostream>
#include <math.h>
#include "ColorDefinition.h"

using namespace std;

class Point
{
private :
	double** getXRotationMatrix(double angle);
	double** getYRotationMatrix(double angle);
	double** getZRotationMatrix(double angle);

	void rotate(double** matrix);

protected:
	float xAxis;
	float yAxis;
	float zAxis;
	int color;


public:
	Point();
	Point(float x, float y, float z);
	Point(float x, float y, float z, int color);
	Point(float x, float y, int color);
	Point(float x, float y);
	Point(const Point& copy);


	float getXaxis();
	float getYaxis();
	float getZaxis();
	int   getColor();
	void setXaxis(float x);
	void setYaxis(float y);
	void setZaxis(float z);
	void setColor(int color);


	void homotethia(double ratio);

	void rotation(double alpha, double beta, double gamma);
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

	friend ostream& operator<<(ostream& stream, Point& point);
};

