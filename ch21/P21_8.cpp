// P21.8: A token machine, first as a function, then as a class
#include <iostream>
using namespace std;

// Version 1: a static local variable
int nextToken()
{
    static int token = 0;       // created once, keeps its value between calls
    token++;
    return token;
}

// Version 2: a class with a static data member
class TokenMachine
{
private:
    static int lastToken;

public:
    static int next()
    {
        return ++lastToken;
    }

    static void reset()         // for example, at the start of a new day
    {
        lastToken = 0;
    }
};

int TokenMachine::lastToken = 0;

int main()
{
    cout << "Function version: ";
    for (int i = 1; i <= 4; i++)
        cout << nextToken() << " ";
    cout << endl;

    cout << "Class version:    ";
    for (int i = 1; i <= 4; i++)
        cout << TokenMachine::next() << " ";
    cout << endl;

    TokenMachine::reset();
    cout << "After reset:      " << TokenMachine::next() << endl;
    return 0;
}
