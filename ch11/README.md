# Chapter 11: Two-Dimensional Arrays and C-strings

Solutions to the Practice Programs of Chapter 11. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P11_1.cpp -o P11_1` (or press F11 in Dev-C++).

## P11.1: Row, column and diagonal sums

Input a 3 × 3 matrix and display the sum of each row, the sum of each column, and the sums of both diagonals.

**Solution:** [P11_1.cpp](P11_1.cpp)

**Sample run**

```
Enter a 3 x 3 matrix row by row:
2 7 6
9 5 1
4 3 8
Sum of row 1 = 15
Sum of row 2 = 15
Sum of row 3 = 15
Sum of column 1 = 15
Sum of column 2 = 15
Sum of column 3 = 15
Sum of main diagonal = 15
Sum of other diagonal = 15
```

The sample matrix is a magic square, so every row, column and diagonal adds up to 15.

## P11.2: Largest and smallest with position

Input a 4 × 4 matrix and display its largest and smallest elements with their row and column numbers.

**Solution:** [P11_2.cpp](P11_2.cpp)

**Sample run**

```
Enter a 4 x 4 matrix row by row:
12 45 7 30
18 3 66 21
50 9 14 27
5 40 33 11
Largest = 66 at row 2, column 3
Smallest = 3 at row 2, column 2
```

The program remembers the row and column of the best value so far, not the value itself.

## P11.3: Symmetric matrix

Input a square matrix and check whether it is symmetric (equal to its own transpose).

**Solution:** [P11_3.cpp](P11_3.cpp)

**Sample run 1**

```
Size of the square matrix (1 to 10): 3
Enter the matrix row by row:
1 4 7
4 2 5
7 5 3
The matrix is symmetric
```

**Sample run 2**

```
Size of the square matrix (1 to 10): 3
Enter the matrix row by row:
1 4 7
4 2 5
6 5 3
The matrix is not symmetric
```

Only the elements above the main diagonal need to be compared with their mirror images below it.

## P11.4: Matrix sum, difference and product

Input two 3 × 3 matrices and display their sum, difference and product.

**Solution:** [P11_4.cpp](P11_4.cpp)

**Sample run**

```
Matrix A:
1 2 3
4 5 6
7 8 9
Matrix B:
9 8 7
6 5 4
3 2 1

A + B
    10    10    10
    10    10    10
    10    10    10
A - B
    -8    -6    -4
    -2     0     2
     4     6     8
A x B
    30    24    18
    84    69    54
   138   114    90
```

## P11.5: Weekly sales

A shop records the sales of 4 salesmen for 7 days in a 4 × 7 array. Display the weekly total of each salesman, the total sales of each day, and the best salesman of the week.

**Solution:** [P11_5.cpp](P11_5.cpp)

**Output**

```
Weekly total of each salesman
Salesman 1: Rs. 86700
Salesman 2: Rs. 74300
Salesman 3: Rs. 111300
Salesman 4: Rs. 73300

Total sales of each day
Day 1: Rs. 45300
Day 2: Rs. 42700
Day 3: Rs. 52100
Day 4: Rs. 47000
Day 5: Rs. 47200
Day 6: Rs. 54800
Day 7: Rs. 56500

Best salesman of the week: Salesman 3 (Rs. 111300)
```

The sales figures are stored in the program as an initialised array, so there is no input.

## P11.6: Result sheet

Input the marks of 5 students in 3 subjects. Display a result sheet with each student's total and percentage, and the highest marks in each subject.

**Solution:** [P11_6.cpp](P11_6.cpp)

**Sample run**

```
Marks of student 1 in 3 subjects (out of 100): 72 85 64
Marks of student 2 in 3 subjects (out of 100): 90 88 79
Marks of student 3 in 3 subjects (out of 100): 45 52 60
Marks of student 4 in 3 subjects (out of 100): 66 70 75
Marks of student 5 in 3 subjects (out of 100): 81 77 93

 Student    S1    S2    S3   Total       %
       1    72    85    64     221   73.67
       2    90    88    79     257   85.67
       3    45    52    60     157   52.33
       4    66    70    75     211   70.33
       5    81    77    93     251   83.67

Highest in subject 1: 90
Highest in subject 2: 88
Highest in subject 3: 93
```

## P11.7: Counting words

Input a sentence and count the number of words in it (words are separated by single spaces).

**Solution:** [P11_7.cpp](P11_7.cpp)

**Sample run**

```
Enter a sentence: Okara is a city in Punjab
Number of words: 6
```

## P11.8: String in reverse

Input a string and display it in reverse, without using any library function.

**Solution:** [P11_8.cpp](P11_8.cpp)

**Sample run**

```
Enter a string: Programming Fundamentals
Reversed: slatnemadnuF gnimmargorP
```

## P11.9: Our own strlen and strcpy

Write your own functions `int myStrlen(const char s[])` and `void myStrcpy(char dest[], const char src[])` and test them.

**Solution:** [P11_9.cpp](P11_9.cpp)

**Sample run**

```
Enter a string: Govt. Graduate College
Length: 22
Copy: Govt. Graduate College
```

## P11.10: Initials

Input a name and display the initials. For example, "Muhammad Ali Jinnah" gives "M. A. J."

**Solution:** [P11_10.cpp](P11_10.cpp)

**Sample run 1**

```
Enter a name: Muhammad Ali Jinnah
Initials: M. A. J. 
```

**Sample run 2**

```
Enter a name: allama muhammad iqbal
Initials: A. M. I. 
```

`toupper` returns an `int`, so it is cast back to `char` before printing.

## P11.11: Password rules

Input a password and check that it has at least 8 characters, at least one uppercase letter, one lowercase letter and one digit. Display which rules, if any, it fails.

**Solution:** [P11_11.cpp](P11_11.cpp)

**Sample run 1**

```
Enter a password: okara
Fails: at least 8 characters
Fails: at least one uppercase letter
Fails: at least one digit
```

**Sample run 2**

```
Enter a password: Okara2026
The password is strong
```

## P11.12: Counting vowels

Input a sentence and display how many times each vowel (a, e, i, o, u) appears in it, ignoring case.

**Solution:** [P11_12.cpp](P11_12.cpp)

**Sample run**

```
Enter a sentence: An Apple a day keeps the doctor away
a: 6
e: 4
i: 0
o: 2
u: 0
```

## P11.13: Sorting city names

Input the names of 5 cities and sort them in alphabetical order using bubble sort with `strcmp` and `strcpy`.

**Solution:** [P11_13.cpp](P11_13.cpp)

**Sample run**

```
City 1: Okara
City 2: Lahore
City 3: Multan
City 4: Faisalabad
City 5: Dera Ghazi Khan

In alphabetical order:
Dera Ghazi Khan
Faisalabad
Lahore
Multan
Okara
```

`cin.getline` is used so that a city name may contain spaces.

## P11.14: Roll number by name

Store the names and roll numbers of 6 students. Input a name and display the matching roll number, or a message if the name is not in the list.

**Solution:** [P11_14.cpp](P11_14.cpp)

**Sample run 1**

```
Enter a name: Hamza Ali
Roll number of Hamza Ali: 204
```

**Sample run 2**

```
Enter a name: Hamza Khan
Hamza Khan is not in the list
```

`strcmp` is case-sensitive, so the name must be typed exactly as it is stored.
