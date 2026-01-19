#include <iostream>

#ifndef H_BT
#define H_BT
    #include "boxType.h"
#endif // H_BT

using namespace std;

void boxType::setDimension(double l, double w, double h)
{
    rectangleType::setDimension(l, w);
    height = h;
}

double boxType::getHeight()
{
    return height;
}

double boxType::area()
{
    return  2 * (getLength() * getWidth()
               + getLength() * height
               + getWidth() * height);
}

double boxType::volume()
{
    return rectangleType::area() * height;
}

void boxType::print()
{
    rectangleType::print();
    cout << "; Height = " << height;
}

boxType::boxType(double l, double w, double h)
    : rectangleType(l, w)
{
    height = h;
}
