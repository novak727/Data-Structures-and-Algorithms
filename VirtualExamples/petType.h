#include <string>
using namespace std;

class petType
{
    public:
        petType(string n = "");
        virtual void print() = 0; // pure virtual
    protected:
        string name;
};
