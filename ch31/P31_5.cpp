// P31.5: A circular Queue template at a bank counter
#include <iostream>
#include <string>
using namespace std;

template <typename T, int SIZE>
class Queue
{
private:
    T items[SIZE];
    int front, count;

public:
    Queue() : front(0), count(0) {}

    bool enqueue(const T &x)
    {
        if (count == SIZE)
            return false;                           // full
        items[(front + count) % SIZE] = x;          // wraps round to the start
        count++;
        return true;
    }

    bool dequeue(T &x)
    {
        if (count == 0)
            return false;                           // empty
        x = items[front];
        front = (front + 1) % SIZE;
        count--;
        return true;
    }

    int size() const { return count; }
};

int main()
{
    Queue<string, 3> counter;
    string arrivals[5] = { "Ali", "Sana", "Bilal", "Fatima", "Hamza" };
    string served;

    for (int i = 0; i < 4; i++)
    {
        if (counter.enqueue(arrivals[i]))
            cout << arrivals[i] << " joins the queue (" << counter.size() << " waiting)" << endl;
        else
            cout << arrivals[i] << " must wait outside: the queue is full" << endl;
    }

    counter.dequeue(served);
    cout << "Served: " << served << endl;
    counter.enqueue(arrivals[3]);
    cout << arrivals[3] << " joins the queue (" << counter.size() << " waiting)" << endl;
    if (!counter.enqueue(arrivals[4]))  // full again
        cout << arrivals[4] << " must wait outside: the queue is full" << endl;

    while (counter.dequeue(served))
        cout << "Served: " << served << endl;
    cout << "Queue empty, " << counter.size() << " waiting" << endl;
    return 0;
}
