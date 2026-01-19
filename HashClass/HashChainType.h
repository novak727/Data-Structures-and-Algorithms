#ifndef H_HashChainType
#define H_HashChainType

#include "HashADT.h"

using namespace std;

//---------------------------------------------------------------------------
/* hashChainType
* A brief description of the object being defined.
* Details about its attributes (public/private/protected) and a
* Brief list of all the available methods.
*/
template <class elemType>
class hashChainType : public hashADT<elemType>
{
public:
    hashChainType(int size = 101): hashADT<elemType>(size)
    {
        // no additional action required
    }
    void insert(const elemType& rec);
        // Function to insert an item in the hash table.
        // The item to be inserted is specified by the parameter rec.
        //    Postcondition: rec is inserted in the proper list (create
        //    the list if not already created).

    void search(const elemType& rec, bool& found);
        // Function to determine whether the item specified by the
        // parameter rec is in the hash table.
        // Postcondition: If rec is found, found is set to true,
        // found is set to false.


    void remove(const elemType& rec);
        // Function to remove an item from the hash table.
        // Postcondition: If rec is found in the table it is removed;
        // otherwise, an appropriate error message is displayed.

    void print() const;
        // Function to output the values in the hash table.
};

//---------------------------------------------------------------------------
/* insert() takes a parameter and inserts that parameter into the hash table.
*/
template <class elemType>
void hashChainType<elemType>::insert(const elemType& rec)
{
    int index = hashADT<elemType>::getHash(rec);

    if (hashADT<elemType>::HTable[index] == nullptr)
    {
        hashADT<elemType>::HTable[index] = new unorderedLinkedList<elemType>();
    }

    hashADT<elemType>::HTable[index]->insertLast(rec);
}

//---------------------------------------------------------------------------
/* search() takes a parameter for the element to find. If it is found, the
* boolean parameter gets set to true, otherwise is set to false.
*/
template <class elemType>
void hashChainType<elemType>::search(const elemType& rec, bool& found)
{
    int index = hashADT<elemType>::getHash(rec);

    if (hashADT<elemType>::HTable[index] != nullptr)
    {
        found = hashADT<elemType>::HTable[index]->search(rec);
    }
    else
    {
        found = false;
    }
}

//---------------------------------------------------------------------------
/* remove() takes a parameter and deletes the parameter from the
*/
template <class elemType>
void hashChainType<elemType>::remove(const elemType& rec)
{
    int index = hashADT<elemType>::getHash(rec);

    if (hashADT<elemType>::HTable[index] != nullptr)
    {
        hashADT<elemType>::HTable[index]->deleteNode(rec);
    }
    else
    {
        cout << rec << " not found" << endl;
    }
}

//---------------------------------------------------------------------------
/* print() outputs all elements in the hash table.
*/
template <class elemType>
void hashChainType<elemType>::print() const
{
    for (int i = 0; i < hashADT<elemType>::HTSize; i++)
    {
        if (hashADT<elemType>::HTable[i] != nullptr)
        {
            hashADT<elemType>::HTable[i]->print();
        }
        cout << endl;
    }
}

#endif
