# Chapter 3: Your First C++ Program

Solutions to the Practice Programs of Chapter 3. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P3_1.cpp -o P3_1` (or press F11 in Dev-C++).

## P3.1: Name, class and city

Print your name, class and city on three separate lines using `endl`.

**Solution:** [P3_1.cpp](P3_1.cpp)

**Output**

```
Name : Ayesha Khan
Class: BS (CS) Semester 1
City : Okara
```

## P3.2: Address with one cout

Print your home address on four lines using a **single** `cout` statement and `\n`.

**Solution:** [P3_2.cpp](P3_2.cpp)

**Output**

```
House No. 12, Street 4
College Road
Okara
Punjab, Pakistan
```

## P3.3: Welcome message in a box

Print the welcome message in a box of stars, exactly as shown in the book.

**Solution:** [P3_3.cpp](P3_3.cpp)

**Output**

```
**************************
*  Welcome to BS (CS)    *
*  Programming in C++    *
**************************
```

## P3.4: Text with double quotes

Print the motto of Pakistan with its quotes: `"Unity, Faith, Discipline"`.

**Solution:** [P3_4.cpp](P3_4.cpp)

**Output**

```
"Unity, Faith, Discipline"
```

Inside a string, `\"` prints a double quote.

## P3.5: A path with backslashes

Print the path `C:\Program Files\Dev-Cpp\bin` exactly.

**Solution:** [P3_5.cpp](P3_5.cpp)

**Output**

```
C:\Program Files\Dev-Cpp\bin
```

Inside a string, `\\` prints one backslash.

## P3.6: Timetable with tabs

Use `\t` to print the timetable in neat columns.

**Solution:** [P3_6.cpp](P3_6.cpp)

**Output**

```
Day	Subject	Room
Monday	PF	Lab-1
Tuesday	DLD	Room-12
```

Each `\t` moves to the next tab position, so the columns line up. The exact spacing depends on the tab width of the console.

## P3.7: The letter C

Print the letter **C** in large size using `*`, 5 lines tall.

**Solution:** [P3_7.cpp](P3_7.cpp)

**Output**

```
 *****
*
*
*
 *****
```

## P3.8: Triangle of stars

Print the triangle of stars shown in the book.

**Solution:** [P3_8.cpp](P3_8.cpp)

**Output**

```
    *
   ***
  *****
 *******
```

## P3.9: Sum, difference and product

Print the sum, difference and product of 48 and 12, each with a label. For example: `48 + 12 = 60`.

**Solution:** [P3_9.cpp](P3_9.cpp)

**Output**

```
48 + 12 = 60
48 - 12 = 36
48 x 12 = 576
```

## P3.10: Total and average

A student got 78, 85 and 91 marks. Print the total and the average with labels. Use brackets so the average is correct.

**Solution:** [P3_10.cpp](P3_10.cpp)

**Output**

```
Total   = 254
Average = 84.6667
```

Without the brackets, only 91 would be divided by 3. Writing `3.0` instead of `3` keeps the decimal part of the answer; Chapter 5 explains why `(78 + 85 + 91) / 3` gives 84.

## P3.11: Area of a room

Print the area of a room that is 14 feet long and 12 feet wide, in square feet.

**Solution:** [P3_11.cpp](P3_11.cpp)

**Output**

```
Area of the room = 168 square feet
```
