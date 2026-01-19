#ifndef H_PT
#define H_PT
    #include "petType.h"
#endif // H_PT

class dogType : public petType
{
    public:
        dogType(string n = "", string b = "");
        void print();
    private:
        string breed;
};
