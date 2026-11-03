// P9.14: Maths quiz for a child
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomBetween(int low, int high);
bool askQuestion(int number);

int main()
{
    srand(time(0));

    int score = 0;
    for (int q = 1; q <= 10; q++)
        if (askQuestion(q))
            score++;

    cout << endl << "Your score: " << score << " out of 10" << endl;
    return 0;
}

int randomBetween(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// asks one question and returns true if the answer is right
bool askQuestion(int number)
{
    int a = randomBetween(1, 20);
    int b = randomBetween(1, 20);
    int answer;

    cout << "Q" << number << ": " << a << " + " << b << " = ? ";
    cin >> answer;

    if (answer == a + b)
    {
        cout << "Correct!" << endl;
        return true;
    }
    cout << "Wrong. The answer is " << a + b << "." << endl;
    return false;
}
