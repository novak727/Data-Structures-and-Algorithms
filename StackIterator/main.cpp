// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #4.5 - Make a Stack Iterator
// Date due: 09/25/2025
// Description: Creation of a stack with various values pushed and popped,
// then iterating through the stack to print out each value of the stack in
// its final form without modifying the stack.
// ---------------------------------------------------------------------------
#include <iostream>
#include "myStack.h"
#include "stackIterator.h"

using namespace std;

int main()
{
    stackType<int> stack1;
    stack1.push(6);
    stack1.push(12);
    stack1.pop();
    stack1.push(17);
    stack1.push(25);
    stack1.push(42);
    stack1.push(34);

    stackIterator<int> it = stack1.begin();

    for (it; it != stack1.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
