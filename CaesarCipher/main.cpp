// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 09/09/2025
// Description: Caesar Cipher program that takes a string from user input and
// encrypts and decrypts the string based on a shift value.
// ---------------------------------------------------------------------------
#include <iostream>

#include "advancedCaesar.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    // Default constructor and print test
    advancedCaesar c1;
    c1.print();
    cout << endl;

    // Overloaded constructor and print test
    advancedCaesar c2(3);
    c2.print();
    cout << endl;

    // Enter string to encrypt/decrypt
    string value;

    cout << "Input a string: " << endl;
    cin >> value;

    // Encryption test w/ c2
    string encryptedValue = c2.encrypt(value);

    cout << encryptedValue << endl;

    // Decryption test w/ c2
    cout << c2.decrypt(encryptedValue) << endl;

	return 0;
}
