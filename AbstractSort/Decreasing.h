#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
    #include "AbstractSort.h"
#endif // ABSTRACTSORT_H

//---------------------------------------------------------------------------
/* Decreasing
* This class is derived from AbstractSort, enabling the option to sort the
* array values in decreasing order.
* All of the AbstractSort class's methods are inherited, with this class
* overriding the compare method that was pure virtual in AbstractSort.
*/
class Decreasing : public AbstractSort
{
    public:
        bool compare(int, int);
};
