# Chapter 7: Loops

Solutions to the Practice Programs of Chapter 7. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P7_1.cpp -o P7_1` (or press F11 in Dev-C++).

## P7.1: Odd numbers

Display all odd numbers from 1 to 99.

**Solution:** [P7_1.cpp](P7_1.cpp)

**Output**

```
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 
```

## P7.2: Sum of digits

Input a number and display the sum of its digits.

**Solution:** [P7_2.cpp](P7_2.cpp)

**Sample run**

```
Enter a number: 4072
Sum of digits = 13
```

## P7.3: Palindrome number

Input a number and check whether it is a palindrome (reads the same both ways, such as 1221).

**Solution:** [P7_3.cpp](P7_3.cpp)

**Sample run 1**

```
Enter a number: 1221
1221 is a palindrome
```

**Sample run 2**

```
Enter a number: 1234
1234 is not a palindrome
```

## P7.4: Largest and smallest

Input numbers until the user enters 0. Display the largest and smallest numbers entered.

**Solution:** [P7_4.cpp](P7_4.cpp)

**Sample run**

```
Enter numbers (0 to stop): 45 12 -7 88 30 0
Largest : 88
Smallest: -7
```

## P7.5: Armstrong number

Input a number and check whether it is an Armstrong number. A three-digit number is an Armstrong number if the sum of the cubes of its digits equals the number, for example 153 = 1^3 + 5^3 + 3^3.

**Solution:** [P7_5.cpp](P7_5.cpp)

**Sample run 1**

```
Enter a three-digit number: 153
153 is an Armstrong number
```

**Sample run 2**

```
Enter a three-digit number: 154
154 is not an Armstrong number
```

## P7.6: PIN with three tries

Keep asking for a PIN until the user enters 1234. Allow at most three tries, then display "Card blocked".

**Solution:** [P7_6.cpp](P7_6.cpp)

**Sample run 1**

```
Enter PIN: 1111
Wrong PIN
Enter PIN: 1234
PIN accepted
```

**Sample run 2**

```
Enter PIN: 1111
Wrong PIN
Enter PIN: 2222
Wrong PIN
Enter PIN: 3333
Wrong PIN
Card blocked
```

## P7.7: Unit converter

Write a menu-driven program for a unit converter: 1. Km to miles  2. Kg to pounds  3. Celsius to Fahrenheit  4. Exit. The menu should repeat until 4 is chosen.

**Solution:** [P7_7.cpp](P7_7.cpp)

**Sample run**

```

1. Km to miles  2. Kg to pounds  3. Celsius to Fahrenheit  4. Exit
Choice: 1
Kilometres: 10
10 km = 6.21371 miles

1. Km to miles  2. Kg to pounds  3. Celsius to Fahrenheit  4. Exit
Choice: 3
Celsius: 37
37 C = 98.6 F

1. Km to miles  2. Kg to pounds  3. Celsius to Fahrenheit  4. Exit
Choice: 4
Goodbye
```

## P7.8: Sum and sum of squares

Input N and display the sum of the series 1 + 2 + 3 + ... + N and the sum of the squares 1^2 + 2^2 + ... + N^2.

**Solution:** [P7_8.cpp](P7_8.cpp)

**Sample run**

```
Enter N: 10
1 + 2 + ... + 10 = 55
1^2 + 2^2 + ... + 10^2 = 385
```

## P7.9: Fibonacci series

Input N and display the first N terms of the Fibonacci series: 0, 1, 1, 2, 3, 5, 8, ...

**Solution:** [P7_9.cpp](P7_9.cpp)

**Sample run**

```
How many terms: 12
0 1 1 2 3 5 8 13 21 34 55 89 
```

## P7.10: Power without pow

Input x and n and display x^n without using `pow`.

**Solution:** [P7_10.cpp](P7_10.cpp)

**Sample run**

```
Enter x and n: 2 10
2^10 = 1024
```

This solution assumes n is 0 or positive.

## P7.11: Pass, fail and average

Input the marks of 10 students. Display the number of students who passed (50 or more), the number who failed, and the class average.

**Solution:** [P7_11.cpp](P7_11.cpp)

**Sample run**

```
Enter marks of 10 students: 72 45 88 50 39 64 91 55 47 70
Passed       : 7
Failed       : 3
Class average: 62.1
```

## P7.12: Prime numbers

Display all the prime numbers between 1 and 100.

**Solution:** [P7_12.cpp](P7_12.cpp)

**Output**

```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
```

A divisor larger than the square root of n would pair with a smaller one, so testing up to `d * d <= n` is enough.

## P7.13: Tables of 2 to 9

Display the tables of 2 to 9, each up to 10, one after another.

**Solution:** [P7_13.cpp](P7_13.cpp)

**Output**

```
Table of 2
2 x  1 =  2
2 x  2 =  4
2 x  3 =  6
2 x  4 =  8
2 x  5 = 10
2 x  6 = 12
2 x  7 = 14
2 x  8 = 16
2 x  9 = 18
2 x 10 = 20

Table of 3
3 x  1 =  3
3 x  2 =  6
3 x  3 =  9
3 x  4 = 12
3 x  5 = 15
3 x  6 = 18
3 x  7 = 21
3 x  8 = 24
3 x  9 = 27
3 x 10 = 30

Table of 4
4 x  1 =  4
4 x  2 =  8
4 x  3 = 12
4 x  4 = 16
4 x  5 = 20
4 x  6 = 24
4 x  7 = 28
4 x  8 = 32
4 x  9 = 36
4 x 10 = 40

Table of 5
5 x  1 =  5
5 x  2 = 10
5 x  3 = 15
5 x  4 = 20
5 x  5 = 25
5 x  6 = 30
5 x  7 = 35
5 x  8 = 40
5 x  9 = 45
5 x 10 = 50

Table of 6
6 x  1 =  6
6 x  2 = 12
6 x  3 = 18
6 x  4 = 24
6 x  5 = 30
6 x  6 = 36
6 x  7 = 42
6 x  8 = 48
6 x  9 = 54
6 x 10 = 60

Table of 7
7 x  1 =  7
7 x  2 = 14
7 x  3 = 21
7 x  4 = 28
7 x  5 = 35
7 x  6 = 42
7 x  7 = 49
7 x  8 = 56
7 x  9 = 63
7 x 10 = 70

Table of 8
8 x  1 =  8
8 x  2 = 16
8 x  3 = 24
8 x  4 = 32
8 x  5 = 40
8 x  6 = 48
8 x  7 = 56
8 x  8 = 64
8 x  9 = 72
8 x 10 = 80

Table of 9
9 x  1 =  9
9 x  2 = 18
9 x  3 = 27
9 x  4 = 36
9 x  5 = 45
9 x  6 = 54
9 x  7 = 63
9 x  8 = 72
9 x  9 = 81
9 x 10 = 90
```

## P7.14: Four patterns

Input N and print each of the four patterns shown in the book (shown for N = 4).

**Solution:** [P7_14.cpp](P7_14.cpp)

**Sample run**

```
Enter N: 4
1 
1 2 
1 2 3 
1 2 3 4 

* * * * 
* * * 
* * 
* 

   * 
  * * 
 * * * 
* * * * 

   1 
  2 2 
 3 3 3 
4 4 4 4 
```

## P7.15: Total and average of each student

Input the marks of 5 students in 3 subjects each. For every student display the total and the average.

**Solution:** [P7_15.cpp](P7_15.cpp)

**Sample run**

```
Marks of student 1 in 3 subjects: 72 85 64
  Total = 221, Average = 73.6667
Marks of student 2 in 3 subjects: 90 88 79
  Total = 257, Average = 85.6667
Marks of student 3 in 3 subjects: 45 52 60
  Total = 157, Average = 52.3333
Marks of student 4 in 3 subjects: 66 70 75
  Total = 211, Average = 70.3333
Marks of student 5 in 3 subjects: 81 77 93
  Total = 251, Average = 83.6667
```

## P7.16: Stop after 1000

Input numbers one by one and add them up. Stop as soon as the total goes over 1000, and display how many numbers were added.

**Solution:** [P7_16.cpp](P7_16.cpp)

**Sample run**

```
Enter a number: 250
Enter a number: 400
Enter a number: 180
Enter a number: 300
Total = 1130 after 4 numbers
```

## P7.17: Using continue

Display the numbers from 1 to 50 except those divisible by 5, using `continue`.

**Solution:** [P7_17.cpp](P7_17.cpp)

**Output**

```
1 2 3 4 6 7 8 9 11 12 13 14 16 17 18 19 21 22 23 24 26 27 28 29 31 32 33 34 36 37 38 39 41 42 43 44 46 47 48 49 
```
