#include "Circle.h"

Circle::Circle() : Point()
{ 
	this->radius = 0;
}

Circle::Circle(float x, float y, float z, float radius, int color) : Point(x, y, z, color)
{
	this->radius = radius;
}

Circle::Circle(float x, float y, float z, float radius) : Point(x, y, z)
{
	this->radius = radius;
}

Circle::Circle(float x, float y, float radius) : Point(x, y)
{
	this->radius = radius;
}

Circle::Circle(float radius) : Point()
{
	this->radius = radius;
}
