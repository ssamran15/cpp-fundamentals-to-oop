# Chapter 32: The Standard Library vector

Solutions to the Practice Programs of Chapter 32. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P32_1.cpp -o P32_1` (or press F11 in Dev-C++).

## P32.1: Even, odd and no negatives

Read numbers until 0 is entered into a `vector<int>`. Print how many are even and how many odd, then remove all negative numbers and print the vector again.

**Solution:** [P32_1.cpp](P32_1.cpp)

**Sample run**

```
Enter numbers (0 to stop): 12 -7 30 45 -8 19 22 -3 64 0
Even: 5, odd: 4
Without the negative numbers: 12 30 45 19 22 64 
```

After `erase`, the next element slides into position `i`, so `i` is increased only when nothing was erased; otherwise two negatives in a row would be missed.

## P32.2: Different names in order

Read names until the word `end` into a `vector<string>`. Sort them, remove the repeated names, and print the different names in order.

**Solution:** [P32_2.cpp](P32_2.cpp)

**Sample run**

```
Enter names (end to stop): Sana Ali Hamza Ali Zainab Sana Ali Bilal end
5 different names:
  Ali
  Bilal
  Hamza
  Sana
  Zainab
```

After sorting, equal names are next to each other, so a name is copied only if it differs from the last name copied.

## P32.3: Fee challans with a vector

Rewrite Program 27.8 (fee challans) so that the students are kept in a `vector<Student *>` with no maximum, and are deleted at the end.

**Solution:** [P32_3.cpp](P32_3.cpp)

**Sample run**

```
Types: 1 Regular, 2 Self-finance, 3 Scholarship (name 0 0 to stop)
Student 1 (name roll type): Ayesha 101 1
Student 2 (name roll type): Bilal 102 2
Student 3 (name roll type): Fatima 103 3
  Waiver percentage: 50
Student 4 (name roll type): Hamza 104 1
Student 5 (name roll type): x 0 0

Fee challans
101  Ayesha (Regular): Rs. 24000
102  Bilal (Self-finance): Rs. 42000
103  Fatima (Scholarship 50%): Rs. 12000
104  Hamza (Regular): Rs. 24000
Total fee to be collected: Rs. 102000
```

The classes are those of Program 27.8, unchanged. Instead of asking for the number of students first, the program reads until a type of 0 is entered, since the vector can grow without limit.

## P32.4: Shopping cart

Write a menu-driven shopping cart using a `vector<Product>`, with choices to add an item, remove an item by name, list the cart with its total, and empty the cart.

**Solution:** [P32_4.cpp](P32_4.cpp)

**Sample run**

```

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 1
Item, quantity and price: Rice 2 1850

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 1
Item, quantity and price: Tea 1 650

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 1
Item, quantity and price: Soap 6 120

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 3
  Rice         2 x  1850.00 =   3700.00
  Tea          1 x   650.00 =    650.00
  Soap         6 x   120.00 =    720.00
  3 item(s), total Rs. 5070.00

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 2
Item to remove: Tea
  Removed

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 3
  Rice         2 x  1850.00 =   3700.00
  Soap         6 x   120.00 =    720.00
  2 item(s), total Rs. 4420.00

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 4
  The cart is empty

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 3
  0 item(s), total Rs. 0.00

1 Add  2 Remove  3 List  4 Empty cart  0 Exit: 0
```

## P32.5: Matrix product

Read the sizes of two matrices and their elements into `vector<vector<int>>` objects, check that they can be multiplied, and print their product.

**Solution:** [P32_5.cpp](P32_5.cpp)

**Sample run 1**

```
Rows and columns of A: 2 3
Rows and columns of B: 3 2
Matrix A:
1 2 3
4 5 6
Matrix B:
7 8
9 10
11 12
A x B:
    58    64
   139   154
```

**Sample run 2**

```
Rows and columns of A: 2 3
Rows and columns of B: 2 2
Cannot multiply: A has 3 columns but B has 2 rows
```

`vector<vector<int>> m(rows, vector<int>(cols))` makes `rows` rows, each a vector of `cols` zeros (Section 32.8).

## P32.6: Stack on a vector

Rewrite the `Stack` class template of Program 31.7 so that it stores its items in a `vector<T>` and has no maximum size.

**Solution:** [P32_6.cpp](P32_6.cpp)

**Output**

```
Pushed 100 numbers
The top five: 1000 990 980 970 960
95 numbers left
Going back through pages:
  Fee Structure
  Admissions
  Home
```

`push` no longer needs to return `bool`, because the vector grows as needed, so the stack is never full. 100 numbers are pushed to show that the old limit of 50 is gone.

## P32.7: Words sorted by length

Read all the words of a text file into a `vector<string>`. Print the number of words, the longest word, and the words sorted by length using a comparison function.

**Solution:** [P32_7.cpp](P32_7.cpp)

**Sample run**

```
File name: notice.txt
Number of words: 21
Longest word: examinations
Sorted by length:
  in
  on
  are
  not
  the
  must
  will
  bring
  hall.
  start
  their
  Mobile
  cards.
  phones
  Monday.
  allowed
  college
  Mid-term
  Students
  examination
  examinations
```

Words of the same length are put in alphabetical order, so the result is always the same. `>>` keeps punctuation with a word, so `Monday.` counts as 7 characters. Capital letters come before small ones in the alphabetical order (`Mobile` before `cards.`).

## P32.8: Totals and positions

A file holds one line per student: a name followed by marks in any number of subjects. Read it into a `vector<string>` of names and a `vector<vector<int>>` of marks, then print each student's total and position in the class.

**Solution:** [P32_8.cpp](P32_8.cpp)

**marks2.txt** (input file)

```
Ayesha 78 85 91 88
Bilal 66 72 58
Fatima 88 94 90 79 85
Hamza 55 61 70 64
Sana 82 79 88 91
Usman 90 85 77
```

**Output**

```
Name        Subjects   Total  Position
Ayesha             4     342         2
Bilal              3     196         6
Fatima             5     436         1
Hamza              4     250         5
Sana               4     340         3
Usman              3     252         4
```

Each row of `marks` has its own length. A student's position is 1 plus the number of students with a higher total, so equal totals would share a position.
