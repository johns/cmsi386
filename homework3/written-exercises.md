# Homework 1-7 Answers

### 1. Given the C++ declaration:
```C++
struct {
  int n;
  char c;
} A[10][10];
```
###On your machine, find the address of A[0][0] and A[3][7]. Explain why these values are what you found them to be.

>ANSWER HERE

### 2. Explain the meaning of the following C++ declarations:
```C++
double *a[n];
double (*b)[n];
double (*c[n])();
double (*d())[n];
```
>Answer Here

### 3. Consider the following declaration in C++:
```C++
double (*f(double (*)(double, double[]), double)) (double, ...);
```
### Describe rigorously, in English, the type of f.

>ANSWER Here

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

### 6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for (a) a raw array, and (b) a std::array.
a.
```C++

```
b.
```C++

```
