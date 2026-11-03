// P13.2: Arranging three numbers through pointers
#include <iostream>
using namespace std;

void swapValues(int *x, int *y);
void arrange(int *a, int *b, int *c);

int main()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    arrange(&x, &y, &z);
    cout << "Smallest to largest: " << x << " " << y << " " << z << endl;
    return 0;
}

void swapValues(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void arrange(int *a, int *b, int *c)
{
    if (*a > *b) swapValues(a, b);
    if (*a > *c) swapValues(a, c);     // now *a is the smallest
    if (*b > *c) swapValues(b, c);     // now *c is the largest
}
