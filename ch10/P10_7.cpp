// P10.7: Array functions
#include <iostream>
using namespace std;

void inputArray(int arr[], int size);
void printArray(const int arr[], int size);
int sum(const int arr[], int size);
double average(const int arr[], int size);

int main()
{
    const int SIZE = 6;
    int marks[SIZE];

    inputArray(marks, SIZE);
    cout << "Marks: ";
    printArray(marks, SIZE);
    cout << "Sum = " << sum(marks, SIZE) << endl;
    cout << "Average = " << average(marks, SIZE) << endl;
    return 0;
}

void inputArray(int arr[], int size)
{
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int sum(const int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += arr[i];
    return total;
}

double average(const int arr[], int size)
{
    return static_cast<double>(sum(arr, size)) / size;
}
