#include <iostream>

#include "caesarCipher.h"

//---------------------------------------------------------------------------
/* Default constructor, setting shiftValue to 1.
*/
caesarCipher::caesarCipher()
{
    shiftValue = 1;
}

//---------------------------------------------------------------------------
/* Overloaded constructor that passes through a declared shiftValue.
*/
caesarCipher::caesarCipher(int sv)
{
    shiftValue = sv;
}

//---------------------------------------------------------------------------
/* encrypt() traverses through the string parameter and encrypts the message
* based on the value of shiftValue.
*/
string caesarCipher::encrypt(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = ((s[i] - 97 + shiftValue) % 26) + 97;
        }
        else
        {
            cout << "limit your characters to a-z all lower case" << endl;
        }
    }
    return s;
}

//---------------------------------------------------------------------------
/* decrypt() takes an encrypted message as a parameter and converts the
* message back into its original value.
*/
string caesarCipher::decrypt(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = ((s[i] - 97 - shiftValue + 26) % 26) + 97;
        }
        else
        {
            cout << "limit your characters to a-z all lower case" << endl;
        }
    }
    return s;
}

//---------------------------------------------------------------------------
/* The print() routine prints the shift value to the console.
*/
void caesarCipher::print()
{
    cout << "Shift Value: " << shiftValue << endl;
}
