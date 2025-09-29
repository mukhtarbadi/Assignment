#include <stdio.h>

// This is a program to perform arithmetic, relational, and logical operations

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Arithmetic operations
    printf("\nAdding: %d", num1 + num2);
    printf("\nSubtracting: %d", num1 - num2);
    printf("\nMultiplying: %d", num1 * num2);
    printf("\nDividing: %d", num2 != 0 ? num1 / num2 : 0);
    printf("\nModulus: %d", num2 != 0 ? num1 % num2 : 0);
    printf("\n");
    // Relational operations
    printf("\nIs Equal? %d", num1 == num2);
    printf("\nIs Not Equal? %d", num1 != num2);
    printf("\nIs Greater? %d", num1 > num2);
    printf("\nIs Smaller? %d", num1 < num2);
    printf("\n");
    // Logical operations
    printf("\nAND Logic: %d", num1 && num2);
    printf("\nOR Logic: %d", num1 || num2);
    printf("\nNOT num1: %d", !num1);
    printf("\nNOT num2: %d", !num2);

    return 0;
}
