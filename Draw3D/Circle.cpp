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

Circle::Circle(Circle& copy) : Point(copy)
{
	this->radius = copy.radius;
}

vector<Point> Circle::getPoints()
{
	vector<Point> pointList;
	Point currentPoint(xAxis, yAxis - radius);

	//Top Right Quarter
	while (currentPoint.getXaxis() < xAxis + radius || currentPoint.getYaxis() < yAxis)
	{
		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation < 0)
			currentPoint.setXaxis(currentPoint.getXaxis() + 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() + 1);

		pointList.push_back(currentPoint);
	}
	cout << "1" << endl;
	//Bottom Right Quarter
	while (currentPoint.getXaxis() > xAxis || currentPoint.getYaxis() < yAxis + radius)
	{
		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation > 0)
			currentPoint.setXaxis(currentPoint.getXaxis() - 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() + 1);

		pointList.push_back(currentPoint);
	}

	cout << "2" << endl;
	//Bottom Left Quarter
	while (currentPoint.getXaxis() > xAxis - radius  || currentPoint.getYaxis() > yAxis)
	{
		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation < 0)
			currentPoint.setXaxis(currentPoint.getXaxis() - 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() - 1);

		pointList.push_back(currentPoint);
	}

	cout << "3" << endl;


	//Top Left Quarter
	while (currentPoint.getXaxis() < xAxis || currentPoint.getYaxis() > yAxis - radius)
	{
		float equation = pow(currentPoint.getXaxis() - xAxis, 2) + pow(currentPoint.getYaxis() - yAxis, 2) - pow(radius, 2);
		if (equation > 0)
			currentPoint.setXaxis(currentPoint.getXaxis() + 1);

		else
			currentPoint.setYaxis(currentPoint.getYaxis() - 1);

		pointList.push_back(currentPoint);
	}


	return pointList;
}
