### int

```c++
INT_MAX
INT_MIN
```



### char

```c++
<cctype> (ctype.h)
isalnum
isalpha
isblank
iscntrl
isdigit
isgraph
islower
isprint
ispunct
isspace
isupper
isxdigit
tolower
toupper
  
/* tolower example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="Test String.\n";
  char c;
  while (str[i])
  {
    c=str[i];
    putchar (tolower(c));
    i++;
  }
  return 0;
}
```



### Vector

```
sort(vector.begin(), vector.end());
std::reverse(A.begin() + i + 1, A.end());
swap(A[i], A[j]);

intervals.insert(intervals.begin() + idx, newInterval);
intervals.erase(intervals.begin() + idx + 1);
vector<vector<int>> ans(n, vector<int> (n));
```


### Array
```c++
int dp[n][n];
// memset()可以初始化整数数组，但是初始化的值只能为0或者-1。
memset(dp, -1, sizeof(dp));
```

### Queue
```c++
#include<queue>
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素   M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()
```

### Deque
> If you need a stack or a queue, then use the correct container. They are designed to prevent certain operations that would be allowable on a deque, such as adding or removing an element in the middle, or even iterating through the container. Such operations are totally unacceptable in a strict stack or queue implementation.

> You might think it's fine to use a deque because you know that you intended to use it as a normal queue. But when somebody else comes along a few years later and your project has grown significantly, it might not be at all obvious to that person. Doing a non-queue operation just because they can to hack around some other issue, your program may inadvertently be broken in subtle ways that could go undetected for weeks, months or years.
```c++
deque<TreeNode*>q;
q.push_back(root);
TreeNode* curr = q.front();
q.pop_front();
```
### Stack
```c++
stack<char> memo;
char memo.top();
void memo.pop();
void memo.push();
bool memo.empty();
```

### String
```c++
string s;
s.at(0);s

s.substr(idx, length);

path.append("/");
```


### Vector
```c++
vector<int> v;
v.push_back(0);
//
vector<int> m(256, 0);
bool m.empty();  // whether is empty
int m.back();  // get the last digit
m.pop_back();

std::find(v.begin(), v.end(), key) != v.end()
```

### Map
```c++
unordered_map<int, int> map;
map.find(key) == map.end() ?;

unordered_map<char, char> mappings= {
    {'(', ')'}, {'{', '}'}, {'[', ']'} 
};


map<vector<int>, vector<string>> mappings;

for(auto x:mappings) {
    res.push_back(x.second);
}


#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> m;
    for (int i = 0; i < 10; i++){
        m[i] = i*i;
    }
    map<int,int>::iterator iter;
    iter = m.begin();
    while(iter != m.end()){
        cout << iter->first << "-" << iter->second << endl;
        iter++;
    }
    for (iter = m.begin();iter != m.end(); iter++){
        cout << iter->first << "-" << iter->second << endl;
    }
    for(auto &it : m){
        cout << it.first << "-" << it.second <<endl;
    }
    return 0;
}

```


### Set
```c++
set<char> window;
window.find(s.at(right)) == window.end();
window.insert(s.at(right));
window.erase(.at(right));
```


### Pointer
```c++
ListNode* head = new ListNode();
```


### 数值类型转换为string
```c++
std命令空间下有一个C++标准库函数std::to_string()，可用于将数值类型转换为string。使用时需要include头文件<string>。
函数原型申明如下：
string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);
```



```c++
// char to int
(int)(v[i]-'0')
// int to char
(char)(v[i]+'0');
// char to string
string s;
s += 'c';


```

### printf
```
%a                              浮点数、十六进制数字和p-计数法(C99)
%A                              浮点数、十六进制数字和p-计数法(C99)
%c                              输出单个字符
%d                              以十进制形式输出带符号整数(正数不输出符号)
%e                              以指数形式输出单、双精度实数
%E                              以指数形式输出单、双精度实数
%f                               以小数形式输出单、双精度实数
%g                              以%f%e中较短的输出宽度输出单.双精度实数,%e格式在指数小于-4或者大于等于精度时使用
%G 　　　　　　　　　　  以%f%e中较短的输出宽度输出单.双精度实数,%e格式在指数小于-4或者大于等于精度时使用
%i                               有符号十进制整数(与%d相同)
%o 　　　　　　　　　　　以八进制形式输出无符号整数(不输出前缀O)
%p                               指针
%s 　　　　　　　　　　　输出字符串
%x 　　　　　　　　　　　以十六进制形式输出无符号整数(不输出前缀OX)
%X　　　　　　　　　　　 以十六进制形式输出无符号整数(不输出前缀OX)
%u 　　　　　　　　　　　以十进制形式输出无符号整数
```