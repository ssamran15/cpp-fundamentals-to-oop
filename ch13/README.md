# Chapter 13: Pointers

Solutions to the Practice Programs of Chapter 13. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P13_1.cpp -o P13_1` (or press F11 in Dev-C++).

## P13.1: Sum and product through pointers

Write a function `void sumAndProduct(int a, int b, int *sum, int *product)` that sends back both the sum and the product of two numbers through pointer parameters. Call it from `main` with numbers entered by the user.

**Solution:** [P13_1.cpp](P13_1.cpp)

**Sample run**

```
Enter two numbers: 12 7
Sum = 19
Product = 84
```

## P13.2: Arranging three numbers

Write a function that receives three integers by pointer and rearranges them so that the first holds the smallest and the third the largest.

**Solution:** [P13_2.cpp](P13_2.cpp)

**Sample run**

```
Enter three numbers: 42 7 19
Smallest to largest: 7 19 42
```

## P13.3: Smallest and largest

Write a function `void minMax(const int *arr, int size, int *mn, int *mx)` that finds the smallest and largest elements of an array using pointer notation. Input 6 numbers in `main` and display the results.

**Solution:** [P13_3.cpp](P13_3.cpp)

**Sample run**

```
Enter 6 numbers: 35 -4 61 18 0 27
Smallest = -4
Largest = 61
```

## P13.4: Even numbers with a moving pointer

Input 10 numbers into an array and display only the even ones, using a pointer that moves through the array. Do not use an index anywhere.

**Solution:** [P13_4.cpp](P13_4.cpp)

**Sample run**

```
Enter 10 numbers: 12 7 30 45 8 19 22 3 64 11
Even numbers: 12 30 8 22 64 
```

`end` points one place past the last element. The loop runs while `p` is before it, so no index is needed.

## P13.5: Reversing with two pointers

Input 8 numbers into an array and reverse the array in place using two pointers, one starting at each end, that move towards each other.

**Solution:** [P13_5.cpp](P13_5.cpp)

**Sample run**

```
Enter 8 numbers: 1 2 3 4 5 6 7 8
Reversed: 8 7 6 5 4 3 2 1 
```

## P13.6: Counting characters

Input a line of text into a C-string and count its vowels, consonants, digits and spaces, using only a `char` pointer to move through it.

**Solution:** [P13_6.cpp](P13_6.cpp)

**Sample run**

```
Enter a line of text: Room 205 is on the 2nd floor
Vowels: 7
Consonants: 11
Digits: 4
Spaces: 6
```

## P13.7: Capitals in place

Write a function `void toUpper(char *s)` that converts a C-string to capital letters in place, using a pointer.

**Solution:** [P13_7.cpp](P13_7.cpp)

**Sample run**

```
Enter some text: Govt. Graduate College, Okara
In capitals: GOVT. GRADUATE COLLEGE, OKARA
```

## P13.8: Palindrome with two pointers

Input a word and check whether it is a palindrome (such as "madam" or "level") using two `char` pointers.

**Solution:** [P13_8.cpp](P13_8.cpp)

**Sample run 1**

```
Enter a word: madam
madam is a palindrome
```

**Sample run 2**

```
Enter a word: madman
madman is not a palindrome
```

## P13.9: Bubble sort in pointer notation

Sort an array of 10 integers with bubble sort, writing every element access in pointer notation, `*(a + j)`, instead of `a[j]`.

**Solution:** [P13_9.cpp](P13_9.cpp)

**Sample run**

```
Enter 10 numbers: 34 7 89 12 56 3 71 45 20 66
Sorted: 3 7 12 20 34 45 56 66 71 89 
```

## P13.10: Month names

Store the names of the twelve months in an array of `const char *`. Input a month number and display its name, with an error message for a number outside 1 to 12.

**Solution:** [P13_10.cpp](P13_10.cpp)

**Sample run 1**

```
Enter a month number: 8
Month 8 is August
```

**Sample run 2**

```
Enter a month number: 13
Error: the month number must be from 1 to 12
```

## P13.11: Account through a pointer

Define a structure `Account` with the account title and balance. Write functions `deposit` and `withdraw` that receive a pointer to an `Account`. A withdrawal larger than the balance must be refused.

**Solution:** [P13_11.cpp](P13_11.cpp)

**Output**

```
Account: Hamza Ali, balance Rs. 25000
After depositing 7500: Rs. 32500
Withdrawal of 40000 refused: not enough balance
Withdrew 12000, balance now Rs. 20500
```

Inside the functions the members are reached with the arrow operator, `acc->balance`. `withdraw` returns `false` when it refuses, so `main` can report it.

## P13.12: Applying a function to all elements

Write a function `void applyToAll(int *arr, int size, int (*f)(int))` that replaces every element with `f` of that element. Test it with functions that square, double and negate a number.

**Solution:** [P13_12.cpp](P13_12.cpp)

**Output**

```
Start:          1 2 3 4 5 
After square:   1 4 9 16 25 
After double:   2 8 18 32 50 
After negative: -2 -8 -18 -32 -50 
```

The doubling function is named `twice`, because `double` is a keyword. The negating function is named `negative`, because the standard library already has something called `negate`, and with `using namespace std;` the name would be ambiguous.

## P13.13: Sorting with a comparison function

Write a bubble sort function that receives, along with the array and its size, a pointer to a function `bool inOrder(int, int)`. Use it to sort the same array in ascending and then in descending order by passing two different functions.

**Solution:** [P13_13.cpp](P13_13.cpp)

**Output**

```
Ascending:  3 7 12 34 45 56 71 89 
Descending: 89 71 56 45 34 12 7 3 
```

The sort itself never changes. Only the function passed in decides which order counts as correct.
