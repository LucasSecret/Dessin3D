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
	{
		segments[i].displayOn(image);
		
	}
}




