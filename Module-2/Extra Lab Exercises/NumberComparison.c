#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a >= b && a >= c)
        printf("\nLargest = %d", a);
    else if(b >= a && b >= c)
        printf("\nLargest = %d", b);
    else
        printf("\nLargest = %d", c);

    if(a <= b && a <= c)
        printf("\nSmallest = %d", a);
    else if(b <= a && b <= c)
        printf("\nSmallest = %d", b);
    else
        printf("\nSmallest = %d", c);

    return 0;
}
