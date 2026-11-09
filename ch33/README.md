# Chapter 33: Exception Handling

Solutions to the Practice Programs of Chapter 33. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P33_1.cpp -o P33_1` (or press F11 in Dev-C++).

## P33.1: Division by zero

Write a function `double divide(double a, double b)` that throws `runtime_error("division by zero")` when `b` is `0`. In `main`, divide five pairs of numbers stored in two arrays, catching the error for each pair so that all five pairs are processed.

**Solution:** [P33_1.cpp](P33_1.cpp)

**Output**

```
45 / 9 = 5
7 / 0: error, division by zero
100 / 8 = 12.5
3.5 / 0: error, division by zero
0 / 4 = 0
All five pairs processed
```

The `try` block is inside the loop, so after an error the loop simply goes on to the next pair. The result is stored before anything is printed, so a failed division prints only the error line.

## P33.2: Reading a valid age

Write a function `readAge()` that reads a line with `getline`, converts it with `stoi`, and throws `invalid_argument` if the line is not a number and `out_of_range` if the age is not from 16 to 60. In `main`, keep asking until a valid age is entered.

**Solution:** [P33_2.cpp](P33_2.cpp)

**Sample run**

```
Age: twenty
Invalid: "twenty" is not a number
Age: 25abc
Invalid: "25abc" is not a number
Age: 70
Out of range: age 70 is not from 16 to 60
Age: 99999999999
Out of range: 99999999999 is far too large
Age: 
Invalid: nothing was typed
Age: 21
Accepted: 21
```

`stoi("25abc")` does not throw: it quietly returns 25. So `readAge` first checks that every character is a digit, and throws `invalid_argument` itself if not. A number too big for an `int`, such as 99999999999, makes `stoi` throw `out_of_range`; its own message is not helpful (GCC gives just "stoi"), so `readAge` catches it and throws a new `out_of_range` with a clearer message.

## P33.3: A Date that throws

Write a class `Date` whose constructor throws `invalid_argument` if the month is not from 1 to 12 or the day is not valid for that month (ignore leap years). Try to create four dates, two valid and two invalid, and report each result.

**Solution:** [P33_3.cpp](P33_3.cpp)

**Output**

```
Created 14/8/2026
Rejected 31/4/2026: day 31 is not valid for month 4
Created 25/12/2026
Rejected 10/13/2026: month 13 is not from 1 to 12
```

When a constructor throws, the object is never created, so there is no invalid `Date` that could be used by mistake (Section 33.7.1).

## P33.4: Stack with standard exceptions

Write a class template `Stack` that holds at most 5 items. `push()` throws `overflow_error` when the stack is full and `pop()` throws `underflow_error` when it is empty. Test it with `Stack<int>` and `Stack<string>`.

**Solution:** [P33_4.cpp](P33_4.cpp)

**Output**

```
Pushed 10
Pushed 20
Pushed 30
Pushed 40
Pushed 50
Error: stack is full
Popped Lahore
Popped Okara
Error: stack is empty
```

Compare with Program 31.7, where `push` and `pop` returned `false`. With exceptions, `pop()` can return the item itself, and a mistake cannot be ignored silently.

## P33.5: Marks from a file

Read the marks of students from a file named by the user. Throw `runtime_error` if the file cannot be opened, and catch `invalid_argument` for any line that is not a number, reporting the line number and skipping it. Print the average of the valid marks.

**Solution:** [P33_5.cpp](P33_5.cpp)

**marks3.txt** (input file)

```
72
85
abc
64

91
n/a
58
```

**Sample run 1**

```
File name: marks3.txt
Line 3 skipped: "abc" is not a number
Line 5 skipped: "" is not a number
Line 7 skipped: "n/a" is not a number
Average of the valid marks: 74
```

**Sample run 2**

```
File name: marks4.txt
Error: cannot open marks4.txt
```

Line 5 of the file is empty, and `stoi("")` also throws `invalid_argument`. As in P33.2, `stoi` would accept a line such as `7x` as 7; the check of P33.2 could be added if that matters.

## P33.6: Matrix errors

Write a class `Matrix` with an `operator+` that throws `invalid_argument` when the two matrices have different sizes, and an element access function that throws `out_of_range` for a bad row or column.

**Solution:** [P33_6.cpp](P33_6.cpp)

**Output**

```
a + b:
   10   11
   21   22
a + c:
Error: cannot add a 2 x 2 matrix to a 3 x 2 matrix
Error: element (2, 0) is outside a 2 x 2 matrix
```

`at()` is named after `vector::at()` (Section 32.4), which also throws `out_of_range`. The text "a + c:" is printed before `+` throws, so it appears just before the error.

## P33.7: Library with its own exceptions

Write a library system with a base exception class `LibraryError` (derived from `runtime_error`) and two derived classes `BookNotFound` and `BookAlreadyIssued`. `BookAlreadyIssued` should store the name of the student who has the book. Write a menu that never crashes.

**Solution:** [P33_7.cpp](P33_7.cpp)

**Sample run**

```

1. Issue  2. Return  3. List  0. Exit
Choice: 1
Title: Learning Databases
Student: Ayesha Khan
Issued.

1. Issue  2. Return  3. List  0. Exit
Choice: 1
Title: Learning Databases
Student: Bilal Ahmed
Refused: "Learning Databases" is already issued to Ayesha Khan

1. Issue  2. Return  3. List  0. Exit
Choice: 1
Title: Data Structures
Student: Hamza Ali
Library error: no book called "Data Structures"

1. Issue  2. Return  3. List  0. Exit
Choice: 2
Title: Networks for Beginners
Library error: "Networks for Beginners" was not issued

1. Issue  2. Return  3. List  0. Exit
Choice: seven
Input error: "seven" is not a menu number

1. Issue  2. Return  3. List  0. Exit
Choice: 3
  Computer Science Made Easy  (on the shelf)
  Learning Databases  (with Ayesha Khan)
  Networks for Beginners  (on the shelf)

1. Issue  2. Return  3. List  0. Exit
Choice: 2
Title: Learning Databases
Returned.

1. Issue  2. Return  3. List  0. Exit
Choice: 3
  Computer Science Made Easy  (on the shelf)
  Learning Databases  (on the shelf)
  Networks for Beginners  (on the shelf)

1. Issue  2. Return  3. List  0. Exit
Choice: 0
Goodbye.
```

The `catch` blocks go from the most specific class to the most general: `BookAlreadyIssued` first, then `LibraryError`, which also catches `BookNotFound` and the "was not issued" error.

## P33.8: Transfer that never loses money

Extend Program 33.11 with a **Transfer** option that moves money from one account to another. If the withdrawal succeeds but the second account is not found, the money must be returned to the first account before the error is reported, so that no money is ever lost.

**Solution:** [P33_8.cpp](P33_8.cpp)

**Sample run**

```

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 1
Title: Ayesha
Opening balance: 20000
Account 1001 opened.

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 1
Title: Bilal
Opening balance: 5000
Account 1002 opened.

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 5
From account: 1001
To account: 1002
Amount: 3000
Transferred.

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 5
From account: 1001
To account: 1009
Amount: 4000
Bank error: no account has number 1009

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 5
From account: 1002
To account: 1001
Amount: 9000
Refused: insufficient funds, short by Rs. 1000.00

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 4
  1001  Ayesha      17000.00
  1002  Bilal        8000.00

1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit
Choice: 0
Goodbye.
```

Only `Bank::transfer` and menu choice 5 are new; the rest is Program 33.11 unchanged. In the second transfer, Rs. 4000 is taken from account 1001, account 1009 is not found, and the `catch (...)` block deposits the money back before `throw;` passes the same error on (Section 33.10). The final list shows account 1001 with Rs. 17000, so nothing was lost.
