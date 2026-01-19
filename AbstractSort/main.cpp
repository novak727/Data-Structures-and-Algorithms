// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 09/16/2025
// Description: Sort an array of random integers in both increasing and
// decreasing order using derived classes.
// ---------------------------------------------------------------------------
#include <iostream>

#ifndef INCREASING_H
#define INCREASING_H
    #include "Increasing.h"
#endif // INCREASING_H

#ifndef DECREASING_H
#define DECREASING_H
    #include "Decreasing.h"
#endif // DECREASING_H

using namespace std;

int main()
{
    // Increasing test
    Increasing incVals;
    incVals.randomFill();
    cout << "Original array: ";
    incVals.print();
    incVals.sort();
    cout << "Sorted array (Increasing): ";
    incVals.print();
    cout << endl;

    // Decreasing test
    Decreasing decVals;
    decVals.randomFill();
    cout << "Original array: ";
    decVals.print();
    decVals.sort();
    cout << "Sorted array (Decreasing): ";
    decVals.print();
    cout << endl;
}
