#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

#include "stackADT.h"
#include "stackIterator.h"

using namespace std;

//---------------------------------------------------------------------------
/* stackType
* This class derives from the stackADT class while also implementing additional
* methods for further actions on the stack.
* 3 attributes are created with this class to represent the max size of the
* stack, the value at the top of the stack, and a pointer to the array holding
* the stack elements.
* This class has the ability to initialize a stack, check if the stack is full
* or empty, push and pop values to the stack, return the top element of the
* stack, and return iterators that point to the top and just past the bottom
* of a stack. A default constructor, copy constructor, and destructor are also
* defined, along with a method to handle creating copies of the stack for when
* the assignment operator is called and when the copy constructor is called.
*/
template <class Type>
class stackType: public stackADT<Type>
{
    public:
        //-------------------------------------------------------------------
        /* Overloaded assignment operator for the stackType class
        */
        const stackType<Type>& operator=(const stackType<Type>& otherStack)
        {
            if (this != &otherStack) // avoid self-copy
            {
                copyStack(otherStack);
            }

            return *this;
        } // end operator=

        //-------------------------------------------------------------------
        /* initializeStack() initializes the stack to an empty state by setting
        * the top to 0
        */
        void initializeStack()
        {
            stackTop = 0;
        } // end initializeStack

        //-------------------------------------------------------------------
        /* isEmptyStack() checks and returns whether or not the stack is
        * empty.
        */
        bool isEmptyStack() const
        {
            return (stackTop == 0);
        } // end isEmptyStack

        //-------------------------------------------------------------------
        /* isFullStack() checks and returns whether or not the stack is full.
        */
        bool isFullStack() const
        {
            return (stackTop == maxStackSize);
        } // end isFullStack

        //-------------------------------------------------------------------
        /* push() adds the parameter to the stack, if the stack is not full.
        */
        void push(const Type& newItem)
        {
            if (!isFullStack())
            {
                list[stackTop] = newItem;   // add newItem to the
                                            // top of the stack
                stackTop++; // increment stackTop
            }
            else
                cout << "Cannot add to a full stack." << endl;
        } // end push

        //-------------------------------------------------------------------
        /* top() returns the top element of the stack, if the stack is not
        * empty.
        */
        Type top() const
        {
            assert(stackTop != 0);      // if stack is empty,
                                        // terminate the program
            return list[stackTop - 1];  // return the element of the
                                        // stack indicated by
                                        // stackTop - 1
        } // end top

        //-------------------------------------------------------------------
        /* pop() removes the top element from the stack, if the stack isn't
        * empty.
        */
        void pop()
        {
            if (!isEmptyStack())
            {
                stackTop--;      // decrement stackTop
            }
            else
            {
                cout << "Cannot remove from an empty stack." << endl;
            }
        } // end pop

        //-------------------------------------------------------------------
        /* Constructor to create an array of the size stackSize, with the
        * default size being 100.
        */
        stackType(int stackSize = 100)
        {
            if (stackSize <= 0)
            {
                cout << "Size of the array to hold the stack must "
                     << "be positive." << endl;
                cout << "Creating an array of size 100." << endl;

                maxStackSize = 100;
            }
            else
            {
                maxStackSize = stackSize;   // set the stack size to
                                            // the value specified by
                                            // the parameter stackSize
            }

            stackTop = 0;                   // set stackTop to 0
            list = new Type[maxStackSize];  // create the array to
                                            // hold the stack elements
        } // end constructor

        //-------------------------------------------------------------------
        /* Copy constructor for stackType class
        */
        stackType(const stackType<Type>& otherStack)
        {
            list = nullptr;

            copyStack(otherStack);
        } // end copy constructor

        //-------------------------------------------------------------------
        /* Class destructor, removes all elements from the stack
        */
        ~stackType()
        {
            delete [] list; // deallocate the memory occupied
                            // by the array
        } // end destructor

        //-------------------------------------------------------------------
        /* begin() returns an iterator at the top element of the stack.
        */
        stackIterator<Type> begin() const
        {
            return stackIterator<Type>(list, stackTop - 1);
        }

        //-------------------------------------------------------------------
        /* end() returns an iterator just past the bottom of the stack.
        */
        stackIterator<Type> end() const
        {
            return stackIterator<Type>(list, -1);
        }

    private:
        int maxStackSize; // variable to store the maximum stack size
        int stackTop;     // variable to point to the top of the stack
        Type *list;       // pointer to the array that holds the
                          // stack elements

        //-------------------------------------------------------------------
        /* copyStack() makes a copy of the stack passed through the parameter.
        */
        void copyStack(const stackType<Type>& otherStack)
        {
            delete [] list;
            maxStackSize = otherStack.maxStackSize;
            stackTop = otherStack.stackTop;

            list = new Type[maxStackSize];

            // copy otherStack into this stack
            for (int j = 0; j < stackTop; j++)
                list[j] = otherStack.list[j];
        } // end copyStack
};

#endif
