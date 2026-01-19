#include "Poly.h"

//---------------------------------------------------------------------------
/* Polynomial constructor with no parameters. Sets the head to nullptr.
*/
Poly::Poly()
{
    head = nullptr;
}

//---------------------------------------------------------------------------
/* Polynomial constructor which calls on the copyList() function to assign
* the Polynomial with the Polynomial parameter.
*/
Poly::Poly(const Poly& other)
{
    head = nullptr;
    copyList(other);
}

//---------------------------------------------------------------------------
/* The extracted operator is overloaded so that data can be read directly into
* the Linked List.
* INCOMING DATA: input stream, Linked List (passed by reference).
* OUTGOING DATA: input stream
*/
istream& operator>>(istream& is, Poly& p)
{
    p.Reset();

    char next;
    string s_coeff;
    string s_exp;
    int i_coeff;
    int i_exp;

    is >> next; //eat <
    if(next != '<')
    {
        cout << "ERROR IN INPUT FORMAT" << endl;
        return is;
    }
    is >> next; //prime coeff
    while(next != '>')
    {
        s_coeff = "";
        s_exp = "";
        while(next != 'x')
        {
            s_coeff += next;
            is >> next;
        }
        i_coeff = stoi(s_coeff);

        is >> next; //eat ^
        is >> next; //prime exp
        while(next != '+' && next != '>')
        {
            s_exp += next;
            is >> next;
        }
        i_exp = stoi(s_exp);

        //cout<<i_coeff<<":"<<i_exp<<endl;
        p.Insert(i_coeff, i_exp);

        if(next != '>')
        {
            is >> next; //prime next coeff;
        }
    }
    return is;
}

//---------------------------------------------------------------------------
/* The insertion operator is overloaded so that it can be used to read out
* data from the Linked List.
* INCOMING DATA: output stream, Linked List (passed by reference and constant).
* OUTGOING DATA: output stream
*/
ostream& operator<<(ostream& os, const Poly& p)
{
    Term* current;
    current = p.head;
    os << "<";
    while(current != nullptr)
    {
        cout << current->coeff;
        if(current->exp != 0)
        {
            cout << "x^" << current->exp;
        }
        if(current->next != nullptr)
        {
            cout <<" + ";
        }
        current = current->next;
    }
    os << ">" << endl;
    return os;
}

//---------------------------------------------------------------------------
/* Reset() traverses through the Linked List to delete every entry within the
* list, resetting the Polynomial back to no equation.
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void Poly::Reset()
{
    Term* current;
    Term* temp;
    current = head;
    while(current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

//---------------------------------------------------------------------------
/* Evaluate() takes in a value for x and solves the polynomial with that
* value for x.
* INCOMING DATA: 1 integer, the x value to use to evaluate the polynomial
* OUTGOING DATA: 1 integer, the result of the evaluated polynomial.
*/
int Poly::Evaluate(int x)
{
    int val = 0;
    Term* current = head;
    while(current != nullptr)
    {
        val = val + ((pow(x, current->exp))*current->coeff);
        current = current->next;
    }
    return val;
}

//---------------------------------------------------------------------------
/* The addition operator is overloaded to allow two polynomials to be added
* together.
* INCOMING DATA: 2 Polynomials, to be added together.
* OUTGOING DATA: 1 Polynomial, the sum of the two Polynomials added together.
*/
Poly Poly::operator+(const Poly& rhs)const
{
    Term* left;
    Term* right;

    Poly sum;

    left = head;
    right = rhs.head;

    while(left != nullptr && right != nullptr)
    {
        if(left->exp == right->exp)
        {
            sum.Insert(left->coeff + right->coeff, left->exp);
            left = left->next;
            right = right->next;
        }
        else if(left->exp > right->exp)
        {
            sum.Insert(left->coeff, left->exp);
            left = left->next;
        }
        else if(left->exp < right->exp)
        {
            sum.Insert(right->coeff, right->exp);
            right = right->next;
        }
    }
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            sum.Insert(right->coeff, right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            sum.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return sum;
}

//---------------------------------------------------------------------------
/* The subtraction operator is overloaded to allow two polynomials to be
* subtracted from each other.
* INCOMING DATA: 2 Polynomials, to be subtracted.
* OUTGOING DATA: 1 Polynomial, the difference of the two Polynomials.
*/
Poly Poly::operator-(const Poly& rhs)const
{
    Term* left;
    Term* right;

    Poly diff;

    left = head;
    right = rhs.head;

    while(left != nullptr && right != nullptr)
    {
        if(left->exp == right->exp)
        {
            int x;
            x = left->coeff + (-1*right->coeff);
            if(x != 0)
            {
                diff.Insert(x, left->exp);
            }
            left = left->next;
            right = right->next;
        }
        else if(left->exp > right->exp)
        {
            diff.Insert(left->coeff, left->exp);
            left = left->next;
        }
        else if(left->exp < right->exp)
        {
            diff.Insert((-1*right->coeff), right->exp);
            right = right->next;
        }
    }
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            diff.Insert((-1*right->coeff), right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            diff.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return diff;
}

//---------------------------------------------------------------------------
/* Derivative() calculates the derivative of the current Polynomial
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void Poly::Derivative()
{
    Term* current;
    Term* previous;
    current = head;

    if(current!=nullptr)
    {
        if(current->exp == 0)
        {
            delete current;
            head = nullptr;
        }
        else if(current->next == nullptr)
        {
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
        }
        else
        {
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
            previous = current;
            current = current->next;
            while(current != nullptr)
            {
                if(current->exp == 0)
                {
                    previous->next = nullptr;
                    delete current;
                    current = nullptr;
                }
                else
                {
                    current->coeff = current->coeff * current->exp;
                    current->exp = current->exp - 1;
                    previous = current;
                    current = current->next;
                }
            }
        }
    }

}

//---------------------------------------------------------------------------
/* Insert() adds the incoming data from the parameters to the Linked List so
* that the values are in descending order.
* INCOMING DATA: 2 integers, one representing the coefficient, the other
* representing the exponent.
* OUTGOING DATA: None
*/
void Poly::Insert(int c, int e)
{
    Term* newT = new Term;
    newT->coeff = c;
    newT->exp = e;
    newT->next = nullptr;

    Term* current;
    Term* previous;

    if(head == nullptr)
    {
        head = newT;
    }
    else if(head->exp < e)
    {
        newT->next = head;
        head = newT;
    }
    else
    {
        current = head;

        while(current != nullptr && current->exp > e)
        {
            previous = current;
            current = current->next;
        }

        if(current == nullptr)
        {
            previous->next = newT;
        }
        else
        {
            previous->next = newT;
            newT->next = current;
        }
    }
}

//---------------------------------------------------------------------------
/* Search() traverses through the Linked List to find the location of an
* exponent provided through a parameter. If the exponent is not found, nullptr
* is returned instead to represent the exponent not being in the Linked List.
* INCOMING DATA: 1 integer, representing the exponent value to search for
* OUTGOING DATA: 1 pointer, either pointing to where the exponent was found or
* nullptr if the exponent was not found.
*/
Term* Poly::Search(int targetExp)
{
    Term* srch;
    srch = head;

    while(srch != nullptr)
    {
        if(srch->exp == targetExp)
        {
            return srch;
        }
        srch = srch->next;
    }
    return nullptr;
}

//---------------------------------------------------------------------------
/* PrintReverse() calls the helper function recPrintRev() to assist in
* recursing through the Linked List in order to print the polynomial in
* reverse order.
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void Poly::PrintReverse()
{
    Term* current;
    current = head;
    cout << "<";
    recPrintRev(current);
    cout << ">" << endl;
}

//---------------------------------------------------------------------------
/* The assignment operator is overloaded to allow assigning of Polynomials
from other polynomials. It does this by calling the copyList() function.
* INCOMING DATA: 1 polynomial to have its data assigned.
* OUTGOING DATA: The resulting polynomial assignment.
*/
Poly& Poly::operator=(const Poly& other)
{
    if (this != &other) //avoid self-copy
    {
        copyList(other);
    }//end else

    return *this;
}

//---------------------------------------------------------------------------
/* The destructor calls the reset routine in order to clear the Linked List
* data.
*/
Poly::~Poly()
{
    Reset();
}

//---------------------------------------------------------------------------
/* recPrintRev() recurses through the Linked List until it reaches nullptr so
* so that the polynomial is printed in reverse order, where the polynomial is
* printed from lowest degree to highest degree, rather than the traditional
* highest degree to lowest degree.
* INCOMING DATA: 1 pointer, passed in from the PrintReverse() function
* OUTGOING DATA: None
*/
void Poly::recPrintRev(Term* c)
{
    if(c->next != nullptr)
    {
        recPrintRev(c->next);
    }
    cout << c->coeff << "x^" << c->exp << " + ";
}

//---------------------------------------------------------------------------
/* copyList() creates a deep copy of another Polynomial.
* INCOMING DATA: 1 Polynomial, the list to have a copy made of.
* OUTGOING DATA: None
*/
void Poly::copyList(const Poly& otherList)
{
    Term* newT;
    Term* current;
    Term* last;

    if(head!=nullptr)
    {
        Reset();
    }

    if(otherList.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        current = otherList.head;
        head = new Term;
        head->coeff = otherList.head->coeff;
        head->exp = otherList.head->exp;
        head->next = nullptr;

        last = head;
        current = current->next;

        while(current != nullptr)
        {
            newT = new Term;
            newT->coeff = current->coeff;
            newT->exp = current->exp;
            newT->next = nullptr;

            last->next = newT;

            last = last->next;
            current = current->next;
        }
    }
}
