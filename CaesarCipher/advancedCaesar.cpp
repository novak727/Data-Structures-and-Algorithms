#include "advancedCaesar.h"

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
/* Default constructor, setting shiftValue to 1, then assigning each entry in
* the array the shifted value for the alphabet in order.
*/
advancedCaesar::advancedCaesar()
    : caesarCipher(1)
{
    for (int i = 0; i < SIZE; i++)
    {
        cipherAlphabet[i] = ((i + shiftValue) % 26) + 97;
    }
}

//---------------------------------------------------------------------------
/* Overloaded constructor, setting shiftValue to the parameter value, then
* assigning each entry in the array the shifted value for the alphabet in
* order.
*/
advancedCaesar::advancedCaesar(int sv)
    : caesarCipher(sv)
{
    for (int i = 0; i < SIZE; i++)
    {
        cipherAlphabet[i] = ((i + shiftValue) % 26) + 97;
    }
}

//---------------------------------------------------------------------------
/* The print() routine prints the shift value (using the caesarCipher class
* print routine, then prints the cipher alphabet in order.
*/
void advancedCaesar::print()
{
    caesarCipher::print();

    cout << "Cipher Alphabet:" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << cipherAlphabet[i] << endl;
    }
}
