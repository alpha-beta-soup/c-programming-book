#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 9)
        printf("1 digit\n");
    else if (num >= 10 && num <= 99)
        printf("2 digits\n");
    else if (num >= 100 && num <= 999)
        printf("3 digits\n");
    else if (num >= 1000 && num <= 9999)
        printf("4 digits\n");
    else if (num >= 10000 && num <= 32767)
        printf("5 digits\n");
    else
        printf("Integer overflow on 16 bit int\n");

    return 0;
}
