#include "Point.h"

#define M_PI 3.14159265358979323846


Point::Point()
{
	this->xAxis = 0;
	this->yAxis = 0;
	this->zAxis = 0;
	this->color = BLUE;
	this->isDisplayed = false;
}

Point::Point(SHORT x, SHORT y, SHORT z)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
	this->color = BLUE;
	this->isDisplayed = false;
}

Point::Point(SHORT x, SHORT y, SHORT z, int color)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
	this->color = color;
	this->isDisplayed = false;
}

Point::Point(SHORT x, SHORT y)
{
	xAxis = x;
	yAxis = y;
	zAxis = 0;
	color = BLUE;
	isDisplayed = false;
}

Point::Point(const Point& copy)
{
	xAxis = copy.xAxis;
	yAxis = copy.yAxis;
	zAxis = copy.zAxis;
	color = copy.color;
	isDisplayed = false;
}

int Point::getXaxis() { return xAxis; }
int Point::getYaxis() { return yAxis; }
int Point::getZaxis() { return zAxis; }
int   Point::getColor() { return color; }
bool  Point::isAlreadyDisplayed() { return isDisplayed; }

void Point::setXaxis(int x) { this->xAxis = x; }
void Point::setYaxis(int y) { this->yAxis = y; }
void Point::setZaxis(int z) { this->zAxis = z; }
void Point::setColor(int y)   { this->color = color; }

bool Point::isOutOfBounds(Ppm& image)
{
	return (xAxis < 0 || xAxis >= image.getWidth() || yAxis < 0 || yAxis >= image.getHeight()) ;
}



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

	return matrix;
}

double** Point::getYRotationMatrix(double angle)
{
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++)
		matrix[i] = new double[3];

	matrix[0][0] = cos(angle);  matrix[0][1] = 0;          matrix[0][2] = sin(angle);
	matrix[1][0] = 0;           matrix[1][1] = 1;          matrix[1][2] = 0;
	matrix[2][0] = -sin(angle); matrix[2][1] = 0;          matrix[2][2] = cos(angle);

	return matrix;
}

double** Point::getZRotationMatrix(double angle)
{
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++)
		matrix[i] = new double[3];

	matrix[0][0] = cos(angle); matrix[0][1] = -sin(angle); matrix[0][2] = 0;
	matrix[1][0] = sin(angle); matrix[1][1] = cos(angle);  matrix[1][2] = 0;
	matrix[2][0] = 0;          matrix[2][1] = 0;           matrix[2][2] = 1;

	return matrix;
}

void Point::rotateWithMatrix(double** matrix)
{
	double x = xAxis * matrix[0][0] + yAxis * matrix[0][1] + zAxis * matrix[0][2];
	double y = xAxis * matrix[1][0] + yAxis * matrix[1][1] + zAxis * matrix[1][2];
	double z = xAxis * matrix[2][0] + yAxis * matrix[2][1] + zAxis * matrix[2][2];

	xAxis = x;
	yAxis = y;
	zAxis = z;	
}

void Point::rotate(double alpha, double beta, double gamma)
{
	Xrotation(alpha);
	Yrotation(beta);
	Zrotation(gamma);
}

void Point::Xrotation(double angle)
{
	angle *= (M_PI / 180);
	rotateWithMatrix(getXRotationMatrix(angle));
}

void Point::Yrotation(double angle)
{
	angle *= (M_PI / 180);
	rotateWithMatrix(getYRotationMatrix(angle));
}

void Point::Zrotation(double angle)
{
	angle *= (M_PI / 180);
	rotateWithMatrix(getZRotationMatrix(angle));
}



void Point::translate(float xOffset, float yOffset, float zOffset)
{
	xAxis += xOffset;
	yAxis += yOffset;
	zAxis += zOffset;
}

Point Point::getNorthNeighbor()
{
	Point p(xAxis, yAxis - 1, color);
	return p;
}

Point Point::getEastNeighbor()
{
	Point p(xAxis+1, yAxis, color);
	return p;
}

Point Point::getSouthNeighbor()
{
	Point p(xAxis, yAxis + 1, color);
	return p;
}

Point Point::getWestNeighbor()
{
	Point p(xAxis - 1, yAxis, color);
	return p;
}


Point& Point::operator+(Point& point)
{
	Point p(xAxis + point.xAxis,
		yAxis + point.yAxis,
		zAxis + point.zAxis);
	return p;
}

Point& Point::operator=(const Point& point)
{
	xAxis = point.xAxis;
	yAxis = point.yAxis;
	zAxis = point.zAxis;
	color = point.color;
	return *this;
}

bool Point::operator==(const Point& point) const
{
	if (xAxis == point.xAxis
		&& yAxis == point.yAxis
		&& zAxis == point.zAxis)
		return true;
	return false;
}

void Point::displayOn(Ppm& image)
{
	int z;
	
	if (zAxis != 0)
	{
		Point pointToDisplay((int)(xAxis + xAxis / zAxis), 
							 (int)(yAxis - yAxis / zAxis), 
							 zAxis);
	}
	else
		Point pointToDisplay(xAxis, yAxis, zAxis);

	
	if (!isOutOfBounds(image))
		image.setpixel(xAxis, yAxis, color);

}

ostream& operator<<(ostream& stream, Point& point)
{
	stream << "Coordonnee x : " << point.xAxis << endl;
	stream << "Coordonnee y : " << point.yAxis << endl;
	stream << "Coordonnee z : " << point.zAxis << endl;
	stream << "Couleur : " << point.color << endl;
	stream << endl << endl;

	return stream;
}
