// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #0.5
// Date due: 08/26/2025
// Description: Linked List to represent a polynomial and perform various
// operations on the data.
// ---------------------------------------------------------------------------
#include <iostream>
#include "Poly.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream myfile ("poly.txt");

    Poly myPoly;

    /*
    * Insert values, where first value is the coefficient
    * and the second value is an exponent.
    */
    myPoly.Insert(5, 4);
    myPoly.Insert(3, 3);
    myPoly.Insert(17, 1);

    // Print out polynomial as it currently stands
    cout << myPoly << endl;

    // Evaluate the current polynomial for x=2
    cout << "Evaluate at x=2" << endl;
    cout << myPoly.Evaluate(2) << endl;

    // Insert additional values into polynomial
    myPoly.Insert(6, 8);
    myPoly.Insert(2, 6);

    // Test printing polynomial in reverse
    myPoly.PrintReverse();

    // Insert another value into polynomial
    myPoly.Insert(5, 0);
    cout << myPoly << endl;

    // Print out the memory location of the exponent in the parameter
    cout << myPoly.Search(6) << endl;
    cout << myPoly.Search(7) << endl;

    // Create a copy of the existing polynomial
    Poly copyPoly;
    copyPoly = myPoly;

    // Insert additional values into the copy of the Polynomial
    copyPoly.Insert(2, 2);
    copyPoly.Insert(9, 9);

    // Insert a value into the original Polynomial
    myPoly.Insert(7, 7);

    Poly result;
    // Print myPoly and copyPoly
    cout << myPoly << endl;
    cout << copyPoly << endl;

    // Addition operator test
    cout << "********Adding********" << endl;
    result = myPoly + copyPoly;
    cout << result << endl;
    cout << "****************" << endl;

    // Subtraction operator test
    cout << "********Subtracting********" << endl;
    result = myPoly - copyPoly;
    cout << result << endl;
    cout << "****************" << endl;

    // 1st Derivative test
    cout << "****************" << endl;
    cout << copyPoly << endl;
    cout << "Derivation One" << endl;
    copyPoly.Derivative();
    cout << copyPoly << endl;

    // 2nd Derivative test
    cout << "Derivation Two" << endl;
    copyPoly.Derivative();
    cout << copyPoly << endl;

    // 3rd Derivative test
    cout << "Derivation Three" << endl;
    copyPoly.Derivative();
    cout << copyPoly << endl;
    cout << "****************" << endl;

    // Test evaluation after reset
    myPoly.Reset();
    cout << myPoly << endl;
    cout << myPoly.Evaluate(2) << endl;
    cout << copyPoly << endl;

    // Extraction operator test using a loaded file with a polynomial
    cout << "********Use >>*******" << endl;
    Poly p3;
    //cin >> p3;
    myfile >> p3;
    cout << p3 << endl;

    myfile.close();
    return 0;
}
