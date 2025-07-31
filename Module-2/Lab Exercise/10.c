#include <stdio.h>
#include <string.h>

// This is a program to join two strings and find the length

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    gets(str1);  
    printf("Enter second string: ");
    gets(str2);

    strcat(str1, str2); 

    printf("\nConcatenated string: %s", str1);
    printf("\nLength of string: %lu", strlen(str1));

    return 0;
}
