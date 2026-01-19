#include <iostream>
using namespace std;

#ifndef H_FB
#define H_FB
    #include "FizzBuzz.h"
#endif


FizzBuzz::FizzBuzz(int l)
{
    limit = l;
}

void FizzBuzz::run()
{
    for(int i = 1; i <= limit; i++)
    {
        if(i % 5 == 0 && i % 3 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if(i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else if(i % 5 == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}

void FizzBuzz::setLimit()
{
   cout << endl;
   cout << "Enter the new limit for the game: " << endl;
   cin >> limit;
   cout << "Limit set to: " << limit << endl;
   cout << endl;
}

int FizzBuzz::menu()
{
   int choice;
   cout << "Menu: " << endl;
   cout << "\t 1. Run the game. " << endl;
   cout << "\t 2. Set the new limit value. " << endl;
   cout << "\t 3. Quit." << endl;
   cout << "Enter your choice: ";
   cin >> choice;
   return choice;
}

