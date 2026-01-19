#ifndef H_StackIterator
#define H_StackIterator

//---------------------------------------------------------------------------
/* stackIterator
* A templated class with various operators overloaded to be able to iterate
* through a stack.
* 2 attributes are created to represent the current index of the stack and
* to create a copy of the stack.
* The dereference, increment, and inequality operators are all overloaded, and
* a default constructor has been implemented which is used by the begin() and
* end() methods declared in the stackType class.
*/
template <class Type>
class stackIterator
{
    public:
        //-------------------------------------------------------------------
        /* Constructor for stackIterator class.
        */
        stackIterator(Type* ptr, int idx)
        {
            current = ptr;
            index = idx;
        }

        //-------------------------------------------------------------------
        /* Overloaded dereference operator for stackIterator class.
        */
        Type& operator*()
        {
            return current[index];
        }

        //-------------------------------------------------------------------
        /* Overloaded increment operator (prefix) for stackIterator class.
        */
        stackIterator<Type>& operator++()
        {
            --index;
            return *this;
        }

        //-------------------------------------------------------------------
        /* Overloaded inequality operator for stackIterator class to compare
        * the index of the two iterator objects.
        */
        bool operator!=(const stackIterator<Type>& right) const
        {
            return (index != right.index);
        }
    private:
        Type* current;
        int index;
};

#endif // H_StackIterator
