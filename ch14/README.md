# Chapter 14: Dynamic Memory: new and delete

Solutions to the Practice Programs of Chapter 14. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

Every program here was also checked with Valgrind: no memory leaks and no invalid memory use.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P14_1.cpp -o P14_1` (or press F11 in Dev-C++).

## P14.1: Above the average

Input `n`, create a dynamic array of `n` integers, input the numbers, and display their average and the numbers greater than the average.

**Solution:** [P14_1.cpp](P14_1.cpp)

**Sample run**

```
How many numbers? 6
Enter 6 numbers: 45 72 38 90 61 54
Average = 60
Greater than the average: 72 90 61 
```

## P14.2: Reversed copy

Write a function `int* reversedCopy(const int *a, int n)` that returns a new dynamic array holding the elements of `a` in reverse order. Display both arrays in `main` and free the memory.

**Solution:** [P14_2.cpp](P14_2.cpp)

**Sample run**

```
How many numbers? 5
Enter 5 numbers: 10 20 30 40 50
Original: 10 20 30 40 50 
Reversed: 50 40 30 20 10 
```

The function creates the array, but `main` must delete it, because only `main` still has its address.

## P14.3: Joining two arrays

Write a function that receives two dynamic arrays and their sizes and returns a new dynamic array containing all the elements of both. Display the merged array.

**Solution:** [P14_3.cpp](P14_3.cpp)

**Sample run**

```
First array
Size: 3
Elements: 4 8 15
Second array
Size: 4
Elements: 16 23 42 50
Merged array: 4 8 15 16 23 42 50 
```

## P14.4: Removing an element

Create a dynamic array of `n` numbers. Input a position and remove the element at that position by creating a new array one element smaller.

**Solution:** [P14_4.cpp](P14_4.cpp)

**Sample run**

```
How many numbers? 6
Enter 6 numbers: 11 22 33 44 55 66
Position to remove (1 to 6): 3
After removing: 11 22 44 55 66 
```

## P14.5: Growing by doubling

Input numbers until the user enters a negative number, storing them in a dynamic array that grows by doubling. Display the numbers in sorted order.

**Solution:** [P14_5.cpp](P14_5.cpp)

**Sample run**

```
Enter numbers (a negative number to stop): 45 12 88 30 67 5 71 23 50 -1
  (capacity grew to 4)
  (capacity grew to 8)
  (capacity grew to 16)
9 numbers in sorted order: 5 12 23 30 45 50 67 71 88 
```

The array starts with room for 2 numbers. The messages show each time it doubles: 2, 4, 8, 16.

## P14.6: Dynamic array of structures

Input `n` and create a dynamic array of `Student` structures (roll number, name, marks). Input the records and display the topper.

**Solution:** [P14_6.cpp](P14_6.cpp)

**Sample run**

```
Number of students: 3
Student 1 roll number: 101
Name: Ayesha Khan
Marks: 78
Student 2 roll number: 102
Name: Bilal Ahmed
Marks: 91
Student 3 roll number: 103
Name: Sana Tariq
Marks: 85

Topper: Bilal Ahmed (roll 102, 91 marks)
```

## P14.7: Pascal's triangle

Input the number of rows `n` and store Pascal's triangle in a jagged dynamic array where row `i` has `i + 1` elements. Display the triangle and free all the memory.

**Solution:** [P14_7.cpp](P14_7.cpp)

**Sample run**

```
Number of rows: 7
    1
    1    1
    1    2    1
    1    3    3    1
    1    4    6    4    1
    1    5   10   10    5    1
    1    6   15   20   15    6    1
```

## P14.8: Dynamic matrices

Input the size of two matrices, create them dynamically, input their elements, and display their sum in a third dynamic matrix.

**Solution:** [P14_8.cpp](P14_8.cpp)

**Sample run**

```
Rows and columns: 2 3
Matrix A:
1 2 3
4 5 6
Matrix B:
10 20 30
40 50 60
A + B:
   11   22   33
   44   55   66
```

## P14.9: Names of exactly the right size

Input `n` names, one per line, and store each in a dynamic C-string of exactly the right size, using an array of `char` pointers. Display the names and the total number of bytes used.

**Solution:** [P14_9.cpp](P14_9.cpp)

**Sample run**

```
How many names? 3
Name 1: Ali
Name 2: Fatima Noor
Name 3: Muhammad Usman

Names stored:
Ali (4 bytes)
Fatima Noor (12 bytes)
Muhammad Usman (15 bytes)
Total bytes used for the names: 31
```

## P14.10: Create, fill and free

Write three functions: `int* createArray(int n)`, `void fillArray(int *a, int n)` and `void freeArray(int *&a)`, which deletes the array and sets the caller's pointer to `nullptr`. Test all three in `main`.

**Solution:** [P14_10.cpp](P14_10.cpp)

**Sample run**

```
Size of the array: 4
Enter 4 numbers: 7 14 21 28
Array: 7 14 21 28 
Memory freed; the pointer is now nullptr
```

`freeArray` takes the pointer by reference (`int *&a`), so setting it to `nullptr` changes the caller's pointer, not a copy.
