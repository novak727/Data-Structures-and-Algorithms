#ifndef H_Poly
#define H_Poly

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "Term.h"

//---------------------------------------------------------------------------
/* Poly
* This class defines the ability to easily work with polynomials, being able
* to and and do operations with coefficients and exponents, as well as solve
* the polynomial using a value x.
*
* This class creates a single Term pointer, the head, referencing the first
* value in the Linked List.
*
* Available methods: Assignment operator, insertion and extraction operators,
* addition and subtraction operators, Print the polynomial in reverse, Search,
* Reset, Evaluate, Derivative calculation, and helpers for printing in reverse
* and copy constructor.
*/
class Poly
{
    public:
        Poly();
        Poly(const Poly&);

        friend istream& operator>>(istream&, Poly&);
        friend ostream& operator<<(ostream&, const Poly&);

        void Reset();
        int Evaluate(int);

        Poly operator+(const Poly&)const;
        Poly operator-(const Poly&)const;

        void Derivative();

        void Insert(int, int);

        Term* Search(int);

        void PrintReverse();

        Poly& operator=(const Poly&);

        ~Poly();

    private:
        Term* head;

        void recPrintRev(Term*);
        void copyList(const Poly& otherList);
};

#endif // H_Poly
