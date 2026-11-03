// P13.1: Sum and product through pointer parameters
#include <iostream>
using namespace std;

void sumAndProduct(int a, int b, int *sum, int *product);

int main()
{
    int a, b, s, p;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    sumAndProduct(a, b, &s, &p);       // pass the addresses of s and p
    cout << "Sum = " << s << endl;
    cout << "Product = " << p << endl;
    return 0;
}

void sumAndProduct(int a, int b, int *sum, int *product)
{
    *sum = a + b;
    *product = a * b;
}
