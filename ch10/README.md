# Chapter 10: Arrays

Solutions to the Practice Programs of Chapter 10. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P10_1.cpp -o P10_1` (or press F11 in Dev-C++).

## P10.1: Even and odd sums

Input 10 numbers into an array. Display the sum of the even numbers and the sum of the odd numbers.

**Solution:** [P10_1.cpp](P10_1.cpp)

**Sample run**

```
Enter 10 numbers: 12 7 30 45 8 19 22 3 64 11
Sum of even numbers = 136
Sum of odd numbers = 85
```

## P10.2: Days above average

Input the daily temperatures of a week. Display the average temperature and the days on which the temperature was above the average.

**Solution:** [P10_2.cpp](P10_2.cpp)

**Sample run**

```
Temperature on day 1: 31
Temperature on day 2: 33.5
Temperature on day 3: 29
Temperature on day 4: 35
Temperature on day 5: 36.5
Temperature on day 6: 30
Temperature on day 7: 32
Average temperature = 32.4286
Days above the average: 2 4 5
```

Strings come in Chapter 12, so the days are shown by number (day 1 to day 7).

## P10.3: Reversing an array

Input 10 numbers and display them in reverse order without using a second array. Then reverse the array itself by swapping the first with the last, the second with the second last, and so on.

**Solution:** [P10_3.cpp](P10_3.cpp)

**Sample run**

```
Enter 10 numbers: 1 2 3 4 5 6 7 8 9 10
In reverse order: 10 9 8 7 6 5 4 3 2 1 
Array after reversing: 10 9 8 7 6 5 4 3 2 1 
```

Only half the array is walked (`i < SIZE / 2`). Going all the way would swap every pair twice and put the array back as it was.

## P10.4: Positive and negative arrays

Input 10 numbers into array A. Copy the positive numbers into array B and the negative numbers into array C, and display both.

**Solution:** [P10_4.cpp](P10_4.cpp)

**Sample run**

```
Enter 10 numbers: 5 -3 12 0 -8 7 -1 20 -15 4
Positive (B): 5 12 7 20 4 
Negative (C): -3 -8 -1 -15 
```

`nb` and `nc` count how many values are in B and C. Zero is neither positive nor negative, so it goes into neither array.

## P10.5: Grade counts

Input the marks of 20 students. Display how many students got each grade: A (80+), B (65–79), C (50–64) and F (below 50).

**Solution:** [P10_5.cpp](P10_5.cpp)

**Sample run**

```
Enter the marks of 20 students:
85 72 64 91 45 58 66 79 80 33 50 49 95 61 70 88 52 40 67 76
Grade A: 5
Grade B: 6
Grade C: 5
Grade F: 4
```

## P10.6: Second largest

Input 10 numbers and display the second largest number.

**Solution:** [P10_6.cpp](P10_6.cpp)

**Sample run**

```
Enter 10 numbers: 45 12 88 30 88 67 5 71 23 50
Second largest = 71
```

Repeated values are allowed: in the run above 88 appears twice, and the second largest is the next different value, 71.

## P10.7: Array functions

Write functions `inputArray`, `printArray`, `sum` and `average`, each taking an array and its size. Use them in a program.

**Solution:** [P10_7.cpp](P10_7.cpp)

**Sample run**

```
Enter 6 numbers: 72 85 64 90 58 77
Marks: 72 85 64 90 58 77 
Sum = 446
Average = 74.3333
```

Only `inputArray` changes the array, so the other three take it as `const`.

## P10.8: Counting a value

Write a function `int countValue(const int arr[], int size, int value)` that returns how many times a value appears in the array.

**Solution:** [P10_8.cpp](P10_8.cpp)

**Sample run 1**

```
Array: 4 7 4 9 1 4 7 3 4 8 7 2 
Value to count: 4
4 appears 4 time(s)
```

**Sample run 2**

```
Array: 4 7 4 9 1 4 7 3 4 8 7 2 
Value to count: 5
5 appears 0 time(s)
```

## P10.9: Is it sorted?

Write a function `bool isSorted(const int arr[], int size)` that returns true if the array is in ascending order.

**Solution:** [P10_9.cpp](P10_9.cpp)

**Output**

```
Array a is sorted
Array b is not sorted
```

## P10.10: Merging sorted arrays

Write a function that merges two sorted arrays of 5 elements each into a third sorted array of 10 elements.

**Solution:** [P10_10.cpp](P10_10.cpp)

**Output**

```
Merged: 2 5 9 9 11 14 27 30 41 50 
```

Each step copies the smaller of the two front values. When one array runs out, the rest of the other is copied as it is.

## P10.11: Searching a roll number

Store the roll numbers and marks of 10 students in two arrays. Input a roll number, search for it, and display the marks of that student.

**Solution:** [P10_11.cpp](P10_11.cpp)

**Sample run 1**

```
Enter roll number: 112
Marks of roll number 112: 83
```

**Sample run 2**

```
Enter roll number: 113
Roll number 113 not found
```

The two arrays are parallel: `marks[i]` belongs to the student whose roll number is `roll[i]`.

## P10.12: Descending bubble sort

Input 10 numbers, sort them in descending order using bubble sort, and display the result.

**Solution:** [P10_12.cpp](P10_12.cpp)

**Sample run**

```
Enter 10 numbers: 34 7 89 12 56 3 71 45 20 66
Descending order: 89 71 66 56 45 34 20 12 7 3 
```

## P10.13: Early-stopping bubble sort

Modify bubble sort so that it stops early if a pass makes no swaps. Count and display the number of passes used for an array that is already sorted.

**Solution:** [P10_13.cpp](P10_13.cpp)

**Output**

```
Already sorted array: 3 7 12 18 25 31 40 52 
Passes used: 1

Unsorted array after sorting: 3 7 12 18 25 31 40 52 
Passes used: 6
```

For an already sorted array one pass is enough: it makes no swaps, so the loop stops. The unsorted array is shown for comparison.

## P10.14: Selection sort and binary search

Input the marks of 10 students, sort them with selection sort, and then use binary search to find whether a given mark was obtained.

**Solution:** [P10_14.cpp](P10_14.cpp)

**Sample run 1**

```
Enter the marks of 10 students: 67 82 45 91 58 73 88 39 64 77
Sorted marks: 39 45 58 64 67 73 77 82 88 91 
Mark to search: 73
73 was obtained (position 6 in the sorted list)
```

**Sample run 2**

```
Enter the marks of 10 students: 67 82 45 91 58 73 88 39 64 77
Sorted marks: 39 45 58 64 67 73 77 82 88 91 
Mark to search: 70
70 was not obtained by any student
```

## P10.15: Dice with a count array

Simulate 6,000 rolls of a dice. Store the count of each face in an array `int count[7]` (using indexes 1 to 6) and display the counts.

**Solution:** [P10_15.cpp](P10_15.cpp)

**Output**

```
Face  Count
1     998
2     1050
3     953
4     972
5     979
6     1048
```

The numbers are random, so your output will be different each time. Compare this with P9.13: the face itself is used as the index, so no `switch` is needed.
