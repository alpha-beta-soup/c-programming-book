#include <stdio.h>

int main()
{
    int language, publisher, book, checksum;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d", &language, &publisher, &book, &checksum);
    printf("Language: %d\n", language);
    printf("Publisher: %d\n", publisher);
    printf("Book number: %d\n", book);
    printf("Check digit: %d\n", checksum);
    return 0;
}
