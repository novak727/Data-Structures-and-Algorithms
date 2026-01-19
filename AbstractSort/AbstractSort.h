//---------------------------------------------------------------------------
/* AbstractSort
* This abstract class defines routines to create, print, and sort a dynamically
* allocated array of integers with random values from 1 to 100.
* This class has 2 private attributes: an integer point for the array of
* values, and an integer to represent the size of the array.
* This class has a constructor and destructor, a routine to fill the array with
* random numbers from 1 to 100, a routine to print the array, and a pure virtual
* method to compare 2 values that are defined in inherited classes.
*/
class AbstractSort
{
    public:
        AbstractSort();
        void randomFill();
        void print();
        virtual bool compare(int, int) = 0; // pure virtual method
        void sort();
        virtual ~AbstractSort(); // must be virtual since this is an abstract class
    private:
        int* nums;
        static const int SIZE = 10;
};
