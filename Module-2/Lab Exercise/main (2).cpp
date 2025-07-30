#include <stdio.h>

#define PI 3.1416

int main() {
    int age = 22;
    float marks = 92.50;
    char grade = 'A';

    printf("Student Details:\n");
    printf("Age     : %d years\n", age);
    printf("Marks   : %.2f\n", marks);
    printf("Grade   : %c\n", grade);
    printf("PI Value: %.4f\n", PI);

    return 0;
}
