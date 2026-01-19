#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
    #include "AbstractSort.h"
#endif // ABSTRACTSORT_H

//---------------------------------------------------------------------------
/* Increasing
* This class is derived from AbstractSort, enabling the option to sort the
* array values in increasing order.
* All of the AbstractSort class's methods are inherited, with this class
* overriding the compare method that was pure virtual in AbstractSort.
*/
class Increasing : public AbstractSort
{
    public:
        bool compare(int, int);
};
