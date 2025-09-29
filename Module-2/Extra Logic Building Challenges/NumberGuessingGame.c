#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int s, g, att = 0, maxA = 10;

    srand(time(0));
    s = (rand() % 100) + 1;

    printf("Welcome to Number Guessing Game!\n");
    printf("Guess number between 1 and 100. You have %d tries.\n", maxA);

    while (att < maxA) {
        printf("Try %d: Enter guess: ", att + 1);
        scanf("%d", &g);
        att++;

        if (g == s) {
            printf("🎉 Correct! You guessed in %d tries.\n", att);
            break;
        } else if (g < s) {
            printf("Too low! Try higher.\n");
        } else {
            printf("Too high! Try lower.\n");
        }
    }

    if (g != s) {
        printf("❌ Out of tries! Number was %d.\n", s);
    }

    return 0;
}
