#include <stdio.h>

// This is a program to check even/odd and display month name

int main() {
    int num, month;

    // Even or Odd Check
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("\nThe number is Even");
    } else {
        printf("\nThe number is Odd");
    }

    // Month name using switch
    printf("\n\nEnter month number (1-12): ");
    scanf("%d", &month);

    switch (month) {
        case 1:
            printf("\nMonth: January");
            break;
        case 2:
            printf("\nMonth: February");
            break;
        case 3:
            printf("\nMonth: March");
            break;
        case 4:
            printf("\nMonth: April");
            break;
        case 5:
            printf("\nMonth: May");
            break;
        case 6:
            printf("\nMonth: June");
            break;
        case 7:
            printf("\nMonth: July");
            break;
        case 8:
            printf("\nMonth: August");
            break;
        case 9:
            printf("\nMonth: September");
            break;
        case 10:
            printf("\nMonth: October");
            break;
        case 11:
            printf("\nMonth: November");
            break;
        case 12:
            printf("\nMonth: December");
            break;
        default:
            printf("\nInvalid month number");
    }

    return 0;
}
