#include <iostream>
#include <string>
using namespace std;

#ifndef H_FB
#define H_FB
    #include "FizzBuzz.h"
#endif // H_FB

using namespace std;

class FizzBuzzExt : public FizzBuzz
{
    public:
        FizzBuzzExt(int);
        void clear();
        void addRule();
        int menu();
        void run();
    private:
        int* mults;
        string* words;
        int numRules;
};
