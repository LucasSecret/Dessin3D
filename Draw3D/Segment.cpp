#include "Segment.h"

Segment::Segment()
{
	start = Point();
	end = Point();
	color = BLUE;
}

Segment::Segment(Point start, Point end)
{
	this->start = start;
	this->end = end;
	color = BLUE;
	start.setColor(color);
	end.setColor(color);
}

Segment::Segment(Point start, Point end, int color)
{
	this->start = start;
	this->end = end;
	this->color = color;
	start.setColor(color);
	end.setColor(color);
}

vector<Point> Segment::getPoints()
{
	vector<Point> list;
	Point currentPoint;
	Point destination;
	cout << "\n\n\n----------------------------------------------\n\n\n";

	//Chose the left point as start, the top point if x is equal for the two points 
	if (start.getXaxis() < end.getXaxis() 
		|| (start.getXaxis() == end.getXaxis() && start.getYaxis() < end.getYaxis()))
	{
		currentPoint = start;
		destination = end;
		cout << "Start : " << currentPoint;
		cout << "Destination : " << end;
	}
	else
	{
		currentPoint = end;
		destination = start;
		cout << "Start : " << endl << currentPoint;
		cout << "Destination : " << endl << start;
	}
	
	currentPoint.setColor(color);
	//The 'a' in the y=ax + b
	double ratio;

	if (currentPoint.getXaxis() == destination.getXaxis())
		ratio = 0;
	else
		ratio = (double)(((double)end.getYaxis() - (double)start.getYaxis()) / ((double)end.getXaxis() - (double)start.getXaxis()));
		// a = yb - ya / xb - xa
	
	
	//cout << "Ratio : " << end.getYaxis() << "-" << start.getYaxis() << "/" << end.getXaxis()<< "-" << start.getXaxis() << "=" << ratio <<endl;

	//The 'b' in y=ax + b
	double b =  currentPoint.getYaxis() - ratio * currentPoint.getXaxis();

	while ((int)currentPoint.getXaxis() != (int)destination.getXaxis() || (int)currentPoint.getYaxis() != (int)destination.getYaxis())
	{
		//ax + b - y = 0
		double equation = ratio*currentPoint.getXaxis() + b - currentPoint.getYaxis();
		//cout << ratio << "*" << currentPoint.getXaxis() << " + " << start.getYaxis() << " - " << currentPoint.getYaxis() << " = " << equation;
		//cout << endl << equation << endl;
		if (ratio > 0)
		{
			if (equation > 0) //so we're under the line
				currentPoint.setYaxis(currentPoint.getYaxis() + 1);

			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}

		else if(ratio < 0)
		{
			if (equation <= 0) //so we're under the line
				currentPoint.setYaxis(currentPoint.getYaxis() - 1);
			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}
		//If ratio == 0, it means x or y ar equals for the two points
		else
		{
			if(currentPoint.getXaxis() == destination.getXaxis())
				currentPoint.setYaxis(currentPoint.getYaxis() + 1);
			
			else
				currentPoint.setXaxis(currentPoint.getXaxis() + 1);
		}
		
		list.push_back(currentPoint);
	}

	return list;
}

Point Segment::getStartPoint() { return start; }
Point Segment::getEndPoint() { return end; }

bool Segment::pointIsInSegment(Point p)
{
	vector<Point> segmentPoints = getPoints();
	for (int i = 0; i < segmentPoints.size(); i++)
	{
		if (p == segmentPoints[i])
			return true;
	}
	return false;
}

//If this segment crossing another, return true and the crossing point
pair<bool, Point> Segment::isCrossing(Segment segment)
{
	vector<Point> segmentCrossedPoints = segment.getPoints();
	vector<Point> thisPoints = getPoints();
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

	vector<Point> points = getPoints();
	cout << "Taille : "<< points.size();

	int middleSize = points.size()/2;

	return points[middleSize-1];
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
}


void Segment::rotate(double alpha, double beta, double gamma)
{
	start.rotate(alpha, beta, gamma);
	end.rotate(alpha, beta, gamma);
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

bool Segment::segmentIsOutOfBounds(Ppm& image)
{
	return 	(start.isOutOfBounds(image) || end.isOutOfBounds(image));

}

void Segment::displayOn(Ppm& image)
{
	if(!(start.isOutOfBounds(image) || end.isOutOfBounds(image)))
		image.line(start.getXaxis(), start.getYaxis(),
				end.getXaxis(), end.getYaxis(), 
				color);
}

ostream& operator<<(ostream& stream, Segment& segment)
{
	stream << "Point de depart :" << segment.start;
	stream << "Point d'arrivee :" << segment.end;

	return stream;
}
