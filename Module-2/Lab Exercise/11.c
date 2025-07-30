//Write a C program that defines a structure to store a student's details (name, 
//roll number, and marks). Use an array of structures to store details of 3 
//students and print them.

#include <stdio.h>

struct information {
    int roll_no;
    char name[50];
    int marks;
};

int main() {
    struct information i1[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\nEnter Roll Number: ");
        scanf("%d", &i1[i].roll_no);

        printf("Enter Name: ");
        scanf("%s", i1[i].name);

        printf("Enter Marks: ");
        scanf("%d", &i1[i].marks);
    }

    printf("\n----------- Student Details -----------\n");
    for (i = 0; i < 3; i++) {
        printf("\nRoll Number: %d", i1[i].roll_no);
        printf("\nName       : %s", i1[i].name);
        printf("\nMarks      : %d\n", i1[i].marks);
    }

    return 0;
}
