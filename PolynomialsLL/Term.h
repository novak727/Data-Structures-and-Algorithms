#ifndef H_Term
#define H_Term

#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------
/* The struct Term creates a data type with 3 values: a coefficient integer,
* an exponent integer, and a pointer to the next Term for the Linked List
* implementation.
*/
struct Term
{
    int coeff;
    int exp;
    Term* next;
};
#endif // H_Term
