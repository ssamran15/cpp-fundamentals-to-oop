// P14.3: Joining two dynamic arrays
#include <iostream>
using namespace std;

int* join(const int *a, int na, const int *b, int nb);
int* inputArray(int &n);
void show(const int *a, int n);

int main()
{
    int na, nb;
    cout << "First array" << endl;
    int *a = inputArray(na);
    cout << "Second array" << endl;
    int *b = inputArray(nb);

    int *c = join(a, na, b, nb);
    cout << "Merged array: ";
    show(c, na + nb);

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}

int* inputArray(int &n)
{
    cout << "Size: ";
    cin >> n;
    int *a = new int[n];
    cout << "Elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

int* join(const int *a, int na, const int *b, int nb)
{
    int *c = new int[na + nb];
    for (int i = 0; i < na; i++)
        c[i] = a[i];
    for (int i = 0; i < nb; i++)
        c[na + i] = b[i];
    return c;
}

void show(const int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
