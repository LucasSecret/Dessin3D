#pragma once
#include "Segment.h"


class SquareFace
{

private :
	Segment* segments;
	int numberOfSegment = 4;
	int color;

public :
	SquareFace();
	SquareFace(Segment* segments);
	SquareFace(vector<Segment> segments);
	SquareFace(Segment* segments, int color);
	SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4);
	SquareFace(Segment seg1, Segment seg2, Segment seg3, Segment seg4, int color);
	SquareFace(Point p1, Point p2, Point p3, Point p4);
	SquareFace(Point p1, Point p2, Point p3, Point p4, int color);

	void translate(float xOffset, float yOffset, float zOffset);
	void rotate(double alpha, double beta, double gamma);

	void displayEdgesOn(Ppm& image);


};

