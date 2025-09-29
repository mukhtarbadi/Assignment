#include <stdio.h>

// This is a program to calculate factorial using a function

int factorial(int number); 

int factorial(int number) {
    int i, result = 1;
    for (i = 1; i <= number; i++) {
        result = result * i;
    }
    return result;
}

int main() {
    int number, answer;

    printf("Enter a number: ");
    scanf("%d", &number);

    answer = factorial(number); 

    printf("\nFactorial of %d is: %d", number, answer);

    return 0;
}



