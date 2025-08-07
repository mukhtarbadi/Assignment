#include <stdio.h>


int pascal(int row, int col) {
    if(col == 0 || col == row)
        return 1;
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

int main() {
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);


    printf("Pascal's Triangle using loops:\n");
    int triangle[20][20] = {0};
    for(i = 0; i < n; i++) {
        triangle[i][0] = 1;
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }


    printf("\nPascal's Triangle using recursion:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            printf("%d ", pascal(i, j));
        }
        printf("\n");
    }

    return 0;
}
