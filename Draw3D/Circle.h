#pragma once
#include <vector>
#include "ppm.h"
#include "Point.h"

class Circle :
    public Point
{
private : 
    float radius;

public:
    Circle();
    Circle(float x, float y, float z, float radius, int Color);
    Circle(float x, float y, float z, float radius);
    Circle(float x, float y, float radius);
    Circle(float radius);
    Circle(Circle& copy);

    void displayOn(Ppm& image);

    vector<Point> getPoints();
};

