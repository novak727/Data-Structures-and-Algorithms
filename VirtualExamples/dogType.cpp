#include "dogType.h"
#include <iostream>
#include <string>
using namespace std;

dogType::dogType(string n, string b)
    : petType(n)
{
    breed = b;
}
void dogType::print()
{
    // petType::print();
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
}
