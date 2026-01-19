// -----------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Project #6
// Date due: 11/12/2025
// Description: Find the kth Order Statistic for any value k in an unordered
// list of integers.
// -----------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/***** WRITE YOUR FUNCTION DECLARATIONS HERE ****/
int kStat(int[], int, int);
int findVal(int[], int, int, int);
int partition(int[], int, int);
void printList(int[], int, int);

int main()
{
    const int SIZE = 25;
    int list[SIZE];

    srand(time(0));

    for(int i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 100;
    }

    cout << "Here is your random list of numbers." << endl;
    printList(list, 0, SIZE - 1);
    cout << endl << endl;

    int choice;
    int kval;
    cout << "Choose an option from the following list." << endl;
    cout << "\t 0: Quit" << endl;
    cout << "\t 1: Find a kth Statistic" << endl;
    cin >> choice;
    while (choice == 1)
    {
        cout << "Enter an integer value k." << endl;
        cin >> kval;

        cout << "The " << kval << "th Order Statistic is: ";
        cout << kStat(list, SIZE, kval - 1) << endl;

        cout << "-----" << endl;
        cout << "Selection: " << endl;
        cout << "\t 0: Quit" << endl;
        cout << "\t 1: Find a kth Statistic" << endl;
        cin >> choice;
    }
    return 0;
}

/***** WRITE YOUR FUNCTION IMPLEMENTATIONS HERE ****/

//------------------------------------------------------------------------------
/* kStat() checks to see that kval is a valid possible index for the array, then
* calls findVal() to recursively find the value.
*/
int kStat(int list[], int size, int k)
{
    if (k < 0 || k >= size)
    {
        cout << "Invalid input" << endl;
        return -1;
    }
    else
    {
        return findVal(list, 0, size - 1, k);
    }
}

//------------------------------------------------------------------------------
/* findVal() recursively looks to finds the value requested by the user.
*/
int findVal(int list[], int low, int high, int k)
{
    int pivotIndex = partition(list, low, high);

    if (pivotIndex == k)
    {
        return list[pivotIndex];
    }
    else if (pivotIndex > k)
    {
        return findVal(list, low, pivotIndex - 1, k);
    }
    else
    {
        return findVal(list, pivotIndex + 1, high, k);
    }
}

//------------------------------------------------------------------------------
/* partition() partially organizes portions of the array around the pivot based
*  on the recursive calls of findVal.
*/
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int lowIndex = low;

    for (int i = low; i <= high; i++)
    {
        if (list[i] < pivot)
        {
            swap(list[lowIndex], list[i]);
            lowIndex++;
        }
    }
    swap(list[lowIndex], list[high]);
    return lowIndex;
}

//------------------------------------------------------------------------------
/* printList() prints all values in the list.
*/
void printList(int list[], int low, int high)
{
    for(int i = low; i <= high; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
