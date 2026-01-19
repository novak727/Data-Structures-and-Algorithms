#include <iostream>

#ifndef H_RT
#define H_RT
    #include "rectangleType.h"
#endif // H_RT

using namespace std;

void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0;

    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength()
{
    return length;
}

double rectangleType::getWidth()
{
    return width;
}

double rectangleType::area()
{
    return length * width;
}

double rectangleType::perimeter()
{
     return 2 * (length + width);
}

void rectangleType::print()
{
    cout << "Length = "  << length
         << "; Width = " << width;
}

rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w);
}
