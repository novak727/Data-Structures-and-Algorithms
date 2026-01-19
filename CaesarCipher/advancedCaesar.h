#ifndef ADVCAESAR_H
#define ADVCAESAR_H

#include "caesarCipher.h"

//---------------------------------------------------------------------------
/* advancedCaesar
* advancedCaesar derives from caesarCipher, adding some additional routines.
* This class adds an array of characters to represent the alphabet after the
* values have all been shifted by the set amount.
* Default constructors are set to set the shiftValue in caesarClass, then
* set the cipherAlphabet array to the correct values. Finally, a print routine
* prints the entire cipherAlphabet array as well as the number each letter was
* shifted by.
*/
class advancedCaesar : public caesarCipher
{
    public:
        advancedCaesar();
        advancedCaesar(int);
        void print();

        static const int SIZE = 26; // represent each letter of the alphabet
    private:
        char cipherAlphabet[SIZE];
};

#endif // ADVCAESAR_H
