//Write a C program that writes user input to a file until '0' is entered, then reads and displays the content from the file.

#include <stdio.h>

int main() {
    FILE *f1;
    char ch;

    f1 = fopen("tops.txt", "w");
    printf("Enter your data (enter 0 to stop): ");
    while ((ch = getchar()) != '0') {
        putc(ch, f1);
    }
    fclose(f1);

    printf("\nRead data from file:\n");
    f1 = fopen("tops.txt", "r");
    while ((ch = getc(f1)) != EOF) {
        printf("%c", ch);
    }
    fclose(f1);

    return 0;
}
