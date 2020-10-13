#pragma once
#include "Point.h"
#include "ppm.h"
#include <vector>



class Segment
{
private :
	Point start, end;
	vector<Point> allPoints;
	int color;

	bool segmentIsOutOfBounds(Ppm& image);
	void calculateAllPoints();

public:
	Segment();
	Segment(Point start, Point end);
	Segment(Point start, Point end, int color);
	Segment(const Segment& copy);

	vector<Point> getAllPoints();
	Point getStartPoint();
	Point getEndPoint();

	bool pointIsInSegment(Point p);
	pair<bool, Point> isCrossing(Segment segment);
	Point getMiddle();

	void setStartPoint(Point start);
	void setEndPoint(Point end);
	void setColor(int color);

	void translate(float xOffset, float yOffset, float zOffset);

	void rotate(double alpha, double beta, double gamma);
	void xRotation(double angle);
	void yRotation(double angle);
	void zRotation(double angle);

	void displayOn(Ppm& image);

	friend ostream& operator<<(ostream& stream, Segment& segment);
};


