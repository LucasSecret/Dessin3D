#include "Face.h"

SquareFace::SquareFace()
{
	segments = new Segment[numberOfSegment];
	color = GREEN;

	calculateCenter();
}

SquareFace::SquareFace(Segment* segments)
{
	color = GREEN;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

	calculateCenter();
}

SquareFace::SquareFace(vector<Segment> segments)
{
	color = GREEN;

	this->segments = new Segment[numberOfSegment];

	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

	calculateCenter();
}

SquareFace::SquareFace(Segment* segments, int color)
{
	this->color = color;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

	calculateCenter();

}

SquareFace::SquareFace(vector<Segment> segments, int color)
{
	this->color = color;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

	calculateCenter();
}

SquareFace::SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4)
{
	color = GREEN;

	segments = new Segment[numberOfSegment];
	segments[0] = seg1;
	segments[1] = seg2;
	segments[2] = seg3;
	segments[3] = seg4;

	calculateCenter();
}

SquareFace::SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4, int color)
{
	this->color = color;

	segments = new Segment[numberOfSegment];
	segments[0] = seg1;
	segments[1] = seg2;
	segments[2] = seg3;
	segments[3] = seg4;

	calculateCenter();
}

SquareFace::SquareFace(Point p1, Point p2, Point p3, Point p4)
{
	color = GREEN;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(p1,p2);
	segments[1] = Segment(p2, p3);
	segments[2] = Segment(p3, p4);
	segments[3] = Segment(p4, p1);
	calculateCenter();
}

SquareFace::SquareFace(Point p1, Point p2, Point p3, Point p4, int color)
{
	this->color = color;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(p1, p2);
	segments[1] = Segment(p2, p3);
	segments[2] = Segment(p3, p4);
	segments[3] = Segment(p4, p1);
	calculateCenter();
}

SquareFace::SquareFace(Point point, int width, int color)
{

	this->color = color;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(Point(point.getXaxis(), point.getYaxis(), point.getZaxis()), Point(point.getXaxis() + width, point.getYaxis(), point.getZaxis()), color);
	segments[1] = Segment(Point(point.getXaxis() + width, point.getYaxis(), point.getZaxis()), Point(point.getXaxis() + width, point.getYaxis() + width, point.getZaxis()), color);
	segments[2] = Segment(Point(point.getXaxis() + width, point.getYaxis() + width, point.getZaxis()), Point(point.getXaxis(), point.getYaxis() + width, point.getZaxis()), color);
	segments[3] = Segment(Point(point.getXaxis(), point.getYaxis() + width, point.getZaxis()), Point(point.getXaxis(), point.getYaxis(), point.getZaxis()), color);
	calculateCenter();
}

SquareFace::SquareFace(SquareFace& copy)
{
	this->color = copy.color;

	segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		segments[i] = copy.segments[i];
	
	center = copy.center;
}


int SquareFace::getWidth()
{
	int i = 0;
	int maxX = 0, minX = 0;
	
	while (minX == maxX)
	{
		minX = segments[i].getStartPoint().getXaxis();
		maxX = segments[i].getEndPoint().getXaxis();
		i++;
	}

	return abs(maxX - minX);
}

//TODO -> Delete it, unsued method
Point SquareFace::getLeftCorner()
{
	int minX = segments[0].getStartPoint().getXaxis();
	int minY = segments[0].getStartPoint().getYaxis();
	int minZ = segments[0].getStartPoint().getZaxis();

	for (int i = 0; i < numberOfSegment; i++)
	{
		if (minX > segments[i].getStartPoint().getXaxis())
		{
			minX = segments[i].getStartPoint().getXaxis();
			minY = segments[i].getStartPoint().getYaxis();
		}
	}		

	return Point(minX, minY, minZ);
}

void SquareFace::calculateCenter()
{
	int xAverage = 0, yAverage = 0, zAverage = 0;
	//Sum all the middle of segments composing the square, and the average point will be the center point 
	for (int i = 0; i < numberOfSegment; i++)
	{
		Point segmentMiddle = segments[i].getMiddle();
		xAverage += segmentMiddle.getXaxis();
		yAverage += segmentMiddle.getYaxis();
		zAverage += segmentMiddle.getZaxis();
	}

	center = Point(xAverage / numberOfSegment, yAverage / numberOfSegment, zAverage/ numberOfSegment);
}

Point SquareFace::getCenter()
{
	return center;
}


void SquareFace::translate(float xOffset, float yOffset, float zOffset)
{
	for (int i = 0; i < numberOfSegment; i++)
		segments[i].translate(xOffset, yOffset, zOffset);

	calculateCenter();
}

void SquareFace::rotate(double alpha, double beta, double gamma)
{
	for (int i = 0; i < numberOfSegment; i++)
	{
		segments[i].translate(-center.getXaxis(), -center.getYaxis(), 0);
		segments[i].rotate(alpha, beta, gamma);
		segments[i].translate(center.getXaxis(), center.getYaxis(), 0);
	}
	calculateCenter();
}

void SquareFace::displayEdgesOn(Ppm& image)
{
	for (int i = 0; i < numberOfSegment; i++)
		segments[i].displayOn(image);
	
	cout << "-Edge Square displayed" << endl;
}

bool pointIsAlreadyDisplayed(vector<Point> displayedPoint, Point currentPoint)
{
	for (int i = 0; i < displayedPoint.size(); i++)
	{
		if (displayedPoint[i] == currentPoint)
			return true;
	}

	return false;
}

bool SquareFace::pointIsOnEdge(Point point)
{
	for (int i = 0; i < numberOfSegment; i++)
	{
		if (segments[i].pointIsInSegment(point))
			return true;
	}

	return false;
}

int SquareFace::displayFaceRecursively(vector<Point>& displayedPoint, Point currentPoint, Ppm& image)
{
	if (pointIsAlreadyDisplayed(displayedPoint, currentPoint))
		return 0;

	if (pointIsOnEdge(currentPoint))
		return 0;
	

	//cout << "x : " << currentPoint.getXaxis() << "   y : " << currentPoint.getYaxis() << endl;
	if (!currentPoint.isOutOfBounds(image))
	{
		image.setpixel(currentPoint.getXaxis(), currentPoint.getYaxis(), color);
		displayedPoint.push_back(currentPoint);
	}
	else return 0; 

	displayFaceRecursively(displayedPoint, currentPoint.getNorthNeighbor(), image);
	displayFaceRecursively(displayedPoint, currentPoint.getEastNeighbor(), image);
	displayFaceRecursively(displayedPoint, currentPoint.getSouthNeighbor(), image);
	displayFaceRecursively(displayedPoint, currentPoint.getWestNeighbor(), image);

	return 0;
}

void SquareFace::displayFullFaceOn(Ppm& image)
{
	vector<Point> displayedPoints;
	Point currentPoint = center;
	cout << "Centre : " << endl << currentPoint;
	displayFaceRecursively(displayedPoints, currentPoint, image);
	cout << "--Full Square displayed" << endl;

}

SquareFace::~SquareFace()
{
	delete[] segments;
}



