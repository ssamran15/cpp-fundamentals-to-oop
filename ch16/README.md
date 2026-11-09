# Chapter 16: Bitwise Operators, enums and Command-line Arguments

Solutions to the Practice Programs of Chapter 16. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P16_1.cpp -o P16_1` (or press F11 in Dev-C++).

## P16.1: Binary, octal and hexadecimal

Input an integer and display it in binary (using `bitset<16>`), octal and hexadecimal (using the `oct` and `hex` manipulators).

**Solution:** [P16_1.cpp](P16_1.cpp)

**Sample run 1**

```
Enter an integer: 2026
Binary      : 0000011111101010
Octal       : 3752
Hexadecimal : 7ea
```

**Sample run 2**

```
Enter an integer: 255
Binary      : 0000000011111111
Octal       : 377
Hexadecimal : ff
```

`oct` and `hex` stay in force for later output, so the program switches back with `dec` at the end.

## P16.2: Power of 2

Input a number and check whether it is a power of 2, using the test `n & (n - 1)`.

**Solution:** [P16_2.cpp](P16_2.cpp)

**Sample run 1**

```
Enter a number: 64
64 is a power of 2
```

**Sample run 2**

```
Enter a number: 96
96 is not a power of 2
```

For 64 (`1000000`), n - 1 is 63 (`0111111`), so the AND is 0. The brackets around `n & (n - 1)` are needed because `==` has higher precedence than `&`.

## P16.3: Set, clear and toggle a bit

Input a number and a bit position. Display the number in binary after setting, clearing and toggling that bit.

**Solution:** [P16_3.cpp](P16_3.cpp)

**Sample run 1**

```
Enter a number: 45
Bit position (0 is the rightmost bit): 1
Number         : 0000000000101101 (45)
After setting  : 0000000000101111 (47)
After clearing : 0000000000101101 (45)
After toggling : 0000000000101111 (47)
```

**Sample run 2**

```
Enter a number: 45
Bit position (0 is the rightmost bit): 2
Number         : 0000000000101101 (45)
After setting  : 0000000000101101 (45)
After clearing : 0000000000101001 (41)
After toggling : 0000000000101001 (41)
```

Bit positions count from 0 at the right, as in Section 16.3.1. Setting a bit that is already 1, or clearing one that is already 0, leaves the number unchanged.

## P16.4: Swapping with XOR

Input two integers and swap them using XOR, without a third variable.

**Solution:** [P16_4.cpp](P16_4.cpp)

**Sample run**

```
Enter two integers: 25 70
Before: a = 25, b = 70
After:  a = 70, b = 25
```

## P16.5: Attendance in one byte

A student's attendance for 8 days is stored in one `unsigned char`, one bit per day. Input the attendance day by day (1 or 0), store it in the bits, and display the days on which the student was present and the total.

**Solution:** [P16_5.cpp](P16_5.cpp)

**Sample run**

```
Day 1 (1 present, 0 absent): 1
Day 2 (1 present, 0 absent): 1
Day 3 (1 present, 0 absent): 0
Day 4 (1 present, 0 absent): 1
Day 5 (1 present, 0 absent): 1
Day 6 (1 present, 0 absent): 0
Day 7 (1 present, 0 absent): 1
Day 8 (1 present, 0 absent): 1

Stored byte: 11011011
Present on days: 1 2 4 5 7 8
Total days present: 6 out of 8
```

Day 1 is stored in bit 0, the rightmost bit, so the byte reads from day 8 on the left to day 1 on the right.

## P16.6: Days in a month

Define `enum Month { JAN = 1, FEB, ..., DEC }`. Input a month number and use a `switch` on the enumerators to display the number of days in that month.

**Solution:** [P16_6.cpp](P16_6.cpp)

**Sample run 1**

```
Enter a month number (1 to 12): 2
28 days (29 in a leap year)
```

**Sample run 2**

```
Enter a month number (1 to 12): 9
30 days
```

**Sample run 3**

```
Enter a month number (1 to 12): 12
31 days
```

## P16.7: Area menu with enum class

Define `enum class Shape { CIRCLE, RECTANGLE, TRIANGLE }`. Write a menu program that asks for a shape, inputs its dimensions and displays its area.

**Solution:** [P16_7.cpp](P16_7.cpp)

**Sample run**

```

1. Circle  2. Rectangle  3. Triangle  0. Exit
Choice: 1
Radius: 7
Area = 153.938

1. Circle  2. Rectangle  3. Triangle  0. Exit
Choice: 3
Base and height: 10 6
Area = 30

1. Circle  2. Rectangle  3. Triangle  0. Exit
Choice: 0
```

A scoped enumeration does not convert to and from `int` by itself, so the menu number is converted with `static_cast<Shape>`. The triangle uses base and height.

## P16.8: Grades with enum class

Define `enum class Grade { A, B, C, D, F }` and write a function `Grade gradeOf(int marks)`. Display the grade for marks entered by the user, using a `switch` to print the letter.

**Solution:** [P16_8.cpp](P16_8.cpp)

**Sample run 1**

```
Enter marks: 83
Grade: A
```

**Sample run 2**

```
Enter marks: 44
Grade: D
```

The limits used are A (80+), B (65 to 79), C (50 to 64), D (40 to 49) and F (below 40).

## P16.9: Command-line calculator

Write a command-line calculator `calc` that is run as `calc 12 + 5`. Support `+`, `-`, `x` (for multiplication) and `/`, and display a usage message if the arguments are wrong.

**Solution:** [P16_9.cpp](P16_9.cpp)

**Run 1**

```
> calc 12 + 5
17
```

**Run 2**

```
> calc 7.5 x 4
30
```

**Run 3**

```
> calc 22 / 7
3.14286
```

**Run 4**

```
> calc 9 / 0
Cannot divide by zero
```

**Run 5**

```
> calc 12 +
Usage: calc number1 op number2   (op is +, -, x or /)
```

Compile it as `calc` (in Dev-C++, save the file as calc.cpp; from the Command Prompt, `g++ P16_9.cpp -o calc`). `x` is used for multiplication because the Command Prompt can treat `*` as a wildcard for file names.

## P16.10: File with line numbers

Write a program that receives a file name as a command-line argument and displays the file with line numbers. If no file name is given or the file cannot be opened, display an error and end with `EXIT_FAILURE`.

**Solution:** [P16_10.cpp](P16_10.cpp)

**Run 1**

```
> P16_10 notice.txt
1: Mid-term examinations will start on Monday.
2: Students must bring their college cards.
3: Mobile phones are not allowed in the examination hall.
```

**Run 2**

```
> P16_10
Usage: P16_10 filename
```

**Run 3**

```
> P16_10 missing.txt
Cannot open missing.txt
```

`notice.txt` is the same file as in Chapter 15.

## P16.11: Largest of any number of arguments

Write a function `int largest(int count, ...)` that returns the largest of its arguments. Call it with 3, 5 and 7 numbers.

**Solution:** [P16_11.cpp](P16_11.cpp)

**Output**

```
Largest of 3: 45
Largest of 5: 66
Largest of 7: 91
```

## P16.12: Ending with exit

Input the marks of 5 students. As soon as an invalid mark (outside 0 to 100) is entered, display a message and end the program with `exit`; otherwise display the average.

**Solution:** [P16_12.cpp](P16_12.cpp)

**Sample run 1**

```
Marks of student 1: 72
Marks of student 2: 85
Marks of student 3: 64
Marks of student 4: 90
Marks of student 5: 58
Average = 73.8
```

**Sample run 2**

```
Marks of student 1: 72
Marks of student 2: 85
Marks of student 3: 140
Invalid marks: 140. The program will end.
```

`exit` is called inside `readMarks`, yet it ends the whole program at once, so in the second run students 4 and 5 are never asked.
