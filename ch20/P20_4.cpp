// P20.4: An IntArray class with a deep copy
#include <iostream>
using namespace std;

class IntArray
{
private:
    int *data;
    int size;

public:
    IntArray(int n)
    {
        size = (n > 0) ? n : 1;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = i + 1;            // 1, 2, 3, ...
    }

    IntArray(const IntArray &other)     // deep copy: new memory, same values
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~IntArray()
    {
        delete[] data;
    }

    void set(int index, int value)
    {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    void show()
    {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    IntArray original(5);
    IntArray copy = original;           // the copy constructor runs here

    copy.set(0, 100);
    copy.set(4, 500);

    cout << "Original: ";
    original.show();
    cout << "Copy:     ";
    copy.show();
    return 0;
}
