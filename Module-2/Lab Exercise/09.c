#include <stdio.h>

// This is a program to change value using a pointer

int main() {
    int number = 10;
    int *ptr;

    ptr = &number;      
    *ptr = 20;         

    printf("Updated value of number: %d", number);

    return 0;
}
