# Chapter 31: Templates

Solutions to the Practice Programs of Chapter 31. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P31_1.cpp -o P31_1` (or press F11 in Dev-C++).

## P31.1: sortArray

Write a function template `sortArray()` that sorts an array of any type into ascending order using bubble sort, and a template `printArray()`. Use them with arrays of `int`, `double` and `string`.

**Solution:** [P31_1.cpp](P31_1.cpp)

**Output**

```
45  58  64  72  85  91  
120  160.75  590  650.5  1850  
Faisalabad  Lahore  Multan  Okara  Sahiwal  
```

`sortArray` uses only `<` and assignment, so it works for any type that has them (Section 31.2.2).

## P31.2: countOf and reverseArray

Write function templates `countOf()`, which counts how many times a value appears in an array, and `reverseArray()`, which reverses an array in place. Test them with `int`, `char` and `string` arrays.

**Solution:** [P31_2.cpp](P31_2.cpp)

**Output**

```
4 appears 3 times
'A' appears 3 times
"Sat" appears 0 times
3 7 4 1 9 4 7 4 
F A C A B A 
Fri Thu Wed Tue Mon 
```

`string("Sat")` is needed in the call: `"Sat"` alone is a C-string, so the compiler could not decide whether `T` is `string` or `const char *`.

## P31.3: minMax with a specialisation

Write a function template `minMax()` that receives an array and returns its smallest and largest values through two reference parameters. Write a specialisation for arrays of C-strings that compares them with `strcmp()`.

**Solution:** [P31_3.cpp](P31_3.cpp)

**Output**

```
Marks: smallest 45, largest 91
Names: first Ali, last Zainab
Cities: first Lahore, last Sahiwal
```

For `const char *`, the general version would compare the addresses of the strings, not their text. The specialisation (`template <>`) replaces it for that one type.

## P31.4: Templates with a Money class

Write a class `Money` with `operator>`, `operator+=` and `operator<<`. Show that `maximum()` from Program 31.1 and `total()` from Program 31.3 work with `Money` objects without any change.

**Solution:** [P31_4.cpp](P31_4.cpp)

**Output**

```
maximum(fee, fine) = Rs. 24000.00
total(bills, 4) = Rs. 4161.00
```

`maximum` needs `>`, and `total` needs `+=` and `T()`, a default constructor (the constructor's default arguments provide it). `Money` supplies all three, so both templates work as they are.

## P31.5: Queue at a bank counter

Write a class template `Queue<T, SIZE>` using a circular array, with `enqueue()`, `dequeue()` and `size()`. Use a `Queue<string, 3>` to model customers at a bank counter.

**Solution:** [P31_5.cpp](P31_5.cpp)

**Output**

```
Ali joins the queue (1 waiting)
Sana joins the queue (2 waiting)
Bilal joins the queue (3 waiting)
Fatima must wait outside: the queue is full
Served: Ali
Fatima joins the queue (3 waiting)
Hamza must wait outside: the queue is full
Served: Sana
Served: Bilal
Served: Fatima
Queue empty, 0 waiting
```

In a circular array the positions wrap round with `% SIZE`, so a place freed at the front can be used again at the back.

## P31.6: Matrix template

Write a class template `Matrix<T, ROWS, COLS>` with functions to read, print and add two matrices. Use it with `int` and `double` matrices.

**Solution:** [P31_6.cpp](P31_6.cpp)

**Sample run**

```
Two 2 x 3 int matrices:
1 2 3
4 5 6
10 20 30
40 50 60
Sum:
      11      22      33
      44      55      66
Two 2 x 2 double matrices:
1.5 2.25
3 0.5
0.5 0.75
1 2.5
Sum:
       2       3
       4       3
```

The size is part of the type: `Matrix<int, 2, 3>` and `Matrix<int, 3, 2>` are different types, so adding matrices of different sizes is caught by the compiler.

## P31.7: Stats template

Write a class template `Stats<T>` that holds up to 100 values and has functions `add()`, `mean()`, `smallest()` and `largest()`. Use it for marks (`int`) and temperatures (`double`).

**Solution:** [P31_7.cpp](P31_7.cpp)

**Output**

```
Marks: mean 74.5, smallest 58, largest 91
Temperatures: mean 32.5, lowest 29.5, highest 36.5
```

`mean()` returns a `double` for both types, so the average of `int` marks is not cut off to a whole number.

## P31.8: Two jobs for one Stack

Use the `Stack` template of Program 31.7 to convert a decimal number to binary, and to print the words of a sentence in reverse order.

**Solution:** [P31_8.cpp](P31_8.cpp)

**Sample run**

```
Enter a number: 45
45 in binary is 101101
Enter a sentence: Okara is a city in Punjab
Reversed: Punjab in city a is Okara
```

The `Stack` class template is copied from Program 31.7. A `Stack<int>` and a `Stack<string>` come from the same code.
