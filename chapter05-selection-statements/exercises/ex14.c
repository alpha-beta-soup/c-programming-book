#include <stdio.h>

int main(void)
{

    int grade, modgrade;

    printf("Enter numerical grade (0-100): ");
    scanf("%d", &grade);

    modgrade = grade / 10;
    switch (modgrade) {
      case 9: case 10:
        printf("A\n"); break;
      case 8:
        printf("B\n"); break;
      case 7:
        printf("C\n"); break;
      case 6:
        printf("D\n"); break;
      default:
        printf("F\n"); break;
    }

    return 0;

}
