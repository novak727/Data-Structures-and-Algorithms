//Header file QueueAsArray

#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;

template <class Type>
class queueType: public queueADT<Type>
{
public:
    //Overload the assignment operator.
    const queueType<Type>& operator=(const queueType<Type>&)
    {
        cout << "Write the definition of the function "
            << "to overload the assignment operator." << endl;
    } //end assignment operator

    //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.
    bool isEmptyQueue() const
    {
        return (count == 0);
    } //end isEmptyQueue

    //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.
    bool isFullQueue() const
    {
        return (count == maxQueueSize);
    } //end isFullQueue

    //Function to initialize the queue to an empty state.
      //Postcondition: The queue is empty.
    void initializeQueue()
    {
        queueFront = 0;
        queueRear = maxQueueSize - 1;
        count = 0;
    } //end initializeQueue

    //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //               terminates; otherwise, the first
      //               element of the queue is returned.
    Type front() const
    {
        assert(!isEmptyQueue());
        return list[queueFront];
    } //end front

    //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //               terminates; otherwise, the last
      //               element of the queue is returned.
    Type back() const
    {
        assert(!isEmptyQueue());
        return list[queueRear];
    } //end back

    //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.
    void addQueue(const Type& newElement)
    {
        if (!isFullQueue())
        {
            queueRear = (queueRear + 1) % maxQueueSize; //use mod
                            //operator to advance queueRear
                            //because the array is circular
            count++;
            list[queueRear] = newElement;
        }
        else
            cout << "Cannot add to a full queue." << endl;
    } //end addQueue

    //Function to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first
      //               element is removed from the queue.
    void deleteQueue()
    {
        if (!isEmptyQueue())
        {
            count--;
            queueFront = (queueFront + 1) % maxQueueSize; //use the
                        //mod operator to advance queueFront
                        //because the array is circular
        }
        else
            cout << "Cannot remove from an empty queue." << endl;
    } //end deleteQueue

    //Constructor
    queueType(int queueSize = 100)
    {
        if (queueSize <= 0)
        {
            cout << "Size of the array to hold the queue must "
                << "be positive." << endl;
            cout << "Creating an array of size 100." << endl;

            maxQueueSize = 100;
        }
        else
            maxQueueSize = queueSize;   //set maxQueueSize to
                                        //queueSize

        queueFront = 0;                 //initialize queueFront
        queueRear = maxQueueSize - 1;   //initialize queueRear
        count = 0;
        list = new Type[maxQueueSize];  //create the array to
                                    //hold the queue elements
    } //end constructor

    //Copy constructor
    queueType(const queueType<Type>& otherQueue)
    {
        cout << "Write the definition of the copy constructor."
         << endl;
    } //end copy constructor

    //Destructor
    ~queueType()
    {
        delete [] list;
    } //end destructor


private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;        //variable to store the number of
                      //elements in the queue
    int queueFront;   //variable to point to the first
                      //element of the queue
    int queueRear;    //variable to point to the last
                      //element of the queue
    Type *list;       //pointer to the array that holds
                      //the queue elements
};

#endif
