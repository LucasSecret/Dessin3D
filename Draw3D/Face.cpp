#include "Face.h"

SquareFace::SquareFace()
{
	segments = new Segment[numberOfSegment];
	color = GREEN;
}

SquareFace::SquareFace(Segment* segments)
{
	color = GREEN;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

}

SquareFace::SquareFace(vector<Segment> segments)
{
	color = GREEN;

	this->segments = new Segment[numberOfSegment];

	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];
}

SquareFace::SquareFace(Segment* segments, int color)
{
	this->color = color;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];

}

SquareFace::SquareFace(vector<Segment> segments, int color)
{
	this->color = color;

	this->segments = new Segment[numberOfSegment];
	for (int i = 0; i < numberOfSegment; i++)
		this->segments[i] = segments[i];
}

SquareFace::SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4)
{
	color = GREEN;

	segments = new Segment[numberOfSegment];
	segments[0] = seg1;
	segments[1] = seg2;
	segments[2] = seg3;
	segments[3] = seg4;

}

SquareFace::SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4, int color)
{
	this->color = color;

	segments = new Segment[numberOfSegment];
	segments[0] = seg1;
	segments[1] = seg2;
	segments[2] = seg3;
	segments[3] = seg4;

}

SquareFace::SquareFace(Point p1, Point p2, Point p3, Point p4)
{
	color = GREEN;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(p1,p2);
	segments[1] = Segment(p2, p3);
	segments[2] = Segment(p3, p4);
	segments[3] = Segment(p4, p1);
}

SquareFace::SquareFace(Point p1, Point p2, Point p3, Point p4, int color)
{
	this->color = color;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(p1, p2);
	segments[1] = Segment(p2, p3);
	segments[2] = Segment(p3, p4);
	segments[3] = Segment(p4, p1);
}

SquareFace::SquareFace(Point point, int width, int color)
{

	this->color = color;
	segments = new Segment[numberOfSegment];
	segments[0] = Segment(Point(point.getXaxis(), point.getYaxis(), point.getZaxis()), Point(point.getXaxis() + width, point.getYaxis(), point.getZaxis()), color);
	segments[1] = Segment(Point(point.getXaxis() + width, point.getYaxis(), point.getZaxis()), Point(point.getXaxis() + width, point.getYaxis() + width, point.getZaxis()), color);
	segments[2] = Segment(Point(point.getXaxis() + width, point.getYaxis() + width, point.getZaxis()), Point(point.getXaxis(), point.getYaxis() + width, point.getZaxis()), color);
	segments[3] = Segment(Point(point.getXaxis(), point.getYaxis() + width, point.getZaxis()), Point(point.getXaxis(), point.getYaxis(), point.getZaxis()), color);
}


int SquareFace::getWidth()
{
	int i = 0;
	int maxX = 0, minX = 0;
	
	while (minX == maxX)
	{
		minX = segments[i].getStartPoint().getXaxis();
		maxX = segments[i].getEndPoint().getXaxis();
	}

	return abs(maxX - minX);
}


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

Point SquareFace::getCenter()
{
	int xAverage = 0, yAverage = 0;
	for (int i = 0; i < numberOfSegment; i++)
	{
		xAverage += segments[i].getMiddle().getXaxis();
		yAverage += segments[i].getMiddle().getYaxis();
	}

	return Point(xAverage, yAverage);
}


void SquareFace::translate(float xOffset, float yOffset, float zOffset)
{
	for (int i = 0; i < numberOfSegment; i++)
		segments[i].translate(xOffset, yOffset, zOffset);

}

void SquareFace::rotate(double alpha, double beta, double gamma)
{
	for (int i = 0; i < numberOfSegment; i++)
		segments[i].rotate(alpha, beta, gamma);
	
}

void SquareFace::displayEdgesOn(Ppm& image)
{
	for (int i = 0; i < numberOfSegment; i++)
		segments[i].displayOn(image);
	
}

bool SquareFace::pointIsOnEdge(Point point)
{
	for (int i = 0; i < numberOfSegment; i++)
	{
		if (point.getXaxis() == segments[i].getStartPoint().getXaxis()
			|| point.getYaxis() == segments[i].getStartPoint().getYaxis())
			return true;
	}

	return false;
}

int SquareFace::displayFaceRecursively(bool** pointsDisplayed, Point topLeftCorner, Point currentPoint, Ppm& image)
{
	if(pointIsOnEdge(currentPoint))
		return 0;
	
	int x = currentPoint.getXaxis() - topLeftCorner.getXaxis();
	int y = currentPoint.getYaxis() - topLeftCorner.getYaxis();

	if (pointsDisplayed[x][y])
		return 0;

	if (!currentPoint.isOutOfBounds(image))
	{
		image.setpixel(currentPoint.getXaxis(), currentPoint.getYaxis(), color);
		pointsDisplayed[x][y] = true;
	}

	else { return 0; }

	displayFaceRecursively(pointsDisplayed, topLeftCorner, currentPoint.getNorthNeighbor(), image);
	displayFaceRecursively(pointsDisplayed, topLeftCorner, currentPoint.getEastNeighbor(), image);
	displayFaceRecursively(pointsDisplayed, topLeftCorner, currentPoint.getSouthNeighbor(), image);
	displayFaceRecursively(pointsDisplayed, topLeftCorner, currentPoint.getWestNeighbor(), image);

	return 0;
}

void SquareFace::displayFullFaceOn(Ppm& image)
{
	int width = getWidth();
	bool** arePointDisplayed = new bool* [width+1];

	Point centerPoint = getCenter();

	cout << "Oui";
	centerPoint.displayOn(image);


	Point topLeftPoint = getLeftCorner();

	Point currentPoint = centerPoint;

	/*
	for(int i=0; i<width+1; i++)
	{
		arePointDisplayed[i] = new bool[width+1];
		
		for (int j = 0; j < width+1; j++)
		{
			if(i==0 || i == width || j==0 || j== width)
				arePointDisplayed[i][j] = true; //set the border colored

			else
				arePointDisplayed[i][j] = false;
		}
	}

	displayFaceRecursively(arePointDisplayed, topLeftPoint, currentPoint, image);
	*/
}



