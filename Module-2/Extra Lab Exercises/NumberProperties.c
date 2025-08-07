#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num % 2 == 0)
        printf("\nThe number is even.");
    else
        printf("\nThe number is odd.");

    if(num > 0)
        printf("\nThe number is positive.");
    else if(num < 0)
        printf("\nThe number is negative.");
    else
        printf("\nThe number is zero.");

    if(num % 3 == 0 && num % 5 == 0)
        printf("\nThe number is a multiple of both 3 and 5.");
    else
        printf("\nThe number is not a multiple of both 3 and 5.");

    return 0;
}
