#pragma once
#include "Segment.h"


class Face
{
private :
	vector<Segment> segments;

public :
	Face();
	Face(vector<Segment> segments);
	Face(Segment seg1, Segment seg2, Segment seg3, Segment seg4);
	Face(vector<Point> points);
	Face(Point p1, Point p2, Point p3, Point p4);


};

