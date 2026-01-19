#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

//---------------------------------------------------------------------------
/* linkedListIterator
* A templated iterator for a linked list
* One private attribute to store the current location in the linked list.
* Methods are available for various operators being overloaded, as well as a
* constructor with and without a parameter.
*/
template <class Type>
class linkedListIterator
{
    public:
        linkedListIterator();
        // Default constructor
        // Postcondition: current = nullptr;

        linkedListIterator(nodeType<Type> *ptr);
        // Constructor with a parameter.
        // Postcondition: current = ptr;

        Type operator*();
        // Function to overload the dereferencing operator *.
        // Postcondition: Returns the info contained in the node.

        linkedListIterator<Type> operator++();
        // Overload the pre-increment operator.
        // Postcondition: The iterator is advanced to the next
        //                node.

        bool operator==(const linkedListIterator<Type>& right) const;
        // Overload the equality operator.
        // Postcondition: Returns true if this iterator is equal to
        //                the iterator specified by right,
        //                otherwise it returns the value false.

        bool operator!=(const linkedListIterator<Type>& right) const;
        // Overload the not equal to operator.
        // Postcondition: Returns true if this iterator is not
        //                equal to the iterator specified by
        //                right; otherwise it returns the value
        //                false.

    private:
        nodeType<Type> *current; // pointer to point to the current
                                 // node in the linked list
};

//---------------------------------------------------------------------------
/* Constructor without parameter, sets current to nullptr.
*/
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

//---------------------------------------------------------------------------
/* Constructor with parameter, sets current to that pointer.
*/
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

//---------------------------------------------------------------------------
/* Multiplication operator overloading.
*/
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

//---------------------------------------------------------------------------
/* Increment operator overloading.
*/
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::
                                  operator++()
{
    current = current->link;

    return *this;
}

//---------------------------------------------------------------------------
/* Equality operator overloading.
*/
template <class Type>
bool linkedListIterator<Type>::operator==
               (const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

//---------------------------------------------------------------------------
/* Not equal to operator overloading.
*/
template <class Type>
bool linkedListIterator<Type>::operator!=
                 (const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}

//---------------------------------------------------------------------------
/* linkedListType
* A templated linked list.
* Attributes are available to store the length of the list and pointers to the
* first and last values of the list.
* Methods are available to create the linked list, destroy the linked list,
* check values at the front and back of the list, insert values into the list,
* check if the list is empty, return iterators at the beginning and end of the
* list, and print the values stored in the list.
*/
template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
                         (const linkedListType<Type>&);
      //Overload the assignment operator.

    void initializeList();
      //Initialize the list to an empty state.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    bool isEmptyList() const;
      //Function to determine whether the list is empty.
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none

    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    Type front() const;
      //Function to return the first element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first
      //               element of the list is returned.

    Type back() const;
      //Function to return the last element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last
      //               element of the list is returned.

    virtual bool search(const Type& searchItem) const = 0;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the
      //               list, otherwise the value false is
      //               returned.

    virtual void insertFirst(const Type& newItem) = 0;
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.

    virtual void insertLast(const Type& newItem) = 0;
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem
      //               is inserted at the end of the list,
      //               last points to the last node in the
      //               list, and count is incremented by 1.

    virtual void deleteNode(const Type& deleteItem) = 0;
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated
      //               list, and count is decremented by 1.

    linkedListIterator<Type> begin();
      //Function to return an iterator at the begining of
      //the linked list.
      //Postcondition: Returns an iterator such that current
      //               is set to first.

    linkedListIterator<Type> end();
      //Function to return an iterator one element past the
      //last element of the linked list.
      //Postcondition: Returns an iterator such that current
      //               is set to nullptr.

    linkedListType();
      //Default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    linkedListType(const linkedListType<Type>& otherList);
      //copy constructor

    ~linkedListType();
      //Destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed.

      nodeType<Type>* getFirst();

protected:
    int count;   //variable to store the number of
                 //elements in the list
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list

private:
    void copyList(const linkedListType<Type>& otherList);
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
};

//---------------------------------------------------------------------------
/* isEmptyList() checks if the list is empty and returns a boolean with the
* result of the check.
*/
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

//---------------------------------------------------------------------------
/* Default constructor for linkedListType class.
*/
template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

//---------------------------------------------------------------------------
/* destroyList() deletes all nodes from the linked list.
*/
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   // pointer to deallocate the memory
                            // occupied by the node
    while (first != nullptr)   // while there are nodes in
    {                          // the list
        temp = first;        // set temp to the current node
        first = first->link; // advance first to the next node
        delete temp;   // deallocate the memory occupied by temp
    }
    last = nullptr; // initialize last to nullptr; first has
               // already been set to nullptr by the while loop
    count = 0;
}

//---------------------------------------------------------------------------
/* initializeList() calls destroyList() which deletes all nodes in the linked
* list.
*/
template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //cif the list has any nodes, delete them
}

//---------------------------------------------------------------------------
/* print() outputs the data in each node of the linked list.
*/
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; // pointer to traverse the list

    current = first;    // set current so that it points to
                        // the first node
    while (current != nullptr) // while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
} // end print

//---------------------------------------------------------------------------
/* length() returns the length of the linked list.
*/
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
} // end length

//---------------------------------------------------------------------------
/* front() returns the first element of the list.
*/
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != nullptr);

    return first->info; // return the info of the first node
} // end front

//---------------------------------------------------------------------------
/* back() returns the last element of the list.
*/
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr);

    return last->info; // return the info of the last node
} // end back

//---------------------------------------------------------------------------
/* begin() returns an iterator at the beginning of the linked list.
*/
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}

//---------------------------------------------------------------------------
/* end() returns an iterator one element past the last element of the linked
* list.
*/
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);

    return temp;
}

//---------------------------------------------------------------------------
/* copyList() makes a copy of the linked list parameter.
*/
template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list

    if (first != nullptr) // if the list is nonempty, make it empty
    {
        destroyList();
    }

    if (otherList.first == nullptr) // otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; // current points to the
                                   // list to be copied
        count = otherList.count;

            // copy the first node
        first = new nodeType<Type>;  // create the node

        first->info = current->info;  // copy the info
        first->link = nullptr;     // set the link field of
                                   // the node to nullptr
        last = first;                // make last point to the
                                     // first node
        current = current->link;   // make current point to
                                   // the next node

           // copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;  // create a node
            newNode->info = current->info; // copy the info
            newNode->link = nullptr;       // set the link of
                                        // newNode to nullptr
            last->link = newNode;  // attach newNode after last
            last = newNode;        // make last point to
                                   // the actual last node
            current = current->link;   // make current point
                                       // to the next node
        } // end while
    } // end else
} // end copyList

//---------------------------------------------------------------------------
/* Destructor for linkedListType class.
*/
template <class Type>
linkedListType<Type>::~linkedListType()
{
   destroyList();
} // end destructor

//---------------------------------------------------------------------------
/* Copy constructor for linkedListType class.
*/
template <class Type>
linkedListType<Type>::linkedListType
                      (const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
} // end copy constructor

//---------------------------------------------------------------------------
/* Assignment operator overloading.
*/
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList)
{
    if (this != &otherList) // avoid self-copy
    {
        copyList(otherList);
    } // end else

     return *this;
}

//---------------------------------------------------------------------------
/* getFirst() returns a pointer to the first node of the linked list.
*/
template<class Type>
nodeType<Type>* linkedListType<Type>::getFirst(){
    return first;
}

#endif
