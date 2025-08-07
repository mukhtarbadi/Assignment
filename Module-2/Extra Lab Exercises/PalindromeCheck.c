#include <stdio.h>
#include <string.h>

int isPalindromeStr(char str[]) {
    int i, len = strlen(str);

    for(i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindromeStr(str))
        printf("\n%s is a palindrome.", str);
    else
        printf("\n%s is not a palindrome.", str);

    return 0;
}
