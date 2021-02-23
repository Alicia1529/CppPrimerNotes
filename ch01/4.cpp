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

