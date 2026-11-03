// P23.8: A complete Stack: copy constructor, operator= and destructor
#include <iostream>
using namespace std;

class Stack
{
private:
    int *items;
    int size, top;

public:
    Stack(int n = 10) : size(n > 0 ? n : 1), top(0)
    {
        items = new int[size];
    }

    Stack(const Stack &other) : size(other.size), top(other.top)
    {
        items = new int[size];
        for (int i = 0; i < top; i++)
            items[i] = other.items[i];
    }

    Stack &operator=(const Stack &other)
    {
        if (this == &other)
            return *this;
        delete[] items;
        size = other.size;
        top = other.top;
        items = new int[size];
        for (int i = 0; i < top; i++)
            items[i] = other.items[i];
        return *this;
    }

    ~Stack()
    {
        delete[] items;
    }

    bool push(int x)
    {
        if (top == size)
            return false;
        items[top++] = x;
        return true;
    }

    bool pop(int &x)
    {
        if (top == 0)
            return false;
        x = items[--top];
        return true;
    }

    void show() const
    {
        cout << "[";
        for (int i = 0; i < top; i++)
            cout << " " << items[i];
        cout << " ]  (top on the right)" << endl;
    }
};

int main()
{
    Stack s1(5), s2(3);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s2 = s1;                // s2 gets its own copy of s1's items
    s2.push(40);
    s2.push(50);

    cout << "s1: "; s1.show();
    cout << "s2: "; s2.show();

    int x;
    s1.pop(x);
    cout << "Popped " << x << " from s1" << endl;
    cout << "s1: "; s1.show();
    cout << "s2: "; s2.show();

    Stack s3 = s2;          // the copy constructor
    cout << "s3 (copy of s2): "; s3.show();
    return 0;
}
