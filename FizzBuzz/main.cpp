// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #1
// Date due: 08/26/2025
// Description: FizzBuzz game generator
// ---------------------------------------------------------------------------
#include <iostream>
#include "FizzBuzz.h"
using namespace std;

int menu();

int main()
{
    FizzBuzz game;
    int choice = 0;

    cout << "------------Welcome to FizzBuzz!------------" << endl << endl;

    do
    {
        choice = menu(); // get input from user
        switch(choice)
        {
            case 1: // Run FizzBuzz game
                game.run();
                break;
            case 2: // set new limit for FizzBuzz
                game.setLimit();
                break;
            case 3: // exit game, also results in breaking out of do-while loop
                cout << "Goodbye!" << endl;
                break;
            default: // Runs for any value that isn't 1, 2, or 3, including negatives
                cout << "Not a valid choice. Please try again." << endl << endl;
        }
    }
    while (choice != 3);

    return 0;
}

//---------------------------------------------------------------------------
/* menu() displays a menu of choices every time the user has the ability to
* input a choice on what they want to do for the game. After a limit has been
* set or the game has been run, the menu will appear again. The user input is
* returned to main() to be validated as a valid choice.
* INCOMING DATA: None
* OUTGOING DATA: 1 integer, representing the user's choice.
*/
int menu()
{
    int choice;
    cout << "1. Run FizzBuzz game" << endl;
    cout << "2. Set a new limit for FizzBuzz" << endl;
    cout << "3. Quit game" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}
