#ifndef H_FBX
#define H_FBX
    #include "FizzBuzzExt.h"
#endif // H_FBX

FizzBuzzExt::FizzBuzzExt(int l)
    : FizzBuzz(l)
{
    mults = new int[100];
    words = new string[100];
    numRules = 0;
}

void FizzBuzzExt::clear()
{
    numRules = 0;
}

void FizzBuzzExt::addRule()
{
    int newNum;
    string newWord;
    cout << "Enter the new multiple: ";
    cin >> newNum;
    cout << "Enter the new word: ";
    cin >> newWord;
    mults[numRules] = newNum;
    words[numRules] = newWord;
    numRules++;
}

int FizzBuzzExt::menu()
{
    int choice;
    cout << "Menu:" << endl;
    cout << "\t1. Run the game." << endl;
    cout << "\t2. Set the limit value." << endl;
    cout << "\t3. Clear the rules." << endl;
    cout << "\t4. Add a rule." << endl;
    cout << "\t5. Quit." << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void FizzBuzzExt::run()
{
    bool flag;
    string output;
    if (numRules == 0)
    {
        cout << "Sorry, no rules currently exist." << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= limit; i++)
        {
            output = "";
            flag = false;
            for (int j = 0; j < numRules; j++)
            {
                if (i % mults[j] == 0)
                {
                    output += words[j];
                    flag = true;
                }
            }

            if (flag)
            {
                cout << output << endl;
                flag = false;
            }
            else
            {
                cout << i << endl;
            }
        }
    }
}
