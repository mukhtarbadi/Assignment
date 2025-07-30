#include <stdio.h>

int main() 
{
    int a, b;

    printf("Enter the first integer: ");
    scanf("%d", &a);

    printf("Enter the second integer: ");
    scanf("%d", &b);

    printf("\n--- Arithmetic Operations ---\n");
    printf("Addition (a + b)       = %d\n", a + b);
    printf("Subtraction (a - b)    = %d\n", a - b);
    printf("Multiplication (a * b) = %d\n", a * b);
    if(b != 0) {
        printf("Division (a / b)       = %d\n", a / b);
        printf("Modulus (a %% b)        = %d\n", a % b);
    } else {
        printf("Division and modulus by zero are not allowed.\n");
    }

    printf("\n--- Relational Operations ---\n");
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n", a <= b);

    printf("\n--- Logical Operations ---\n");
    printf("(a && b) : %d\n", a && b);
    printf("(a || b) : %d\n", a || b);
    printf("!(a)     : %d\n", !a);

    return 0;
}
