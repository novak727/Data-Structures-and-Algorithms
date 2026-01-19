#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
/* FizzBuzz
* This class defines the FizzBuzz game, giving the ability to run the game
* and set the limit for how high the game will go, with a base limit of 100.
* The limit for the game is stored as an integer.
* Available Methods: Ability to run the FizzBuzz game and change how high of
* a number the game will run to.
*/

class FizzBuzz
{
    public:
        // The limit is assigned in the header to avoid an error.
        FizzBuzz(int = 100);
        void run() const;
        void setLimit();
    private:
        int limit;
};

#endif // FIZZ_H
