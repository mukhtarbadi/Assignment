//Write a C program to demonstrate pointer usage. Use a pointer to modify the value of a variable and print the result.

#include <stdio.h>

int main() {
    int no = 10;
    int *ptr;

    ptr = &no;

    printf("Original value: %d\n", no);

    *ptr = 25;

    printf("Modified value: %d\n", no);

    return 0;
}
