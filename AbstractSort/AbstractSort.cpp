#include <iostream>
#include <random>
#include <utility>

#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
    #include "AbstractSort.h"
#endif // ABSTRACTSORT_H

using namespace std;

//---------------------------------------------------------------------------
/* Constructor that creates a dynamically allocated array with 10 values.
*/
AbstractSort::AbstractSort()
{
    nums = new int[SIZE];
}

//---------------------------------------------------------------------------
/* randomFill() uses the Mersenne Twister random number generator to generate
* random numbers from 1 to 100. Each time the program runs, new numbers will
* be generated.
*/
void AbstractSort::randomFill()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    for (int i = 0; i < SIZE; i++)
    {
        nums[i] = distrib(gen);
    }
}

//---------------------------------------------------------------------------
/* print() iterates through the array of values, printing them in the order
* they are stored in the array.
*/
void AbstractSort::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

//---------------------------------------------------------------------------
/* sort() uses a bubble sort algorithm to compare the values of the array.
* It checks each value in the array, and compares the value using the compare()
* method. If the result of compare() is true, the swap() function (from
* <utility>) is used to switch the values in the corresponding locations in the
* array. The version of compare() used is based on if the object defined is an
* Increasing object or a Decreasing object since compare() is a pure virtual
* method in this class.
*/
void AbstractSort::sort()
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (compare(nums[i], nums[j]))
            {
                swap(nums[i], nums[j]);
            }
        }
    }
}

//---------------------------------------------------------------------------
/* Destructor that deletes the dynamically allocated array nums.
*/
AbstractSort::~AbstractSort()
{
    delete[] nums;
}
