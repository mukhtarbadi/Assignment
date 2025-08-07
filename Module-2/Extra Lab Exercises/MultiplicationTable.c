#include <stdio.h>

int main() {
    int num, i, range;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter range: ");
    scanf("%d", &range);

    for(i = 1; i <= range; i++) {
        printf("\n%d x %d = %d", num, i, num * i);
    }

    return 0;
}
