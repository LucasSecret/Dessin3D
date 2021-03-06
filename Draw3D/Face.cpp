#include "Face.h"

SquareFace::SquareFace()
{
	segments = new Segment[numberOfSegment];
	color = GREEN;
	center = Point();
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
	segments[0] = Segment(p1,p2, color);
	segments[1] = Segment(p2, p3, color);
	segments[2] = Segment(p3, p4, color);
	segments[3] = Segment(p4, p1, color);
	calculateCenter();
}

SquareFace::SquareFace(Point p1, Point p2, Point p3, Point p4, int color)
{
	this->color = color;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(p1, p2, color);
	segments[1] = Segment(p2, p3, color);
	segments[2] = Segment(p3, p4, color);
	segments[3] = Segment(p4, p1, color);
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

int SquareFace::getDepthAverage()
{
	int zAverage=0;
	for (int i = 0; i < numberOfSegment; i++)
		zAverage += segments[i].getStartPoint().getZaxis();
	
	return zAverage / numberOfSegment;
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
	int xOffset = center.getXaxis();
	int yOffset = center.getYaxis();

	for (int i = 0; i < numberOfSegment; i++)
		segments[i].rotate(alpha, beta, gamma);

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

bool SquareFace::faceIsVisible()
{
	for (int i = 0; i < numberOfSegment; i++)
	{
		if (segments[i].getStartPoint().getXaxis() == segments[i].getEndPoint().getXaxis()
			&& segments[i].getStartPoint().getYaxis() == segments[i].getEndPoint().getYaxis())
			return false;
	}

	return true;
}

int SquareFace::displayFaceRecursively(vector<Point>& displayedPoint, Point currentPoint, Ppm& image)
{
	/*If face is only on zAxis, no try to display 
	(if the cube has no rotation and the face is not the front one or the back one) */
	if (!faceIsVisible())
		return 0;
	//avoid program exit
	if (!currentPoint.isOutOfBounds(image))
	{
		image.setpixel(currentPoint.getXaxis(), currentPoint.getYaxis(), color);
		displayedPoint.push_back(currentPoint);
	}
	else return 0;

	//Check if the point is on the border 
	if (pointIsOnEdge(currentPoint))
		return 0;

	//Check if neighbors are already displayed before to call or not the method
	if (!pointIsAlreadyDisplayed(displayedPoint, currentPoint.getNorthNeighbor()))
		displayFaceRecursively(displayedPoint, currentPoint.getNorthNeighbor(), image);

	if(!pointIsAlreadyDisplayed(displayedPoint, currentPoint.getEastNeighbor()))
		displayFaceRecursively(displayedPoint, currentPoint.getEastNeighbor(), image);

	if (!pointIsAlreadyDisplayed(displayedPoint, currentPoint.getSouthNeighbor()))
		displayFaceRecursively(displayedPoint, currentPoint.getSouthNeighbor(), image);

	if (!pointIsAlreadyDisplayed(displayedPoint, currentPoint.getWestNeighbor()))
		displayFaceRecursively(displayedPoint, currentPoint.getWestNeighbor(), image);

	return 0;
}


void SquareFace::displayFullFaceOn(Ppm& image)
{
	vector<Point> displayedPoints;
	Point currentPoint = center;
	displayFaceRecursively(displayedPoints, currentPoint, image);
	cout << "--Full Square displayed" << endl;
}

SquareFace& SquareFace::operator=(const SquareFace& copy)
{
	color = copy.color;
	center = copy.center;
	for (int i = 0; i < numberOfSegment; i++)
		segments[i] = copy.segments[i];

	return *this;
}

SquareFace::~SquareFace()
{
	delete[] segments;
}



