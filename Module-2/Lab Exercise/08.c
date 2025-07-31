#include <stdio.h>

// This is a program to take input in 1D and 2D arrays and print + sum values

int main() {
    int i, j;

    // 1D Array Input
    int numbers[5];
    printf("Enter 5 numbers (1D array):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }

    // Print 1D array
    printf("\nYou entered:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    // 2D Array Input (3x3 Matrix)
    int matrix[3][3];
    int total = 0;

    printf("\n\nEnter 9 numbers for 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
            total = total + matrix[i][j];
        }
    }

    // Print 2D matrix
    printf("\nMatrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of all elements in matrix: %d", total);

    return 0;
}
