#pragma once
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
    Circle(float x, float y);
    Circle(float radius);


    Circle(Circle& copy);


};

