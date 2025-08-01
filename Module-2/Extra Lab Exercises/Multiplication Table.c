#include <stdio.h>

int main() {
    int num, start, end, i;

    printf("Enter the number for multiplication table: ");
    scanf("%d", &num);

    printf("Enter the starting range: ");
    scanf("%d", &start);

    printf("Enter the ending range: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid range! Starting value should be less than or equal to ending value.\n");
        return 1;
    }

    printf("Multiplication table of %d from %d to %d:\n", num, start, end);
    for (i = start; i <= end; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
