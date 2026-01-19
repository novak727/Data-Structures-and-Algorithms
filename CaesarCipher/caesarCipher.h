#ifndef CAESAR_H
#define CAESAR_H

#include <string>
using namespace std;

//---------------------------------------------------------------------------
/* caesarCipher
* caesarCipher defines an encryption scheme for a fully lowercase string with
* no spaces.
* This class has a single integer attribute used to store the value to shift
* each letter by when encrypting the message.
* Methods are programmed to encrypt and decrypt the message, set the shift
* value in a constructor (either a default value or user set), and to print
* the shift value.
*/
class caesarCipher
{
    public:
        caesarCipher();
        caesarCipher(int);
        string encrypt(string);
        string decrypt(string);
        void print();

    protected:
        int shiftValue;
};

#endif // CAESAR_H
