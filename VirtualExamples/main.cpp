#include <iostream>
#include <string>
using namespace std;

#ifndef H_PT
#define H_PT
    #include "petType.h"
#endif // H_PT

#include "dogType.h"
void callPrint(petType*);
int main()
{
    petType* p;
    // p = new petType("Turtle");
    // callPrint(p);

    // dogType dT("Dog", "Poodle");
    p = new dogType("Dog", "Boston Terrier");
    callPrint(p);
    // dT.print();

    return 0;
}

void callPrint(petType* pT)
{
    pT->print();
}
