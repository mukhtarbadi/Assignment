#include <stdio.h>

int main() {
    int n, i, sum = 0;
    float avg;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    avg = (float)sum / n;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    return 0;
}
