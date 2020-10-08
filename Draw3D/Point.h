#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Point
{
protected:
	float xAxis;
	float yAxis;
	float zAxis;


public:
	Point();
	Point(float x, float y);

	float getXaxis();
	float getYaxis();
	void setXaxis(float x);
	void setYaxis(float y);

	void homotethia(double ratio);
	void rotation(double angle);
	float rho();
	float teta();
	void move(int xOffset, int yOffset);

	void display();
};

