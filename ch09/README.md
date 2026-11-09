# Chapter 9: Functions II

Solutions to the Practice Programs of Chapter 9. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P9_1.cpp -o P9_1` (or press F11 in Dev-C++).

## P9.1: Sorting three numbers

Write a function `void sortTwo(int &a, int &b)` that puts the smaller value in `a` and the larger in `b`. Use it to sort three numbers entered by the user.

**Solution:** [P9_1.cpp](P9_1.cpp)

**Sample run**

```
Enter three numbers: 42 7 19
In ascending order: 7 19 42
```

Three calls of `sortTwo` are enough to sort three numbers, as the comments in the code show.

## P9.2: Smallest and largest

Write a function `void minMax(int a, int b, int c, int &smallest, int &largest)` and display both results.

**Solution:** [P9_2.cpp](P9_2.cpp)

**Sample run**

```
Enter three numbers: 35 -4 61
Smallest = -4
Largest = 61
```

## P9.3: Area and circumference

Write a function `void circle(double r, double &area, double &circumference)`.

**Solution:** [P9_3.cpp](P9_3.cpp)

**Sample run**

```
Enter the radius: 7
Area = 153.938
Circumference = 43.9823
```

## P9.4: Converting seconds

Write a function `void convertTime(int totalSeconds, int &h, int &m, int &s)`.

**Solution:** [P9_4.cpp](P9_4.cpp)

**Sample run**

```
Enter time in seconds: 9875
9875 seconds = 2 h 44 min 35 s
```

## P9.5: Default arguments

Write a function `double simpleProfit(double amount, double rate = 12.5, int years = 1)`. Call it with one, two and three arguments.

**Solution:** [P9_5.cpp](P9_5.cpp)

**Output**

```
One argument:    12500
Two arguments:   15000
Three arguments: 45000
```

The default values are written only in the prototype, not again in the definition.

## P9.6: Overloaded area

Write overloaded functions `area` for a circle (one `double`), a rectangle (two `double`s) and a triangle given three sides (three `double`s, using Heron's formula).

**Solution:** [P9_6.cpp](P9_6.cpp)

**Sample run**

```
Radius of the circle: 5
Length and width of the rectangle: 8 3.5
Three sides of the triangle: 3 4 5
Circle area = 78.5397
Rectangle area = 28
Triangle area = 6
```

## P9.7: Overloaded display

Write overloaded functions `display` that print an `int`, a `double` with 2 decimal places, and a `char` repeated n times.

**Solution:** [P9_7.cpp](P9_7.cpp)

**Output**

```
int: 250
double: 3.14
********************
```

## P9.8: Recursive sum

Write a recursive function to find the sum 1 + 2 + … + n.

**Solution:** [P9_8.cpp](P9_8.cpp)

**Sample run**

```
Enter n: 100
1 + 2 + ... + 100 = 5050
```

## P9.9: Recursive GCD

Write a recursive function `int gcd(int a, int b)` using the rule gcd(a, b) = gcd(b, a % b), and gcd(a, 0) = a.

**Solution:** [P9_9.cpp](P9_9.cpp)

**Sample run**

```
Enter two positive numbers: 48 36
GCD = 12
```

## P9.10: Digits in reverse

Write a recursive function that prints the digits of a number in reverse order.

**Solution:** [P9_10.cpp](P9_10.cpp)

**Sample run**

```
Enter a number: 58301
Reversed: 10385
```

## P9.11: Binary form

Write a recursive function that displays a number in binary. For example, 13 is displayed as 1101.

**Solution:** [P9_11.cpp](P9_11.cpp)

**Sample run 1**

```
Enter a number: 13
13 in binary is 1101
```

**Sample run 2**

```
Enter a number: 100
100 in binary is 1100100
```

## P9.12: Recursive palindrome check

Write a recursive function `bool isPalindrome(int n, int reversed = 0)` or any other recursive method to check whether a number is a palindrome.

**Solution:** [P9_12.cpp](P9_12.cpp)

**Sample run 1**

```
Enter a number: 45654
45654 is a palindrome
```

**Sample run 2**

```
Enter a number: 4565
4565 is not a palindrome
```

Here the recursion is in `reverseNumber`, which carries the reversed digits in its second parameter. `isPalindrome` then compares the number with its reverse.

## P9.13: Rolling a dice 600 times

Simulate 600 rolls of a dice and display how many times each face (1 to 6) appeared.

**Solution:** [P9_13.cpp](P9_13.cpp)

**Output**

```
Face  Count
1     83
2     100
3     110
4     84
5     103
6     120
```

The numbers are random, so your output will be different each time. Each face should come up about 100 times. Arrays (Chapter 10) will make this program much shorter.

## P9.14: Maths quiz

Write a maths quiz for a child: show 10 questions of the form `7 + 4 = ?` with random numbers from 1 to 20, take the answers, and display the score.

**Solution:** [P9_14.cpp](P9_14.cpp)

**Sample run**

```
Q1: 11 + 1 = ? 12
Correct!
Q2: 11 + 9 = ? 20
Correct!
Q3: 12 + 4 = ? 16
Correct!
Q4: 16 + 3 = ? 20
Wrong. The answer is 19.
Q5: 3 + 15 = ? 18
Correct!
Q6: 10 + 1 = ? 11
Correct!
Q7: 6 + 14 = ? 20
Correct!
Q8: 11 + 8 = ? 19
Correct!
Q9: 14 + 14 = ? 29
Wrong. The answer is 28.
Q10: 16 + 16 = ? 32
Correct!

Your score: 8 out of 10
```

The numbers are random, so your output will be different each time.

## P9.15: Tossing a coin

Write a function `char tossCoin()` that returns `'H'` or `'T'` at random. Toss the coin 100 times and display the number of heads and tails.

**Solution:** [P9_15.cpp](P9_15.cpp)

**Output**

```
Heads: 55
Tails: 45
```

The numbers are random, so your output will be different each time.
