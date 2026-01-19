#include "FizzBuzz.h"

//---------------------------------------------------------------------------
/* Constructor for FizzBuzz class, setting the limit of the game to the
* default value assigned in the header.
*/
FizzBuzz::FizzBuzz(int lim)
{
    limit = lim;
}

//---------------------------------------------------------------------------
/* run() plays the FizzBuzz game, printing out either the number, Fizz, Buzz,
* or FizzBuzz based on the value of the number i.
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void FizzBuzz::run() const
{
    // Print out each value or the appropriate term based on divisibility
    for (int i = 1; i <= limit; i++)
    {
        /*
        * This first check has the same effect as checking both 3 and 5
        * since only multiples of 15 are divisible by both 3 and 5.
        */
        if (i % 15 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if (i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else if (i % 5 == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    cout << endl; // Final newline for cleaner printing of menu after gameplay
}

//---------------------------------------------------------------------------
/* setLimit() sets the highest value the FizzBuzz game will go to based on
* the number the user enters. It will repetitively ask the user for a number
* until a valid one is entered.
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void FizzBuzz::setLimit()
{
    int input = 0;

    // Will repeatedly run until a valid value is entered.
    do
    {
        cout << "Enter the limit value: ";
        cin >> input;

        if (input < 1) // data validation to avoid negatives or 0.
        {
            cout << "Not a valid value. Please try again." << endl << endl;
        }
        else
        {
            limit = input;
            cout << "Value recorded" << endl << endl;
        }
    }
    while (input < 1);
}
