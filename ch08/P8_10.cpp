// P8.10: First 15 primes with isPrime and nextPrime
#include <iostream>
using namespace std;

bool isPrime(int n);
int nextPrime(int n);

int main()
{
    int p = 1;
    cout << "The first 15 prime numbers:" << endl;
    for (int i = 1; i <= 15; i++)
    {
        p = nextPrime(p);
        cout << p << " ";
    }
    cout << endl;
    return 0;
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
}

int nextPrime(int n)
{
    int candidate = n + 1;
    while (!isPrime(candidate))
        candidate++;
    return candidate;
}
