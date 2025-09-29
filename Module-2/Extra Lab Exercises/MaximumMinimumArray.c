#include <stdio.h>

int main() {
    int a[10], i, j, t, max, min;

    printf("Enter 10 numbers:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for(i = 1; i < 10; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    for(i = 0; i < 9; i++) {
        for(j = i+1; j < 10; j++) {
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);

    printf("\nSorted array:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
