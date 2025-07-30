#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindromeString(char str[]) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);

        if (leftChar != rightChar) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindromeString(str))
        printf("\"%s\" is a palindrome string.\n", str);
    else
        printf("\"%s\" is NOT a palindrome string.\n", str);

    return 0;
}
