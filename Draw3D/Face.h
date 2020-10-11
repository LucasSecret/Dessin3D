#pragma once
#include "Segment.h"
#include <map>


class SquareFace
{

private :
	Segment* segments;
	int numberOfSegment = 4;
	int color;

	int displayFaceRecursively(bool** pointsDisplayed, Point topLeftCorner, Point currentPoint, Ppm& image);
	
	bool pointIsOnEdge(Point point);

public :
	SquareFace();
	SquareFace(Segment* segments);
	SquareFace(vector<Segment> segments);
	SquareFace(Segment* segments, int color);
	SquareFace(vector<Segment> segments, int color);
	SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4);
	SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4, int color);
	SquareFace(Point p1, Point p2, Point p3, Point p4);
	SquareFace(Point p1, Point p2, Point p3, Point p4, int color);
	SquareFace(Point point, int width, int color);

	int getWidth();
	Point getLeftCorner();

	void translate(float xOffset, float yOffset, float zOffset);
	void rotate(double alpha, double beta, double gamma);

	void displayEdgesOn(Ppm& image);

	void displayFullFaceOn(Ppm& image);

};

