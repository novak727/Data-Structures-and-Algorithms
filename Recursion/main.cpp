// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #7
// Date due: 10/24/2025
// Description: Recursion demonstration by finding the largest digit of a
// number and finding how much change you have.
// ---------------------------------------------------------------------------
#include <iostream>
using namespace std;

int largestDigit(int val);
void printChange(int amount);

int main()
{
    int num1 = 0;
    int num2 = 0;

    // prompt for value, verify is valid
    do
    {
        cout << "Enter a positive integer: ";
        cin >> num1;
        if (num1 <= 0)
        {
            cout << "Invalid input" << endl << endl;
        }
    } while (num1 <= 0);

    cout << "Largest Digit: " << largestDigit(num1) << endl << endl;

    // prompt for value, verify is valid
    do
    {
        cout << "Enter an amount in cents less than $1: ";
        cin >> num2;
        if (num2 <= 0 || num2 >= 100)
        {
            cout << "Invalid input" << endl << endl;
        }
    } while (num2 <= 0 || num2 >= 100);

    printChange(num2);

    return 0;
}

//---------------------------------------------------------------------------
/* largestDigit() takes an integer parameter and recursively finds the
* largest digit of the number.
*/
int largestDigit(int val)
{
    if (val < 10) // one digit left
    {
        return val;
    }
    else
    {
        int last = val % 10;
        int maxRemainder = largestDigit(val / 10); // eliminate rightmost digit
        if (last > maxRemainder)
        {
            return last;
        }
        else
        {
            return maxRemainder;
        }
    }
}

//---------------------------------------------------------------------------
/* printChange() takes an integer as a parameter and recursively prints out
* a character representing each coin that would be in someone's possession if
* they have the most of that type of coin.
*/
void printChange(int amount)
{
    if (amount <= 0) // no more change
    {
        return;
    }
    else if (amount >= 25) // Quarter(s)
    {
        cout << 'Q';
        printChange(amount - 25);
    }
    else if (amount >= 10) // Dime(s)
    {
        cout << 'D';
        printChange(amount - 10);
    }
    else if (amount >= 5) // Nickel
    {
        cout << 'N';
        printChange(amount - 5);
    }
    else // Penny(s)
    {
        cout << 'P';
        printChange(amount - 1);
    }
}
