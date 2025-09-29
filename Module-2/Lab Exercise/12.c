#include <stdio.h>

// This is a program that writes user input to a file until '0' is entered,
// then reads and displays the content from the file

int main() {
    FILE *file;
    char c;

    file = fopen("tops.txt", "w");
    if (file == NULL) {
        printf("Unable to create file.");
        return 1;
    }

    printf("Enter your text (press 0 to stop):\n");
    while ((c = getchar()) != '0') {
        fputc(c, file);
    }
    fclose(file);

    printf("\nReading data from file:\n");
    file = fopen("tops.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);

    return 0;
}
