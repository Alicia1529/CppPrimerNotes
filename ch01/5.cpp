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


