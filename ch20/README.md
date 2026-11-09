# Chapter 20: Objects and Memory: this, Copy Constructor, Deep vs Shallow Copy

Solutions to the Practice Programs of Chapter 20. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

Every program here was also checked with Valgrind: no memory leaks and no invalid memory use.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P20_1.cpp -o P20_1` (or press F11 in Dev-C++).

## P20.1: Adding distances

Write a class `Distance` (feet and inches) and a non-member function `Distance addDistances(const Distance &a, const Distance &b)` that returns their sum as a new object.

**Solution:** [P20_1.cpp](P20_1.cpp)

**Output**

```
5' 9" + 3' 7" = 9' 4"
```

`addDistances` is not a member, so it cannot touch `feet` and `inches` directly; it uses the getters. Because `a` and `b` are `const` references, the getters must be `const` member functions, as `get()` is in Program 20.2 (Chapter 21 explains `const` members in full).

## P20.2: Cascaded calculator

Write a class `Calculator` whose functions `set`, `add`, `subtract`, `multiply` and `divide` return `*this`, so that a calculation can be written as `c.set(10).add(5).multiply(3).subtract(2).show();`.

**Solution:** [P20_2.cpp](P20_2.cpp)

**Output**

```
Result = 43
Result = 13
(division by zero ignored) Result = 14
```

Each function returns `Calculator &`, a reference to the same object, so the next call in the chain works on that object and not on a copy.

## P20.3: Topper with this->

Write a class `Student` (name, CGPA) whose setter uses `this->` for parameters with the same names as the members, and a member function `bool isBetterThan(const Student &other)`. Find the topper among 5 students.

**Solution:** [P20_3.cpp](P20_3.cpp)

**Output**

```
Topper: Fatima Noor (CGPA 3.88)
```

`isBetterThan` can read `other.cgpa` directly, because it is a member function of the same class.

## P20.4: IntArray with a deep copy

Write a class `IntArray` that allocates an array of a given size in its constructor and fills it with 1, 2, 3, ..., with a deep-copy copy constructor, a destructor, and functions `set` and `show`. Show that changing a copy does not change the original.

**Solution:** [P20_4.cpp](P20_4.cpp)

**Output**

```
Original: 1 2 3 4 5 
Copy:     100 2 3 4 500 
```

## P20.5: Person passed by value

Write a class `Person` with a name stored as a dynamic C-string (`char *`) and an age. Give it a constructor, copy constructor and destructor. Pass a `Person` by value to a function that prints it, and show that the program ends safely.

**Solution:** [P20_5.cpp](P20_5.cpp)

**Output**

```
  [copy constructor: copied Muhammad Usman]
Inside printPerson:
  Muhammad Usman, 21 years
Back in main, the original is unharmed:
  Muhammad Usman, 21 years
Program ends safely
```

Without the copy constructor, `p` would share `a`'s memory and free it at the end of `printPerson`, and the later `a.show()` and `a`'s destructor would then use freed memory.

## P20.6: MyString

Write your own class `MyString` with a `char *` member, a constructor from a C-string, a copy constructor, a destructor, and member functions `length()`, `show()` and `toUpper()`.

**Solution:** [P20_6.cpp](P20_6.cpp)

**Output**

```
city: Okara
copy: OKARA
Length: 5
```

`toUpper()` changed only the copy, which shows that the copy has its own memory.

## P20.7: Matrix transpose

Write a class `Matrix` with a dynamic 2D array, a copy constructor and destructor, and a member function that returns the transpose as a new `Matrix` object.

**Solution:** [P20_7.cpp](P20_7.cpp)

**Sample run**

```
Enter a 2 x 3 matrix:
1 2 3
4 5 6
Matrix:
    1    2    3
    4    5    6
Transpose:
    1    4
    2    5
    3    6
Copy of the matrix:
    1    2    3
    4    5    6
```

`allocate()` is a private helper used by both constructors. As Section 20.8 advises, the program never assigns one `Matrix` to another; the assignment operator comes in Chapter 23.

## P20.8: Tracer array explained

Using the `Tracer` class of Program 20.8, write a program that creates an array of 3 `Tracer` objects, passes one element by value and one by reference to functions, and explain every line of the output.

**Solution:** [P20_8.cpp](P20_8.cpp)

**Output**

```
1. Create the array
  constructor 1
  constructor 2
  constructor 3
2. byValue(list[0])
  copy constructor 101 (copied from 1)
  inside byValue, id = 101
  destructor 101
3. byReference(list[1])
  inside byReference, id = 2
4. End of main
  destructor 3
  destructor 2
  destructor 1
```

Line by line:

- **Step 1:** each element is built straight from `Tracer(1)`, `Tracer(2)` and `Tracer(3)`. Since C++17 no copy is made here, so only three constructors run.
- **Step 2:** `list[0]` is copied into the parameter `t`, so the copy constructor runs and makes id 101. `byValue` prints 101, and `t` is destroyed when the function ends ("destructor 101"). The original `list[0]` still has id 1.
- **Step 3:** `t` is just another name for `list[1]`, so no constructor or destructor runs and the id printed is 2.
- **Step 4:** at the end of `main` the array is destroyed. Array elements are destroyed in the reverse order of construction: 3, then 2, then 1.
