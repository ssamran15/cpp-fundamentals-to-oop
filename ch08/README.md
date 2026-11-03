# Chapter 8: Functions I

Solutions to the Practice Programs of Chapter 8. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P8_1.cpp -o P8_1` (or press F11 in Dev-C++).

## P8.1: Heading in a box

Write a function `printHeading()` that prints your college name inside a box of `*`. Call it at the top of a program.

**Solution:** [P8_1.cpp](P8_1.cpp)

**Output**

```
*********************************
*                               *
* Govt. Graduate College, Okara *
*                               *
*********************************
Programming Fundamentals (C++)
```

## P8.2: Multiplication tables

Write a function `printTable(int n)` that prints the multiplication table of n. In `main`, call it for 2, 5 and 9.

**Solution:** [P8_2.cpp](P8_2.cpp)

**Output**

```
Table of 2
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20

Table of 5
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50

Table of 9
9 x 1 = 9
9 x 2 = 18
9 x 3 = 27
9 x 4 = 36
9 x 5 = 45
9 x 6 = 54
9 x 7 = 63
9 x 8 = 72
9 x 9 = 81
9 x 10 = 90
```

## P8.3: Right triangle

Write a function `printPattern(int rows)` that prints a right triangle of `*` with the given number of rows.

**Solution:** [P8_3.cpp](P8_3.cpp)

**Sample run**

```
Enter the number of rows: 5
*
**
***
****
*****
```

## P8.4: Celsius to Fahrenheit table

Write a function `double celsiusToFahrenheit(double c)`. In `main`, display a conversion table from 0°C to 100°C in steps of 10.

**Solution:** [P8_4.cpp](P8_4.cpp)

**Output**

```
   Celsius    Fahrenheit
         0            32
        10            50
        20            68
        30            86
        40           104
        50           122
        60           140
        70           158
        80           176
        90           194
       100           212
```

## P8.5: Sum of digits

Write a function `int sumOfDigits(int n)` and use it to display the sum of the digits of a number entered by the user.

**Solution:** [P8_5.cpp](P8_5.cpp)

**Sample run**

```
Enter a number: 4072
Sum of digits = 13
```

## P8.6: Counting even numbers

Write a function `bool isEven(int n)`. Use it to count the even numbers among 10 numbers entered by the user.

**Solution:** [P8_6.cpp](P8_6.cpp)

**Sample run**

```
Enter 10 numbers: 12 7 30 45 8 19 22 3 64 11
Even numbers entered: 5
```

## P8.7: Power with a loop

Write a function `long long power(int base, int exp)` that calculates base^exp with a loop, without using `pow`.

**Solution:** [P8_7.cpp](P8_7.cpp)

**Sample run 1**

```
Enter base and exponent: 2 30
2^30 = 1073741824
```

**Sample run 2**

```
Enter base and exponent: 7 0
7^0 = 1
```

This solution assumes the exponent is 0 or positive. `long long` holds results that are too big for `int`, such as 2^40.

## P8.8: Reverse and palindrome

Write a function `int reverse(int n)` and a function `bool isPalindrome(int n)` that uses it.

**Solution:** [P8_8.cpp](P8_8.cpp)

**Sample run 1**

```
Enter a number: 12321
Reverse: 12321
12321 is a palindrome
```

**Sample run 2**

```
Enter a number: 1234
Reverse: 4321
1234 is not a palindrome
```

## P8.9: Income tax

Write a function `double calculateTax(double salary)` using these rules: no tax up to Rs. 50,000; 5% on the amount above Rs. 50,000 up to Rs. 100,000; 10% on the amount above Rs. 100,000. Display the tax for a salary entered by the user.

**Solution:** [P8_9.cpp](P8_9.cpp)

**Sample run 1**

```
Enter monthly salary (Rs.): 45000
Tax = Rs. 0.00
```

**Sample run 2**

```
Enter monthly salary (Rs.): 80000
Tax = Rs. 1500.00
```

**Sample run 3**

```
Enter monthly salary (Rs.): 120000
Tax = Rs. 4500.00
```

For Rs. 120,000 the tax is 5% of 50,000 (Rs. 2,500) for the middle slab plus 10% of 20,000 (Rs. 2,000) for the top slab.

## P8.10: First 15 primes

Write functions `isPrime` and `nextPrime(int n)` (the smallest prime greater than n). Display the first 15 prime numbers using them.

**Solution:** [P8_10.cpp](P8_10.cpp)

**Output**

```
The first 15 prime numbers:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
```

## P8.11: Student result

Write functions `inputMarks()`, `calculatePercentage(int obtained, int total)` and `findDivision(double percent)`. Use them to print a student's result.

**Solution:** [P8_11.cpp](P8_11.cpp)

**Sample run 1**

```
Enter obtained marks (out of 1100): 842
Marks: 842 / 1100
Percentage: 76.55%
Division: First
```

**Sample run 2**

```
Enter obtained marks (out of 1100): 1200
Invalid marks. Enter again: 455
Marks: 455 / 1100
Percentage: 41.36%
Division: Third
```

Marks are out of 1100, with the divisions used in Chapter 6: First (60% and above), Second (45% to below 60%), Third (33% to below 45%) and Fail (below 33%). Strings come in Chapter 12, so `findDivision` prints the division itself.

## P8.12: Calculator menu

Write a menu-driven program with separate functions for addition, subtraction, multiplication and division of two numbers. The menu should repeat until the user exits.

**Solution:** [P8_12.cpp](P8_12.cpp)

**Sample run**

```

1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit
Choice: 1
Enter two numbers: 12 8
Result = 20

1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit
Choice: 4
Enter two numbers: 7 2
Result = 3.5

1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit
Choice: 4
Enter two numbers: 5 0
Cannot divide by zero

1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit
Choice: 5
Goodbye
```

## P8.13: GCD and LCM

Write a function `int gcd(int a, int b)` using the Euclidean method (repeatedly replace the larger number by the remainder of dividing it by the smaller). Use it to write `int lcm(int a, int b)`, since lcm = a × b / gcd.

**Solution:** [P8_13.cpp](P8_13.cpp)

**Sample run 1**

```
Enter two positive numbers: 12 18
GCD = 6
LCM = 36
```

**Sample run 2**

```
Enter two positive numbers: 21 6
GCD = 3
LCM = 42
```
