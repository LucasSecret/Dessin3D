#include "Segment.h"

#define RESIZE_FACTOR 1.5

Segment::Segment()
{
	start = Point();
	end = Point();
	color = BLUE;
	calculateAllPoints();
}

Segment::Segment(Point start, Point end)
{
	this->start = start;
	this->end = end;
	this->color = color;
	start.setColor(color);
	end.setColor(color);
	calculateAllPoints();
}

Segment::Segment(Point start, Point end, int color)
{
	this->start = start;
	this->end = end;
	this->color = color;
	start.setColor(color);
	end.setColor(color);
	calculateAllPoints();
}

Segment::Segment(const Segment& copy)
{
	start = copy.start;
	end = copy.end;
	color = copy.color;
	allPoints = copy.allPoints;
}


//Calculate all points that have been made for the segment between start and end
void Segment::calculateAllPoints()
{
	allPoints.clear();
	Point currentPoint = start;
	Point destination = end;
	bool segmentOnZ = false;

	//Change x for z if x and y are equals
	if (start.getXaxis() == end.getXaxis()
		&& start.getYaxis() == end.getYaxis())
	{
		currentPoint.setXaxis(start.getZaxis());
		currentPoint.setYaxis(start.getYaxis());
		destination.setXaxis(end.getZaxis());
		destination.setYaxis(end.getYaxis());

		segmentOnZ = true;
	}


	//Chose the left point as start, the top point if x is equal for the two points 
	if (currentPoint.getXaxis() < destination.getXaxis()
		|| (currentPoint.getXaxis() == destination.getXaxis() && currentPoint.getYaxis() < destination.getYaxis()))
	{
		//cout << "Start : " << currentPoint;
		//cout << "Destination : " << end;
	}
	else
	{
		Point temp = currentPoint;
		currentPoint = destination;
		destination = temp;

		//cout << "Start : " << endl << currentPoint;
		//cout << "Destination : " << endl << start;
	}

	currentPoint.setColor(color);

	//The 'a' in the y=ax + b
	double ratio;

	//avoid division by zero
	if (currentPoint.getXaxis() == destination.getXaxis())
		ratio = 0;
	else
		ratio = (double)(((double)destination.getYaxis() - (double)currentPoint.getYaxis()) / ((double)destination.getXaxis() - (double)currentPoint.getXaxis()));
	    // a = yb - ya / xb - xa

	//The 'b' in y=ax + b
	double b = currentPoint.getYaxis() - ratio * currentPoint.getXaxis();

	while ((int)currentPoint.getXaxis() != (int)destination.getXaxis() || (int)currentPoint.getYaxis() != (int)destination.getYaxis())
	{
		//ax + b - y = 0
		double equation = ratio * currentPoint.getXaxis() + b - currentPoint.getYaxis();
		
		//Descending line
		if (ratio > 0)
		{
			if (equation > 0) //so we're under the line
				currentPoint.setYaxis(currentPoint.getYaxis() + 1);

			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}

		//Rising line
		else if (ratio < 0)
		{
			if (equation <= 0) //so we're under the line
				currentPoint.setYaxis(currentPoint.getYaxis() - 1);
			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}

		//If ratio == 0, it means x or y are equals for the two points (for straight line)
		else
		{
			if (currentPoint.getXaxis() == destination.getXaxis())
				currentPoint.setYaxis(currentPoint.getYaxis() + 1);

			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}

		Point result;

		//re-exchange x and z 
		if (segmentOnZ)
			result = Point(currentPoint.getZaxis(), currentPoint.getYaxis(),
				currentPoint.getXaxis());
		else
			result = currentPoint;

		allPoints.push_back(result);
		//cout << currentPoint << endl;
	}
}

vector<Point> Segment::getAllPoints() { return allPoints; }
Point Segment::getStartPoint() { return start; }
Point Segment::getEndPoint() { return end; }

//True if the point is a part of this segment
bool Segment::pointIsInSegment(Point p)
{
	for (int i = 0; i < allPoints.size(); i++)
	{
		if (p.getXaxis() == allPoints[i].getXaxis() && p.getYaxis() == allPoints[i].getYaxis())
			return true;
	}
	return false;
}

//If this segment crossing another, return true and the crossing point
pair<bool, Point> Segment::isCrossing(Segment segment)
{
	vector<Point> segmentCrossedPoints = segment.getAllPoints();
	vector<Point> thisPoints = getAllPoints();
	for (int i = 0; i < segmentCrossedPoints.size(); i++)
	{
		for (int j = 0; j < thisPoints.size(); j++)
		{
			if (segmentCrossedPoints[i] == thisPoints[j])
				return pair<bool, Point>(true, segmentCrossedPoints[i]);
		}
	}
	return pair<bool, Point>(false, Point(0,0));
}

//Get all points that have been made for the segment between start and end, and return the middle point
Point Segment::getMiddle()
{
	int middleSize = allPoints.size()/2;
	return allPoints[middleSize-1];
}

bool Segment::segmentIsOutOfBounds(Ppm& image)
{
	return 	(start.isOutOfBounds(image) || end.isOutOfBounds(image));
}

void Segment::setStartPoint(Point start) { this->start = start; }
void Segment::setEndPoint(Point end) { this->end = end; }
void Segment::setColor(int color)
{
	this->color = color;
	this->start.setColor(color);
	this->end.setColor(color);
}

void Segment::translate(float xOffset, float yOffset, float zOffset)
{
	start.translate(xOffset, yOffset, zOffset);
	end.translate(xOffset, yOffset, zOffset);
	calculateAllPoints();

}

void Segment::rotate(double alpha, double beta, double gamma)
{
	start.rotate(alpha, beta, gamma);
	end.rotate(alpha, beta, gamma);

	calculateAllPoints();
}

void Segment::xRotation(double angle)
{
	start.Xrotation(angle);
	end.Xrotation(angle);
}

void Segment::yRotation(double angle)
{
	start.Yrotation(angle);
	end.Yrotation(angle);
}

void Segment::zRotation(double angle)
{
	start.Zrotation(angle);
	end.Zrotation(angle);
}


void Segment::displayOn(Ppm& image)
{
	if (!(start.isOutOfBounds(image) || end.isOutOfBounds(image)))
		image.line(start.getXaxis(), start.getYaxis(),
			end.getXaxis(), end.getYaxis(),
			color);
	else
		cout << "!!! Warning : segment out of edges" << endl;
}

Segment& Segment::operator=(const Segment& copy) 
{
	start = copy.start;
	end = copy.end;
	color = copy.color;
	allPoints.clear();
	for (int i = 0; i < copy.allPoints.size(); i++)
		allPoints.push_back(copy.allPoints[i]);

	return *this;
}

ostream& operator<<(ostream& stream, Segment& segment)
{
	stream << "Point de depart :" << segment.start;
	stream << "Point d'arrivee :" << segment.end;

	return stream;
}
