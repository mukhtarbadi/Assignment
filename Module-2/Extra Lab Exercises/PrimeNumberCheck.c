#include <stdio.h>

int main() {
    int n, i, j, p;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nPrime numbers between 1 and %d are:\n", n);

    for(i = 2; i <= n; i++) {
        p = 1;
        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                p = 0;
                break;
            }
        }
        if(p)
            printf("%d ", i);
    }

    return 0;
}
