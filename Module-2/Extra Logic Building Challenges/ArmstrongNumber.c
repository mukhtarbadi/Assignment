#include <stdio.h>

int isArmstrong(int n) {
    int temp = n, sum = 0, d;
    while(temp > 0) {
        d = temp % 10;
        sum += d * d * d;
        temp /= 10;
    }
    return (sum == n);
}

int main() {
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    printf("Armstrong numbers between 1 and 1000:\n");
    for(i = 1; i <= 1000; i++) {
        if(isArmstrong(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
