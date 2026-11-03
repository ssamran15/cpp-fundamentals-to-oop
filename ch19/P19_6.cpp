// P19.6: A Stack class with a dynamic array
#include <iostream>
using namespace std;

class Stack
{
private:
    int *items;
    int size;
    int top;                    // number of items in the stack

public:
    Stack(int n)
    {
        size = (n > 0) ? n : 1;
        items = new int[size];
        top = 0;
        cout << "[stack of " << size << " created]" << endl;
    }

    ~Stack()
    {
        delete[] items;
        cout << "[stack freed]" << endl;
    }

    bool isEmpty() { return top == 0; }
    bool isFull()  { return top == size; }

    bool push(int x)
    {
        if (isFull())
            return false;
        items[top++] = x;
        return true;
    }

    bool pop(int &x)
    {
        if (isEmpty())
            return false;
        x = items[--top];
        return true;
    }
};

int main()
{
    Stack s(4);

    for (int i = 1; i <= 5; i++)
    {
        if (s.push(i * 10))
            cout << "Pushed " << i * 10 << endl;
        else
            cout << "Stack full, " << i * 10 << " not pushed" << endl;
    }

    int x;
    cout << "Popping:";
    while (s.pop(x))
        cout << " " << x;
    cout << endl;
    cout << "Empty now? " << (s.isEmpty() ? "yes" : "no") << endl;
    return 0;
}
