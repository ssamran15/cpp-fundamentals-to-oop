# Chapter 30: Streams and Object File I/O

Solutions to the Practice Programs of Chapter 30. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P30_1.cpp -o P30_1` (or press F11 in Dev-C++).

## P30.1: One function for any output stream

Write a function `void table(ostream &out, int n)` that prints the multiplication table of `n`. Call it once with `cout` and once with an `ofstream`, then read the file back and count its lines.

**Solution:** [P30_1.cpp](P30_1.cpp)

**Output**

```
Table of 7 on the screen:
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
table9.txt has 10 lines
```

**table9.txt** (after the run)

```
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

An `ofstream` is a kind of `ostream` (Section 30.1), so the same `table` function writes to the screen or to a file.

## P30.2: Valid and invalid entries

A file holds daily temperatures separated by spaces, but some entries are not numbers. Count the valid and invalid entries and find the average of the valid ones, using the stream state functions.

**Solution:** [P30_2.cpp](P30_2.cpp)

**temperatures.txt** (input file)

```
31.5 33 29.5 x7 35 36.5 ?? 30 32
34 n/a 28.5
```

**Output**

```
Skipped "x7"
Skipped "??"
Skipped "n/a"
Valid entries: 9, invalid entries: 3
Average of the valid entries: 32.2222
```

This follows Program 30.2: when `in >> t` fails and `eof()` is false, the entry is not a number, so the flags are cleared with `clear()` and the bad word is read into a `string` and thrown away. Note that `x7` is rejected as a whole word, because `>>` stops at once on the letter.

## P30.3: Employees in a CSV file

Write a class `Employee` (ID, full name, salary) with `<<` and `>>` using a CSV format. Read five employees from the keyboard, save them to a file, then read the file and print the employee with the highest salary.

**Solution:** [P30_3.cpp](P30_3.cpp)

**Sample run**

```
Enter 5 employees as id,full name,salary:
1001,Asad Mehmood,57000
1002,Rabia Saleem,77500
1003,Imran Haider,47000
1004,Nadia Akram,76000
1005,Kamran Yousaf,78000
Saved to employees.csv
Highest salary: 1005,Kamran Yousaf,78000
```

**employees.csv** (after the run)

```
1001,Asad Mehmood,57000
1002,Rabia Saleem,77500
1003,Imran Haider,47000
1004,Nadia Akram,76000
1005,Kamran Yousaf,78000
```

`>>` reads the ID and the full name up to the next comma with `getline(in, field, ',')`, so a name may contain spaces. `stoi` and `stod` (Section 12.3) turn the text into numbers.

## P30.4: Holidays in a month

Write a class `Date` with `<<` and `>>` using the format `dd/mm/yyyy`. Read a list of holidays from a file and print those that fall in a month typed by the user.

**Solution:** [P30_4.cpp](P30_4.cpp)

**holidays.txt** (input file)

```
05/02/2026 Kashmir Day
23/03/2026 Pakistan Day
01/05/2026 Labour Day
14/08/2026 Independence Day
09/11/2026 Iqbal Day
25/12/2026 Quaid-e-Azam Day
```

**Sample run 1**

```
Month (1 to 12): 8
14/08/2026 Independence Day
```

**Sample run 2**

```
Month (1 to 12): 3
23/03/2026 Pakistan Day
```

**Sample run 3**

```
Month (1 to 12): 7
No holidays in that month
```

## P30.5: A bill with string streams

A file holds one purchase per line as `item quantity price`. Read each line with `getline()`, split it with an `istringstream`, build each output line with an `ostringstream`, and print the bill and its total.

**Solution:** [P30_5.cpp](P30_5.cpp)

**purchases.txt** (input file)

```
Rice 2 1850
Sugar 3 160
Tea 1 650
Oil 2 590
Soap 6 120
```

**Output**

```
Rice           2 x  1850.00 =   3700.00
Sugar          3 x   160.00 =    480.00
Tea            1 x   650.00 =    650.00
Oil            2 x   590.00 =   1180.00
Soap           6 x   120.00 =    720.00
------------------
Total: Rs. 6730.00
```

## P30.6: Books in a binary file

Write a class `Book` (code, title as `char[40]`, price) with `save()` and `load()` functions. Store ten books in a binary file and search for a book by its code.

**Solution:** [P30_6.cpp](P30_6.cpp)

**Sample run 1**

```
10 books saved to books.dat
Code to search: 107
107  Digital Logic  Rs. 900
```

**Sample run 2**

```
10 books saved to books.dat
Code to search: 120
No book with code 120
```

The title is a `char` array so that every `Book` has the same fixed size and can be written with `write()` as it is (Section 30.5). `strncpy` copies at most 39 characters and the last one is set to `'\0'`, so a long title cannot overflow the array.

## P30.7: Deleting a record

Add a "Delete record" choice to Program 30.7. Copy every record except the one to be deleted to a temporary file, then use `remove()` and `rename()` from `<cstdio>` to replace the old file.

**Solution:** [P30_7.cpp](P30_7.cpp)

**Sample run**

```

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 1
Roll no: 101
Name: Ayesha Khan
CGPA: 3.62

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 1
Roll no: 102
Name: Bilal Ahmed
CGPA: 3.15

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 1
Roll no: 103
Name: Fatima Noor
CGPA: 3.88

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 2
  101  Ayesha Khan  3.62
  102  Bilal Ahmed  3.15
  103  Fatima Noor  3.88
  3 record(s)

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 5
Roll no: 102
  Deleted

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 2
  101  Ayesha Khan  3.62
  103  Fatima Noor  3.88
  2 record(s)

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 5
Roll no: 999
  Not found

1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: 0
```

Only the new parts are explained here; the rest is Program 30.7 unchanged. The class's own function is also called `remove`, so the library functions are written `std::remove` and `std::rename` to make clear which one is meant. If the roll number is not found, the temporary file is deleted and the original is left alone.

## P30.8: Lines, words and the longest line

Read a text file and print the number of lines, the number of words and the longest line, using `getline()` and an `istringstream` for each line.

**Solution:** [P30_8.cpp](P30_8.cpp)

**Sample run**

```
File name: notice.txt
Lines: 3
Words: 21
Longest line (54 characters): Mobile phones are not allowed in the examination hall.
```

`notice.txt` is the file used in Chapter 15. Compare with P15.2, which counted words character by character: `>>` on an `istringstream` does the splitting for us.
