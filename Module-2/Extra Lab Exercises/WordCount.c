#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, words = 0, maxLen = 0, currLen = 0, start = 0, maxStart = 0;

    printf("Enter a sentence:\n");
    fgets(str, sizeof(str), stdin);

    // Word counting
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n') {
            currLen++;
        } else {
            if(currLen > 0) {
                words++;
                if(currLen > maxLen) {
                    maxLen = currLen;
                    maxStart = start;
                }
                currLen = 0;
            }
            start = i + 1;
        }
    }

    // To handle last word if no trailing space
    if(currLen > 0) {
        words++;
        if(currLen > maxLen) {
            maxLen = currLen;
            maxStart = start;
        }
    }

    printf("\nTotal words = %d\n", words);

    // Print longest word
    printf("Longest word = ");
    for(i = maxStart; i < maxStart + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
