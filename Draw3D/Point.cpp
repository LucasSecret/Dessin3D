#include "Point.h"

#define M_PI 3.14159265358979323846


Point::Point()
{
	this->xAxis = 0;
	this->yAxis = 0;
	this->zAxis = 0;
	this->color = BLUE;
}

Point::Point(float x, float y, float z)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
	this->color = BLUE;
}

Point::Point(float x, float y, float z, int color)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
	this->color = color;
}

Point::Point(float x, float y, int color)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = 0;
	this->color = color;
}

Point::Point(float x, float y)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = 0;
	this->color = BLUE;
}

Point::Point(Point& copy)
{
	xAxis = copy.xAxis;
	yAxis = copy.yAxis;
	zAxis = copy.zAxis;
	color = copy.color;
}

float Point::getXaxis() { return xAxis; }
float Point::getYaxis() { return yAxis; }
float Point::getZaxis() { return zAxis; }
int   Point::getColor() { return color; }

void Point::setXaxis(float x) { this->xAxis = x; }
void Point::setYaxis(float y) { this->yAxis = y; }
void Point::setZaxis(float z) { this->zAxis = z; }
void Point::setColor(int y)   { this->color = color; }



void Point::homotethia(double ratio)
{
	xAxis *= ratio;
	yAxis *= ratio;
	zAxis *= ratio;
}


double** Point::getXRotationMatrix(double angle)
{
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++)
		matrix[i] = new double[3];

	matrix[0][0] = 1; matrix[0][1] = 0;          matrix[0][2] = 0;
	matrix[1][0] = 0; matrix[1][1] = cos(angle); matrix[1][2] = -sin(angle);
	matrix[2][0] = 0; matrix[2][1] = sin(angle); matrix[2][2] = cos(angle);
	
}

double** Point::getYRotationMatrix(double angle)
{
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++)
		matrix[i] = new double[3];

	matrix[0][0] = cos(angle);  matrix[0][1] = 0;          matrix[0][2] = sin(angle);
	matrix[1][0] = 0;           matrix[1][1] = 1;          matrix[1][2] = 0;
	matrix[2][0] = -sin(angle); matrix[2][1] = 0;          matrix[2][2] = cos(angle);

}

double** Point::getZRotationMatrix(double angle)
{
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++)
		matrix[i] = new double[3];

	matrix[0][0] = cos(angle); matrix[0][1] = -sin(angle); matrix[0][2] = 0;
	matrix[1][0] = sin(angle); matrix[1][1] = cos(angle);  matrix[1][2] = 0;
	matrix[2][0] = 0;          matrix[2][1] = 0;           matrix[2][2] = 1;

}

void Point::rotate(double** matrix)
{
	double x = xAxis * matrix[0][0] + yAxis * matrix[0][1] + zAxis * matrix[0][2];
	double y = xAxis * matrix[1][0] + yAxis * matrix[1][1] + zAxis * matrix[1][2];
	double z = xAxis * matrix[2][0] + yAxis * matrix[2][1] + zAxis * matrix[2][2];

	xAxis = x;
	yAxis = y;
	zAxis = z;	
}

void Point::Xrotation(double angle)
{
	angle *= (M_PI / 180);
	rotate(getXRotationMatrix(angle));
}

void Point::Yrotation(double angle)
{
	angle *= (M_PI / 180);
	rotate(getYRotationMatrix(angle));
}


void Point::Zrotation(double angle)
{
	angle *= (M_PI / 180);
	rotate(getZRotationMatrix(angle));
}




void Point::translate(int xOffset, int yOffset, int zOffset)
{
	xAxis += xOffset;
	yAxis += yOffset;
	zAxis += zOffset;
}

Point& Point::operator+(Point& point)
{
	Point p(xAxis + point.xAxis,
		yAxis + point.yAxis,
		zAxis + point.zAxis);
	return p;
}

bool Point::operator==(Point& point)
{
	if (xAxis == point.xAxis
		&& yAxis == point.xAxis
		&& zAxis == point.zAxis)
		return true;
	return false;
}

ostream& operator<<(ostream& stream, Point& point)
{
	cout << endl;
	cout << "Coordonnee x : " << point.xAxis << endl;
	cout << "Coordonnee y : " << point.yAxis << endl;
	cout << "Coordonnee z : " << point.zAxis << endl;
	cout << "Couleur : " << point.color << endl;
	cout << endl << endl;
}