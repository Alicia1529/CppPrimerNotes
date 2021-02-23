## 3.1. Namespace using Declarations

A `using` declaration lets us use a name from a namespace without qualifying the name with a `namespace_name::` prefix. A `using` declaration has the form

```c++
#include <iostream>
// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
int main()
{
    int i;
    cin >> i; // ok: cin is a synonym for std::cin
    cout << i; // error: no using declaration; we must use the full name
    std::cout << i; // ok: explicitly use cout from namepsace std
    return 0;
}
```

- A Separate `using` Declaration Is Required for Each Name
- Headers Should Not Include `using` Declarations



## 3.2. Library string Type

### 3.2.1. Defining and Initializing `string`s

```c++
#include <string>
string s1; // default initialization; s1 is the empty string
string s2(s1); // s2 is a copy of s1
string s2 = s1; // same as above
string s3("hiya"); // s3 is a copy of the string literal
string s3 = "hiya"; // s3 is a copy of the string literal
string s4(10, 'c'); // s4 is cccccccccc
```



```c++
string s5 = "hiya"; // copy initialization
string s6("hiya"); // direct initialization
string s7(10, 'c'); // direct initialization; s7 is cccccccccc
```



### 3.2.2. Operations on `string`s

```c++
os << s									// Write s onto output stream os. Returns os.
is >> s								  // Reads whitespace-separated string from is into s. Returns is.
getline(is, s)					// Reads a line of input from is into s. Returns is.
s.empty()
s.size()
s[n]
s1 + s2
s1 = s2
s1 == s2								// The strings s1 and s2 are equal if they contain the same characters.
s1 != s2
<, <=, >, >=						// Comparisions are case-sensitive and use dictionary ordering
```

- Reading an Unknown Number of strings

  ```c++
  int main()
  {
      string word;
      while (cin >> word) // read until end-of-file
      cout << word << endl; // write each word followed by a new line
      return 0;
  }
  ```

- Using `getline` to Read an Entire Line

  ```c++
  int main()
  {
      string line;
      // read input a line at a time until end-of-file
      while (getline(cin, line))
        cout << line << endl;
      return 0;
  }
  ```

- The `string::size_type` Type

  It might be logical to expect that size returns an int or, thinking back to § 2.1.1 (p.34), an unsigned. Instead, size returns a `string::size_type` value. This type requires a bit of explanation.

  ```c++
  auto len = line.size(); // len has type string::size_type
  ```

  Because size returns an unsigned type, it is essential to remember that expressions that mix signed and unsigned data can have surprising results (§ 2.1.2, p.36). For example, if `n` is an `int` that holds a negative value, then `s.size() < n` will almost surely evaluate as true. It yields

- Adding Literals and strings

  ```c++
  string s4 = s1 + ", "; // ok: adding a string and a literal
  string s5 = "hello" + ", "; // error: no string operand
  string s6 = s1 + ", " + "world"; // ok: each + has a string operand
  string s7 = "hello" + ", " + s2; // error: can't add string literals
  ```



### 3.2.3. Dealing with the Characters in a string

```c++
Character classification functions

// They check whether the character passed as parameter belongs to a certain category:
isalnum   // Check if character is alphanumeric (function )
isalpha   // Check if character is alphabetic (function )
isblank   // Check if character is blank (function )
iscntrl   // Check if character is a control character (function )
isdigit   // Check if character is decimal digit (function )
isgraph   // Check if character has graphical representation (function )
islower   // Check if character is lowercase letter (function )
isupper   // Check if character is uppercase letter (function )
isprint   // Check if character is printable (function )
ispunct   // Check if character is a punctuation character (function )
isspace   // Check if character is a white-space (function )
isxdigit  // Check if character is hexadecimal digit (function )

// Character conversion functions
tolower  // Convert uppercase letter to lowercase (function )
toupper  // Convert lowercase letter to uppercase (function )
```

- Processing Every Character? Use Range-Based `for`

  ```c++
  string s("Hello World!!!");
  // punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
  decltype(s.size()) punct_cnt = 0;
  // count the number of punctuation characters in s
  for (auto c : s) // for every char in s
    if (ispunct(c)) // if the character is punctuation
      ++punct_cnt; // increment the punctuation counter
  cout << punct_cnt
       << " punctuation characters in " << s << endl;
  ```

  

- Using a Range `for` to Change the Characters in a string

  ```C++
  string s("Hello World!!!");
  // convert s to uppercase
  for (auto &c : s) // for every char in s (note: c is a reference)
    c = toupper(c); // c is a reference, so the assignment changes the char in s
  cout << s << endl; // HELLO WORLD!!!
  ```

  

## 3.3. Library vector Type

```c++
#include <vector>
using std::vector;

vector<int> ivec; // ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file; // vector whose elements are vectors
```

### 3.3.1. Defining and Initializing `vector`s

```c++
vector<T> v1                      `vector` that holds objects of type T.
  																 Default initializations; v1 is empty.
vector<T> v2(v1)									 v2 has a copy of each element in v1.
vector<T> v2 = v1									 same as above.
vector<T> v3(n, val)							 v3 has n elements with value val
vector<T> v4(n)							 			 v4 has n copies of a value-initialized object
vector<T> v5{a, b, c...}					 v5 has as many elements as there are initializers;
																	 elements are initialized by corresponding initializers.
vector<T> v5 = {a, b, c...}        Equivalent to above
```

- List Initializing a vector

  ```c++
  vector<string> articles = {"a", "an", "the"};
  vector<string> v1{"a", "an", "the"}; // list initialization
  vector<string> v2("a", "an", "the"); // error
  ```

- Creating a Specified Number of Elements

  ```c++
  vector<int> ivec(10, -1); // ten int elements, each initialized to -1
  vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
  ```



### 3.3.2. `vector` Operations

```c++
v.empty();
v.size();
v.push_back(t);
v[n];
v1 = v2;
v1 = {a, b, c, d...};
v1 == v2;
v1 != v2;
<, <=, >, >=;
```

```c++
vector<int> v{1,2,3,4,5,6,7,8,9};
for (auto &i : v) // for each element in v (note: i is a reference)
  i *= i; // square the element value
for (auto i : v) // for each element in v
  cout << i << " "; // print the element
cout << endl;
```



## 3.4. Introducing Iterators

### 3.4.1. Using Iterators

```c++
auto start = iter.begin();
*iter;
iter->men;
++iter;
--iter;
iter1 == iter2;
iter1 != iter2;

string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin(); // it denotes the first character in s
    *it = toupper(*it); // make that character uppercase
}
// Some string

// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	*it = toupper(*it); // capitalize the current character
```

- **Iterator Types**

  ```c++
  vector<int>::iterator it; // it can read and write vector<int> elements
  string::iterator it2; // it2 can read and write characters in a string vector<int>::const_iterator it3; // it3 can read but not write elements string::const_iterator it4; // it4 can read but not write characters
  ```

  

### 3.5. Arrays

#### **3.5.1. Defining and Initializing Built-in Arrays**

```c++
unsigned cnt = 42; // not a constant expression
constexpr unsigned sz = 42; // constant expression
// constexpr see § 2.4.4 (p. 66)
int arr[10]; // array of ten ints
int *parr[sz]; // array of 42 pointers to int
string bad[cnt]; // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise


/* Explicitly Initializing Array Elements */
const unsigned sz = 3;
int ia1[sz] = {0,1,2}; // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2}; // an array of dimension 3
int a3[5] = {0, 1, 2}; // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}
int a5[2] = {0,1,2}; // error: too many initializers

/* Character Arrays Are Special
Character arrays have an additional form of initialization: We can initialize such arrays from a string literal (§ 2.1.3, p. 39). When we use this form of initialization, it is important to remember that string literals end with a null character. That null character is copied into the array along with the characters in the literal:
*/
char a1[] = {'C', '+', '+'}; // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null char a3[] = "C++"; // null terminator added automatically
const char a4[6] = "Daniel"; // error: no space for the null!

/* No Copy or Assignment */
int a[] = {0, 1, 2}; // array of three ints
int a2[] = a; // error: cannot initialize one array with another
a2 = a; // error: cannot assign one array to another


/* Understanding Complicated Array Declarations */
int *ptrs[10]; // ptrs is an array of ten pointers to int
int &refs[10] = /* ? */; // error: no arrays of references
int (*Parray)[10] = &arr; // Parray points to an array of ten ints
int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints
```

**As with variables of built-in type, a default-initialized array of built-in type that is defined inside a function will have undefined values.**

#### **3.5.2. Accessing the Elements of an Array**

When we use a variable to subscript an array, we normally should define that variable to have type **size_t**. size_t is a machine-specific unsigned type that is guaranteed to be large enough to hold the size of any object in memory. The size_t type is defined in the cstddef header, which is the C++ version of the `stddef.h` header from the C library.

#### **3.5.3. Pointers and Arrays**

```c++
string nums[] = {"one", "two", "three"}; // array of strings string
*p = &nums[0]; // p points to the first element in nums
string *p2 = nums; // equivalent to p2 = &nums[0]
```

- Pointers Are Iterators

  ```c++
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  int *p = arr; // p points to the first element in arr ++p; // p points to arr[1]
  int *e = &arr[10]; // pointer just past the last element in arr
  ```

  

- **The Library** **`begin`** **and** **`end`** **Functions**

  ```c++
  /* The Library begin and end Functions */
  int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
  int *beg = begin(ia); // pointer to the first element in ia
  int *last = end(ia); // pointer one past the last element in ia
  
  // pbeg points to the first and pend points just past the last element in arr 
  int *pbeg = begin(arr), *pend = end(arr);
  // find the first negative element, stopping if we've seen all the elements
  while (pbeg != pend && *pbeg >= 0)
      ++pbeg;
  ```

  `begin` returns a pointer to the first, and `end` returns a pointer one past the last element in the given array: These functions are defined in the iterator header.

  Using `begin` and `end`, it is easy to write a loop to process the elements in an array.

- **Pointer Arithmetic**

  ```C++
  constexpr size_t sz = 5;
  int arr[sz] = {1,2,3,4,5};
  int *ip = arr; // equivalent to int *ip = &arr[0]
  int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr
  
  // ok: arr is converted to a pointer to its first element; p points one past the end of arr
  int *p = arr + sz; // use caution -- do not dereference!
  int *p2 = arr + 10; // error: arr has only 5 elements; p2 has undefined value
  
  auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr (type is ptrdiff_t)
  ```

  

#### **3.5.4. C-Style Character Strings**

Strings that follow this convention are stored in character arrays and are **null terminated**. By null- terminated we mean that the last character in the string is followed by a null character (`'\0'`). Ordinarily we use pointers to manipulate these strings.

```c++
strlen(p)  // returns the length of p, not counting the null
strcmp(p1, p2) // compares p1 and p2 for equality. returns 0 if p1 == p2, as positive value if p1 > p2, a negative balue if p1 < p2
strcat(p1, p2)  // appends p2 to p1, returns p1
strcpy(p1, p2)  // copies p2 into p1, returns p2
  
/* The pointer(s) passed to these routines must point to null-terminated array(s):*/
char ca[] = {'C', '+', '+'}; // not null terminated
cout << strlen(ca) << endl; // disaster: ca isn't null terminated
```



### **3.5.5. Interfacing to Older Code**

```c++
string s("Hello World"); // s holds Hello World

char *str = s; // error: can't initialize a char* from a string const char *str = s.c_str(); // ok

/* Using an Array to Initialize a vector */
int int_arr[] = {0, 1, 2, 3, 4, 5};
// ivec has six elements; each is a copy of the corresponding element in int_arr
vector<int> ivec(begin(int_arr), end(int_arr));
// copies three elements: int_arr[1], int_arr[2], int_arr[3]
vector<int> subVec(int_arr + 1, int_arr + 4);
```



### **3.6. Multidimensional Arrays**

```c++
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
// array of size 10; each element is a 20-element array whose elements are arrays of 30 ints
int arr[10][20][30] = {0}; // initialize all elements to 0


/**
 * Initializing the Elements of a Multidimensional Array
**/
int ia[3][4] = { // three elements; each element is an array of size 4
  {0, 1, 2, 3},  // initializers for the row indexed by 0
  {4, 5, 6, 7},  // initializers for the row indexed by 1
	{8, 9, 10, 11} // initializers for the row indexed by 2
};
// The nested braces are optional. The following initialization is equivalent, although considerably less clear:
// equivalent initialization without the optional nested braces for each row
int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
// explicitly initialize only element 0 in each row
int ia[3][4] = {{ 0 }, { 4 }, { 8 }};
// explicitly initialize row 0; the remaining elements are value initialized
int ix[3][4] = {0, 3, 6, 9};

constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt]; // 12 uninitialized elements
// for each row
for (size_t i = 0; i != rowCnt; ++i) {
    // for each column within the row
    for (size_t j = 0; j != colCnt; ++j) {
        // assign the element's positional index as its value
        ia[i][j] = i * colCnt + j;
    }
}



/* Using a Range for with Multidimensional Arrays */
size_t cnt = 0;
for (auto &row : ia) // for every element in the outer array
    for (auto &col : row) { // for every element in the inner array
      	col = cnt; // give this element the next value
        ++cnt; // increment cnt
		}


/* Pointers and Multidimensional Arrays */
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
int (*p)[4] = ia; // p points to an array of four ints
p = &ia[2]; // p now points to the last element in ia

int *ip[4]; // array of pointers to int
int (*ip)[4]; // pointer to an array of four ints
```





​				 		