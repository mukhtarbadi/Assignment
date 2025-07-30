#include <stdio.h>

int main() {
    double num1, num2;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);  // Space to handle newline

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("\n");

    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0)
                printf("Error: Division by zero is not allowed.\n");
            else
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            break;
        case '%':
            if ((int)num2 == 0)
                printf("Error: Modulus by zero is not allowed.\n");
            else
                printf("%d %% %d = %d\n", (int)num1, (int)num2, (int)num1 % (int)num2);
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    return 0;
}
