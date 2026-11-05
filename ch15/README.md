# Chapter 15: Files and the Preprocessor

Solutions to the Practice Programs of Chapter 15. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P15_1.cpp -o P15_1` (or press F11 in Dev-C++).

## P15.1: Writing and reading contacts

Input the names and phone numbers of 5 friends and write them to `contacts.txt`, one per line. Then read the file back and display it as a table.

**Solution:** [P15_1.cpp](P15_1.cpp)

**Sample run**

```
Friend 1 name: Ali Raza
Phone: 0300-1234567
Friend 2 name: Sana Tariq
Phone: 0321-7654321
Friend 3 name: Hamza Ali
Phone: 0333-5550101
Friend 4 name: Fatima Noor
Phone: 0345-2223344
Friend 5 name: Usman Raza
Phone: 0312-9876543

Name                Phone
-----------------------------------
Ali Raza            0300-1234567
Sana Tariq          0321-7654321
Hamza Ali           0333-5550101
Fatima Noor         0345-2223344
Usman Raza          0312-9876543
```

**contacts.txt** (after the run)

```
Ali Raza,0300-1234567
Sana Tariq,0321-7654321
Hamza Ali,0333-5550101
Fatima Noor,0345-2223344
Usman Raza,0312-9876543
```

Each line holds the name and the phone number separated by a comma, so a name may contain spaces. The file is read back with `getline(in, name, ',')` as in Program 15.6.

## P15.2: Characters, words and lines

Input the name of a text file and display the number of characters, words and lines in it.

**Solution:** [P15_2.cpp](P15_2.cpp)

**notice.txt** (input file)

```
Mid-term examinations will start on Monday.
Students must bring their college cards.
Mobile phones are not allowed in the examination hall.
```

**Sample run 1**

```
File name: notice.txt
Characters: 137
Words: 21
Lines: 3
```

**Sample run 2**

```
File name: missing.txt
Cannot open missing.txt
```

Newline characters are counted as line ends, not as characters. A word starts wherever a non-space character follows a space, tab, newline or the start of the file.

## P15.3: Adding grades

Read `marks.txt` (name and marks on each line) and write a new file `result.txt` in which each line also shows the grade.

**Solution:** [P15_3.cpp](P15_3.cpp)

**marks.txt** (input file)

```
Ayesha 85
Bilal 72
Fatima 91
Hamza 58
Sana 66
Usman 43
```

**Output**

```
6 records written to result.txt
```

**result.txt** (after the run)

```
Ayesha 85 A
Bilal 72 B
Fatima 91 A
Hamza 58 C
Sana 66 B
Usman 43 F
```

The grades are those of P10.5: A (80+), B (65 to 79), C (50 to 64) and F (below 50). Names are read with `>>`, so each name is one word.

## P15.4: Searching contacts

Input a name and search `contacts.txt` for it. Display the phone number, or "Not found".

**Solution:** [P15_4.cpp](P15_4.cpp)

**Sample run 1**

```
Name to search: Hamza Ali
Phone: 0333-5550101
```

**Sample run 2**

```
Name to search: Hamza Khan
Not found
```

`contacts.txt` is the file written by P15.1.

## P15.5: Copying in capitals

Copy a text file to a new file, converting every letter to a capital letter.

**Solution:** [P15_5.cpp](P15_5.cpp)

**Sample run**

```
Source file: notice.txt
New file: notice_upper.txt
140 characters copied to notice_upper.txt
```

**notice_upper.txt** (after the run)

```
MID-TERM EXAMINATIONS WILL START ON MONDAY.
STUDENTS MUST BRING THEIR COLLEGE CARDS.
MOBILE PHONES ARE NOT ALLOWED IN THE EXAMINATION HALL.
```

## P15.6: Merging sorted files

Two files each contain integers in ascending order. Merge them into a third file that is also in ascending order.

**Solution:** [P15_6.cpp](P15_6.cpp)

**numbers1.txt** (input file)

```
3 8 15 22 40
```

**numbers2.txt** (input file)

```
1 9 10 30 41 50 60
```

**Output**

```
12 numbers written to merged.txt
```

**merged.txt** (after the run)

```
1 3 8 9 10 15 22 30 40 41 50 60 
```

`readNext` returns `true` when a number was read, so `hasA` tells whether `a` holds a number that has not been written yet. This is the same idea as merging two sorted arrays in P10.10.

## P15.7: Students in each program

Read `students.csv` (roll number, name, program) and display how many students are in each program.

**Solution:** [P15_7.cpp](P15_7.cpp)

**students.csv** (input file)

```
101,Ayesha Khan,BSCS
102,Bilal Ahmed,BSIT
103,Fatima Noor,BSCS
104,Hamza Ali,BSSE
105,Sana Tariq,BSIT
106,Usman Raza,BSCS
107,Zainab Iqbal,BSAI
108,Ali Raza,BSSE
```

**Output**

```
Program   Students
BSCS      3
BSIT      2
BSSE      2
BSAI      1
```

The program names are not fixed in the code. Each new program found in the file is added to the `programName` array.

## P15.8: Random access to employee records

Define a structure `Employee` (id, name as a `char` array, salary). Write the records of 5 employees to `employees.dat`. Then input a record number and display only that record, using `seekg`.

**Solution:** [P15_8.cpp](P15_8.cpp)

**Sample run**

```
5 records written to employees.dat
Record number (1 to 5): 4
ID: 4
Name: Nadia Akram
Salary: Rs. 76000.00
```

The name is a `char` array, not a `string`, so that every record has the same fixed size and can be written to a binary file as it is.

## P15.9: Changing a price in place

Open `products.dat` of Program 15.7 with `fstream` in `ios::in | ios::out | ios::binary` mode. Input a record number and a new price, read the record, change its price and write it back in the same place using `seekp`.

**Solution:** [P15_9.cpp](P15_9.cpp)

**Sample run**

```
Record number (1 to 4): 3
New price: 695
Old: 103  Tea 250g  Rs. 650.00

All records now:
101  Soap        Rs. 120.00
102  Rice 1kg    Rs. 380.00
103  Tea 250g    Rs. 695.00
104  Sugar 1kg   Rs. 160.00
```

Run Program 15.7 first to create `products.dat`. Only the third record changes; the others stay where they were.

## P15.10: Macros with brackets

Define macros `CUBE(x)`, `MIN(a, b)` and `IS_EVEN(n)`, with correct brackets, and test each with expressions such as `CUBE(1 + 2)`.

**Solution:** [P15_10.cpp](P15_10.cpp)

**Output**

```
CUBE(3)          = 27
CUBE(1 + 2)      = 27
100 / CUBE(2)    = 12
MIN(17, 42)      = 17
MIN(10 - 8, 1)   = 1
2 * MIN(3, 5)    = 6
IS_EVEN(14)      = 1
IS_EVEN(7 + 2)   = 0
```

Without the brackets around each `x`, `CUBE(1 + 2)` would become `1 + 2 * 1 + 2 * 1 + 2` = 7 instead of 27. Without the outer brackets, `100 / CUBE(2)` would also go wrong. `IS_EVEN` gives 1 for true and 0 for false.

## P15.11: DEBUG switch

Write a bubble sort program in which a `DEBUG` macro, when defined, makes the program print the array after every pass.

**Solution:** [P15_11.cpp](P15_11.cpp)

**Output**

```
After pass 1: 10 14 29 13 5 37 
After pass 2: 10 14 13 5 29 37 
After pass 3: 10 13 5 14 29 37 
After pass 4: 10 5 13 14 29 37 
After pass 5: 5 10 13 14 29 37 
Sorted: 5 10 13 14 29 37 
```

Delete (or comment out) the `#define DEBUG` line and compile again: only the last line, `Sorted: ...`, is printed.

## P15.12: assert

Write a function `double percentage(int obtained, int total)` that uses `assert` to check that `total` is greater than 0 and that `obtained` is between 0 and `total`.

**Solution:** [P15_12.cpp](P15_12.cpp)

**Sample run 1**

```
Obtained marks and total marks: 842 1100
Percentage = 76.5455%
```

**Sample run 2**

```
Obtained marks and total marks: 1200 1100
Assertion failed: obtained >= 0 && obtained <= total, file P15_12.cpp, line 21
```

In the second run the assertion fails and the program stops at once. The message above is the Windows (Dev-C++) form; Dev-C++ may show the full path of the file instead of just its name. The result is stored in `p` before anything is printed, so "Percentage =" does not appear when the assertion fails.
