# Homework 1-6 Answers

### 1. Given the C++ declaration:
```C++
struct {
  int n;
  char c;
} A[10][10];
```
### On your machine, find the address of A[0][0] and A[3][7]. Explain why these values are what you found them to be.

>For the array's first value at A[0][0], the memory address is randomly allocated. Consider the values to be A[x][y]. The natural allocation of memory looks like this:
[0][0]
[0][1]
.
.
[0][9]
[1][0]
(The pointer for [0][10] points to the same memory address as the pointer for [1][0]. However, [0][10] is not within the size of the array.)
When y is incremented by 1, 8 in hexadecimal is added to the memory address to allocate memory for a char's size, which is 8 bits. When x is incremented by 1, the memory is still allocated for the 10 y's that belong to the previous x value. For that reason, the memory address when x is incremented by 1 increases by 50 in hexadecimal (8 * a in hex is 50. a(hex) = 10(dec)).


---
### 2. Explain the meaning of the following C++ declarations:
```C++
double *a[n];
double (*b)[n];
double (*c[n])();
double (*d())[n];
```
>Answer Here

---
### 3. Consider the following declaration in C++:
```C++
double (*f(double (*)(double, double[]), double)) (double, ...);
```
### Describe rigorously, in English, the type of f.

>ANSWER Here

---
### 4. What happens when we “redefine” a field in a C++ subclass? For example, suppose we have:
```C++
class Base {
public:
  int a;
  std::string b;
};

class Derived: public Base {
public:
  float c;
  int b;
};
```
### Does the representation of a Derived object contain one b field or two? If two, are both accessible, or only one? Under what circumstances? Tell the story of how things are.

>ANSWER Here

---
### 5. What does the following C++ program output?
```C++
#include <iostream>
int x = 2;
void f() { std::cout << x << '\n'; }
void g() { int x = 5; f(); std::cout << x << '\n'; }
int main() {
  g();
  std::cout << x << '\n';
}
```
### Verify that the answer you obtained is the same that would be inferred from apply the rules of static scoping. If C++ used dynamic scoping, what would the output have been?

>ANSWER Here

---
### 6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for (a) a raw array, and (b) a std::array.
a.
```C++

```
b.
```C++

```
