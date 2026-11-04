// P33.4: A Stack template that throws overflow_error and underflow_error
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
    T items[5];
    int count;

public:
    Stack() : count(0) {}

    void push(const T &x)
    {
        if (count == 5)
            throw overflow_error("stack is full");
        items[count++] = x;
    }

    T pop()
    {
        if (count == 0)
            throw underflow_error("stack is empty");
        return items[--count];
    }
};

int main()
{
    Stack<int> numbers;
    try
    {
        for (int i = 1; i <= 6; i++)
        {
            numbers.push(i * 10);
            cout << "Pushed " << i * 10 << endl;
        }
    }
    catch (const overflow_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    Stack<string> words;
    words.push("Okara");
    words.push("Lahore");
    try
    {
        for (int i = 1; i <= 3; i++)
        {
            string w = words.pop();     // pop first, so nothing is printed if it throws
            cout << "Popped " << w << endl;
        }
    }
    catch (const underflow_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
