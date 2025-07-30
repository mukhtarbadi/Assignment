#include <stdio.h>

int main() {
    int a, b, c;
    int largestFlag = 0, smallestFlag = 0;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        largestFlag = 1;
    else if (b >= a && b >= c)
        largestFlag = 2;
    else
        largestFlag = 3;

    if (a <= b && a <= c)
        smallestFlag = 1;
    else if (b <= a && b <= c)
        smallestFlag = 2;
    else
        smallestFlag = 3;

    printf("\n");

    switch (largestFlag) {
        case 1:
            printf("Largest number is: %d (a)\n", a);
            break;
        case 2:
            printf("Largest number is: %d (b)\n", b);
            break;
        case 3:
            printf("Largest number is: %d (c)\n", c);
            break;
    }

    switch (smallestFlag) {
        case 1:
            printf("Smallest number is: %d (a)\n", a);
            break;
        case 2:
            printf("Smallest number is: %d (b)\n", b);
            break;
        case 3:
            printf("Smallest number is: %d (c)\n", c);
            break;
    }

    return 0;
}
