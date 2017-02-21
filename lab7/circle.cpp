#include "circle.h"

Circle::Circle()
{ radius = 1; }

Circle::Circle(float r)
{ radius = r; }

Circle::~Circle() {}

float Circle::getRadius()
{ return radius; }

void Circle::setRadius(float r)
{ r = radius; }

float Circle::circumference()
{ return (2*3.14159*radius); }

float Circle::area()
{ return (3.14159*radius*radius); }
