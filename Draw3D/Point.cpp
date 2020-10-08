#include "Point.h"

#define M_PI 3.14159265358979323846


Point::Point()
{
	this->xAxis = 0;
	this->yAxis = 0;
	numberOfpoint++;
}

Point::Point(float x, float y)
{
	this->xAxis = x;
	this->yAxis = y;
	numberOfpoint++;
}

float Point::getXaxis() { return xAxis; }
float Point::getYaxis() { return yAxis; }

void Point::setXaxis(float x) { this->xAxis = x; }
void Point::setYaxis(float y) { this->yAxis = y; }



void Point::homotethia(double ratio)
{
	xAxis *= ratio;
	yAxis *= ratio;
}

void Point::rotation(double angle)
{
	angle *= (M_PI / 180);
	float newXAwis = xAxis * cos(angle) - yAxis * sin(angle);
	yAxis = xAxis * sin(angle) + yAxis * cos(angle);
	xAxis = newXAwis;
}


float Point::rho()
{
	return sqrt(pow(xAxis, 2) + pow(yAxis, 2));
}

float Point::teta()
{
	if (xAxis == 0)
		return 0;

	return atan2(yAxis, xAxis);
}

void Point::move(int xOffset, int yOffset)
{
	xAxis += xOffset;
	yAxis += yOffset;
}

void Point::display()
{
	cout << endl;
	cout << "Coordonnee x : " << xAxis << endl;
	cout << "Coordonnee y : " << yAxis << endl;
	//cout << "Nombre de point : " << numberOfpoint 
	cout << endl << endl;
}
