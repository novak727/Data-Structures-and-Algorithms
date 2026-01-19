#include <iostream>
#include <iomanip>

#ifndef H_RT
#define H_RT
    #include "rectangleType.h"
#endif // H_RT

#ifndef H_BT
#define H_BT
    #include "boxType.h"
#endif // H_BT

using namespace std;

int main()
{
    rectangleType myRectangle1;
    rectangleType myRectangle2(8, 6);

    boxType myBox1;
    boxType myBox2(10, 7, 3);

    cout << fixed << showpoint << setprecision(2);

    cout << "Line 13: myRectangle1: ";
    myRectangle1.print();
    cout << endl;
    cout << "Line 16: Area of myRectangle1: "
         << myRectangle1.area() << endl;

    cout << "Line 17: myRectangle2: ";
    myRectangle2.print();
    cout << endl;
    cout << "Line 20: Area of myRectangle2: "
         << myRectangle2.area() << endl;

    cout << "Line 21: myBox1: ";
    myBox1.print();
    cout << endl;
    cout << "Line 24: Surface Area of myBox1: "
         << myBox1.area() << endl;
    cout << "Line 25: Volume of myBox1: "
         << myBox1.volume() << endl;

    cout << "Line 26: myBox2: ";
    myBox2.print();
    cout << endl;
    cout << "Line 29: Surface Area of myBox2: "
         << myBox2.area() << endl;
    cout << "Line 30: Volume of myBox2: "
         << myBox2.volume() << endl;

    return 0;
}
