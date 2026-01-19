#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;


//------------------------------------------------------------------------------
/* nodeType
* The definition of the node used for linked lists.
* Contains the value stored at each node and a pointer to the next node
*/
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

//------------------------------------------------------------------------------
/* linkedListIterator
* An implementation of an iterator for a linked list.
* The only attribute is a pointer for the current node in the linked list.
* Contains overloaded pre-increment, dereference, equality, and inequality
* operators.
*/
template <class Type>
class linkedListIterator
{
    public:
        //----------------------------------------------------------------------
        /* Default constructor
        */
        linkedListIterator()
        {
            current = nullptr;
        }

        //----------------------------------------------------------------------
        /* Copy constructor
        */
        linkedListIterator(nodeType<Type> *ptr)
        {
            current = ptr;
        }

        //----------------------------------------------------------------------
        /* Overloaded dereference operator
        */
        Type operator*()
        {
            return current->info;
        }

        //----------------------------------------------------------------------
        /* Overloaded pre-increment operator
        */
        linkedListIterator<Type> operator++()
        {
            current = current->link;

            return *this;
        }

        //----------------------------------------------------------------------
        /* Overloaded equality operator
        */
        bool operator==(const linkedListIterator<Type>& right) const
        {
            return (current == right.current);
        }

        //----------------------------------------------------------------------
        /* Overloaded not equal to operator
        */
        bool operator!=(const linkedListIterator<Type>& right) const
        {
            return (current != right.current);
        }

    private:
        nodeType<Type> *current; // pointer to point to the current node in the linked list
};

//------------------------------------------------------------------------------
/* linkedListType
* An implementation of a templated linked list.
* Attributes for the number of elements in the list and pointers to the first
* and last nodes of the linked list.
* Methods available to create the linked list, check if it's empty, print the
* list, destroy the list, insert at the front or back of the list, delete nodes
* from the list,
*/
template <class Type>
class linkedListType
{
    public:
        //----------------------------------------------------------------------
        /* Overloaded assignment operator
        */
        const linkedListType<Type>& operator=(const linkedListType<Type>& otherList)
        {
            if (this != &otherList) // avoid self-copy
            {
                copyList(otherList);
            }

             return *this;
        }

        //----------------------------------------------------------------------
        /* initializeList() sets the linked list to an empty state
        */
        void initializeList()
        {
            destroyList(); // if the list has any nodes, delete them
        }

        //----------------------------------------------------------------------
        /* isEmptyList() determines if the linked list is empty.
        */
        bool isEmptyList() const
        {
            return (first == nullptr);
        }

        //----------------------------------------------------------------------
        /* print() outputs the data contained in each node of the linked list
        */
        void print() const
        {
            nodeType<Type> *current; // pointer to traverse the list

            current = first;    // set current so that it points to the first node
            while (current != nullptr) // while more data to print
            {
                cout << current->info << " ";
                current = current->link;
            }
        }

        //----------------------------------------------------------------------
        /* length() returns the number of nodes in the linked list
        */
        int length() const
        {
            return count;
        }

        //----------------------------------------------------------------------
        /* destroyList() deletes all nodes from the linked list.
        */
        void destroyList()
        {
            nodeType<Type> *temp; // pointer to deallocate the memory occupied by the node
            while (first != nullptr) // while there are nodes in the list
            {
                temp = first;        // set temp to the current node
                first = first->link; // advance first to the next node
                delete temp;         // deallocate the memory occupied by temp
            }
            last = nullptr; // initialize last to nullptr; first has already
                            // been set to nullptr by the while loop
            count = 0;
        }

        //----------------------------------------------------------------------
        /* front() returns the first element of the linked list.
        */
        Type front() const
        {
            assert(first != nullptr);

            return first->info; // return the info of the first node
        }

        //----------------------------------------------------------------------
        /* back() returns the last element of the linked list.
        */
        Type back() const
        {
            assert(last != nullptr);

            return last->info; // return the info of the last node
        }

        virtual bool search(const Type& searchItem) const = 0;
        virtual void insertFirst(const Type& newItem) = 0;
        virtual void insertLast(const Type& newItem) = 0;
        virtual void deleteNode(const Type& deleteItem) = 0;

        //----------------------------------------------------------------------
        /* begin() returns an iterator at the beginning of the linked list
        */
        linkedListIterator<Type> begin()
        {
            linkedListIterator<Type> temp(first);

            return temp;
        }

        //----------------------------------------------------------------------
        /* end() returns an iterator one element past the last element of the
        *  linked list
        */
        linkedListIterator<Type> end()
        {
            linkedListIterator<Type> temp(nullptr);

            return temp;
        }

        //----------------------------------------------------------------------
        /* Default constructor
        */
        linkedListType()
        {
            first = nullptr;
            last = nullptr;
            count = 0;
        }

        //----------------------------------------------------------------------
        /* Copy constructor
        */
        linkedListType(const linkedListType<Type>& otherList)
        {
            first = nullptr;
            copyList(otherList);
        }

        //----------------------------------------------------------------------
        /* Destructor
        */
        ~linkedListType()
        {
            destroyList();
        }

    protected:
        int count;   // variable to store the number of elements in the list
        nodeType<Type> *first; // pointer to the first node of the list
        nodeType<Type> *last;  // pointer to the last node of the list

    private:
        //----------------------------------------------------------------------
        /* copyList() makes a copy of the parameter otherList.
        */
        void copyList(const linkedListType<Type>& otherList)
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

                first->info = current->info; // copy the info
                first->link = nullptr;        // set the link field of the node to nullptr
                last = first;              // make last point to the first node
                current = current->link;     // make current point to the next node

                // copy the remaining list
                while (current != nullptr)
                {
                    newNode = new nodeType<Type>;  // create a node
                    newNode->info = current->info; // copy the info
                    newNode->link = nullptr;       // set the link of newNode to nullptr
                    last->link = newNode;  // attach newNode after last
                    last = newNode;        // make last point to the actual last node
                    current = current->link;   //make current point to the next node
                }
            }
        }
};

#endif
