#ifndef H_RT
#define H_RT
    #include "rectangleType.h"
#endif // H_RT

class boxType: public rectangleType
{
public:
    void setDimension(double l, double w, double h);
    double getHeight();
    double area();
    double volume();
    void print();
    boxType(double l = 0, double w = 0, double h = 0);

private:
    double height;
};
