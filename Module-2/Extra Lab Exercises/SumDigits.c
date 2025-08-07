#include <stdio.h>

int main() {
    int num, sum = 0, temp, rev = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while(temp != 0) {
        int digit = temp % 10;
        sum = sum + digit;
        rev = rev * 10 + digit;
        temp = temp / 10;
    }

    printf("\nSum of digits = %d", sum);
    printf("\nReversed number = %d", rev);

    return 0;
}
