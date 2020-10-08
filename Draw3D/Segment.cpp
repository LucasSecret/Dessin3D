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
	Point currentPoint(start);

	//The 'a' in the y=ax + b
	float ratio = (end.getXaxis() - start.getXaxis()) / (end.getXaxis() - start.getXaxis()); 

	while (currentPoint.getXaxis() != end.getXaxis() || currentPoint.getYaxis() != end.getYaxis())
	{
		//ax + b - y = 0
		float equation = ratio*currentPoint.getXaxis() + start.getYaxis() - currentPoint.getYaxis();
		if (equation > 0) //so we're under the line
			currentPoint.setYaxis(currentPoint.getYaxis() + 1);
		else
			currentPoint.setXaxis(currentPoint.getXaxis() + 1);

		list.push_back(currentPoint);
	}

	return list;
}

Point Segment::getStartPoint() { return start; }
Point Segment::getEndPoint() { return end; }

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
