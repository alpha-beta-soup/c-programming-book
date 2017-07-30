// Rewrute of square2 that pauses after 24 squares and then uses getchar to
// wait for enter in order to continue

#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar(); //remove the newline char from the buffer

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);

        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;
        }
    }

    return 0;
}
