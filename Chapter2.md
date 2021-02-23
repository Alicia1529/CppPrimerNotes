### 2.1.1. Arithmetic Types
1 byte = 8 bits
**16位编译器**
char ：1个字节
char*(即指针变量): 2个字节
short int : 2个字节
int：  2个字节
unsigned int : 2个字节
float:  4个字节
double:   8个字节
long:   4个字节
long long:  8个字节
unsigned long:  4个字节

**32位编译器**
char ：1个字节
char*（即指针变量）: 4个字节（32位的寻址空间是2^32, 即32个bit，也就是4个字节。同理64位编译器）
short int : 2个字节
int：  4个字节
unsigned int : 4个字节
float:  4个字节
double:   8个字节
long:   4个字节
long long:  8个字节
unsigned long:  4个字节

**64位编译器**
char ：1个字节
char*(即指针变量): 8个字节
short int : 2个字节
int：  4个字节
unsigned int : 4个字节
float:  4个字节
double:   8个字节
long:   8个字节
long long:  8个字节
unsigned long:  8个字节 

### 2.2.1. Variable Definitions
#### Default Initialization

When we define a variable without an initializer, the variable is default initialized.

The value of an object of built-in type that is not explicitly initialized depends on where it is defined. Variables defined outside any function body are initialized to zero. With one exception, which we cover in § 6.1.1 (p. 205), variables of built-in type defined inside a function are uninitialized.

```c++
#include <iostream>

std::string global_str;
int global_int;
int main() {
    int local_int;
    std::string local_str;
    printf("global_int %d, local_int %d\n", global_int, local_int);
    std::cout << "gobal_str: " << global_str << std::endl;
    std::cout << "local_str: " << local_str << std::endl;
}
// global_int 0, local_int 1
// gobal_str: 
// local_str: 
```
#### List Initialization
```c++
// For example, we can use any of the following four different ways to define an int variable named units_sold and initialize it to 0:
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

### 2.2.2. Variable Declarations and Definitions

To support separate compilation, C++ distinguishes between declarations and definitions. A declaration makes a name known to the program. A file that wants to use a name defined elsewhere includes a declaration for that name. A definition creates the associated entity. A variable declaration specifies the type and name of a variable. A variable definition is a declaration. In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value.


**References to Pointers**
```c++
#include <iostream>
int main() {
    int i = 42;
    int *p;        // p is a pointer to int
    int *&r = p;   // r is a reference to the pointer p
    r = &i; //  r refers to a pointer; assigning &i to r makes p point to i
    printf("r %p, r %d, p %p, p %d\n", r, *r, p, *p);
    // r 0x7ffee4f026ec, r 42, p 0x7ffee4f026ec, p 42


    *r = 0; //  dereferencing r yields i, the object to which p points; changes i to 0
    printf("r %p, r %d, p %p, p %d, i %d\n", r, *r, p, *p, i);
    // r 0x7ffee4f026ec, r 0, p 0x7ffee4f026ec, p 0, i 0
}
```

### 2.3.1. References
When we define a reference, instead of copying the initializer’s value, we bind the reference to its initializer. Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer to a different
object. Because there is no way to rebind a reference, references must be initialized.

A reference is not an object. Instead, a reference is just another name for an already existing object.

```c++
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2;

refVal = 2; // assigns 2 to the object to which refVal refers, i.e., to ival
int ii = refVal; // same as ii = ival
```


### 2.3.2. Pointers
### 2.3.3. Understanding Compound Type Declarations
It can be easier to understand complicated pointer or reference declarations if you read them from right to left.
```c++
// References to Pointers
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to r makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0
```


### 2.5.1. Type Aliases
```c++
// Traditionally, we use a typedef:
typedef double wages; // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*

// The new standard introduced a second way to define a type alias, via an alias declaration:
using SI = Sales_item; // SI is a synonym for Sales_item

// A type alias is a type name and can appear wherever a type name can appear:
wages hourly, weekly; // same as double hourly, weekly;
SI item; // same as Sales_item item
```

### 2.6.1. Defining Our Own Data Structures (the Sales_data Type)
```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
The close curly that ends the class body must be followed by a semicolon. The semicolon is needed because we can define variables after the class body:
```c++
struct Sales_data { /* ... */ } accum, trans, *salesptr;
// equivalent, but better way to define these objects
struct Sales_data { /* ... */ };
Sales_data accum, trans, *salesptr;
```

### 2.6.3. Writing Our Own Header Files
```C++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
```
The first time Sales_data.h is included, the `#ifndef` test will succeed. The preprocessor will process the lines following `#ifndef` up to the #endif. As a result, the preprocessor variable SALES_DATA_H will be defined and the contents of `Sales_data.h` will be copied into our program. If we include Sales_data.h later on in the same file, the `#ifndef` directive will be false. The lines between it and the `#endif` directive will be ignored.

