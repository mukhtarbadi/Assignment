#include <stdio.h>

// This is a program to use break and continue statements with a loop

int main() {
    int i;

    // Using break to stop at 5
    printf("Using break (stop at 5):\n");
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            break;
        }
        printf("%d ", i);
    }

    // Using continue to skip 3
    printf("\n\nUsing continue (skip 3):\n");
    for (i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}
