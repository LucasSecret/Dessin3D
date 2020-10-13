#include "Circle.h"

Circle::Circle() : Point()
{ 
	this->radius = 0;
}

Circle::Circle(float x, float y, float z, float radius, int color) : Point(x, y, z, color)
{
	this->radius = radius;
}
																//avoid ambigus constructor
Circle::Circle(float x, float y, float z, float radius) : Point((SHORT)x, (SHORT)y, (SHORT)z)
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

Circle::Circle(Circle& copy) : Point(copy)
{
	this->radius = copy.radius;
}

void Circle::displayOn(Ppm& image)
{
	vector<Point> pointList = getPoints();
	for (int i = 0; i < pointList.size(); i++)
		image.setpixel(pointList[i].getXaxis(), pointList[i].getYaxis(), pointList[i].getColor());

	cout << "--Circle displayed" << endl;
}



vector<Point> Circle::getPoints()
{
	vector<Point> pointList;
	Point currentPoint(xAxis, yAxis - radius, 0, color);

	//Top Right Quarter
	while (currentPoint.getXaxis() < xAxis + radius || currentPoint.getYaxis() < yAxis)
	{
		pointList.push_back(currentPoint);

		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation < 0)
			currentPoint.setXaxis(currentPoint.getXaxis() + 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() + 1);

	}

	//Bottom Right Quarter
	while (currentPoint.getXaxis() > xAxis || currentPoint.getYaxis() < yAxis + radius)
	{
		pointList.push_back(currentPoint);

		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation > 0)
			currentPoint.setXaxis(currentPoint.getXaxis() - 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() + 1);

	}

	//Bottom Left Quarter
	while (currentPoint.getXaxis() > xAxis - radius  || currentPoint.getYaxis() > yAxis)
	{
		pointList.push_back(currentPoint);

		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation < 0)
			currentPoint.setXaxis(currentPoint.getXaxis() - 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() - 1);

	}

	//Top Left Quarter
	while (currentPoint.getXaxis() < xAxis || currentPoint.getYaxis() > yAxis - radius)
	{
		pointList.push_back(currentPoint);

		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation > 0)
			currentPoint.setXaxis(currentPoint.getXaxis() + 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() - 1);

	}

	return pointList;
}
