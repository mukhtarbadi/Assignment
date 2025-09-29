#include <stdio.h>

int factorial_iter(int n) {
    int fact = 1, i;
    for(i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int factorial_rec(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial_rec(n - 1);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial (iterative) = %d\n", factorial_iter(num));
    printf("Factorial (recursive) = %d\n", factorial_rec(num));

    return 0;
}
