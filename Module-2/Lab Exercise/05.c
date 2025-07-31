#include <stdio.h>

// This is a program to print numbers from 1 to 10 using while, for, and do-while loops

int main() {
    int i;

    // Using while loop
    i = 1;
    printf("While Loop:\n");
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }

    // Using for loop
    printf("\n\nFor Loop:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    // Using do-while loop
    i = 1;
    printf("\n\nDo-While Loop:\n");
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);

    return 0;
}
