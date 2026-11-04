// P31.8: Two jobs for the Stack template of Program 31.7
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
    T items[50];
    int count;

public:
    Stack();
    bool push(const T &x);
    bool pop(T &x);
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
};

template <typename T>
Stack<T>::Stack() : count(0) {}

template <typename T>
bool Stack<T>::push(const T &x)
{
    if (count == 50)
        return false;                   // stack full
    items[count++] = x;
    return true;
}

template <typename T>
bool Stack<T>::pop(T &x)
{
    if (count == 0)
        return false;                   // stack empty
    x = items[--count];
    return true;
}

int main()
{
    // Job 1: decimal to binary
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cin.ignore(100, '\n');

    Stack<int> bits;
    int value = n;
    do
    {
        bits.push(value % 2);           // the remainders come out last bit first
        value /= 2;
    } while (value > 0);

    cout << n << " in binary is ";
    int b;
    while (bits.pop(b))                 // so popping gives them in the right order
        cout << b;
    cout << endl;

    // Job 2: the words of a sentence in reverse order
    string sentence, word;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    Stack<string> words;
    istringstream in(sentence);
    while (in >> word)
        words.push(word);

    cout << "Reversed:";
    while (words.pop(word))
        cout << " " << word;
    cout << endl;
    return 0;
}
