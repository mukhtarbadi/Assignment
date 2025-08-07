#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    int vowels = 0, consonants = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while(str[i] != '\0') {
        char ch = str[i];

        // Convert uppercase to lowercase for simplicity
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else if(ch >= 'a' && ch <= 'z')
            consonants++;
        else if(ch >= '0' && ch <= '9')
            digits++;
        else
            special++;

        i++;
    }

    printf("\nVowels = %d", vowels);
    printf("\nConsonants = %d", consonants);
    printf("\nDigits = %d", digits);
    printf("\nSpecial characters = %d\n", special);

    return 0;
}
