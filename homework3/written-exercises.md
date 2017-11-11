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
.  
.  
[9][8]  
[9][9]  
(The pointer for [0][10] points to the same memory address as the pointer for [1][0]. However, [0][10] is not within the size of the array.)  
When y is incremented by 1, 8 in hexadecimal is added to the memory address to allocate memory for a char's size, which is 8 bits. When x is incremented by 1, the memory is still allocated for the 10 y's that belong to the previous x value. For that reason, the memory address when x is incremented by 1 increases by 50 in hexadecimal (8 * a in hex is 50. a(hex) = 10(dec)).

---
### 2. Explain the meaning of the following C++ declarations:
```C++
double *a[n];       //a
double (*b)[n];     //b
double (*c[n])();   //c
double (*d())[n];   //d
```
>a. The asterisk (*) symbol denotes pointers in C++. Therefore, this is declaring an array of n pointers which point to doubles.  
b. The (*b) value is a pointer to an array of doubles. [n] is the amount of doubles in the array.  
c. Inside the initial parenthesis, there is an array of pointers. These pointers point to functions that all return doubles.  
d. The first thing that should be read is a function d(), which returns a pointer. This pointer points to an array of n doubles.

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

> The program outputs  
2  
5  
2  
In C++, functions first check for variables on the closest scope and then look outwards because the language is statically scoped. In f(), there is no locally declared integers named x. Therefore, when x is called, the function looks to the next outward scope and finds the globally declared x. The main method looks globally as well because x is not declared within main. In g(), integer x is declared locally, and therefore, when x is called, it refers to the local integer x.  
If C++ was dynamically scoped, the output would be  
5  
5  
2  
Since f() is called within g(), it would look for variables first locally and then within g(). This is because in a dynamically scoped language, the function looks to the scope in which the function was called so long as variables aren't declared locally.

---
### 6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for (a) a raw array, and (b) a std::array.
a.
```C++

```
b.
```C++

```
