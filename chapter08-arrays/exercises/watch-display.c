// Prints numbers like a digital watch

// NOTE: doesn't work yet

#include <stdio.h>

#define LEN (int) (sizeof(a) / sizeof(a[0]))
#define SPACE (char) ' '
#define PIPE (char) '|'
#define FLAT (char) '_'
#define FACES 12

int main() {
  long n;
  int digit, face_n, facet, i;
  const int segments[10][7] = {
    {1,1,1,1,1,1},
    {0,1,1},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
  };

  printf("Enter an integer: ");
  scanf("%ld", &n);

  while (n > 0) {
    char face[FACES] = {};
    face_n = 1;
    digit = n % 10;
    // convert digit into watch display
    for (facet = 0; facet <= 6; facet++) {
      switch(facet) {
        case 0: case 3: case 6:
          face[face_n] = SPACE;
          face_n++;
          switch(segments[digit][facet]) {
            case 0:
              face[face_n] = SPACE;
              face_n++;
              break;
            case 1:
              face[face_n] = FLAT;
              face_n++;
              break;
          }
          face[face_n] = SPACE;
          face_n++;
        case 1: case 2: case 4: case 5:
          switch(segments[digit][facet]) {
            case 0:
              face[face_n] = SPACE;
              face_n++;
              break;
            case 1:
              face[face_n] = PIPE;
              face_n++;
              break;
          }
          break;
        // case 3: case 6:
        //   switch (segments[digit][facet]) {
        //     case 0:
        //       face[face_n] = SPACE;
        //       face_n++;
        //       break;
        //     case 1:
        //       face[face_n] = FLAT;
        //       face_n++;
        //       break;
        //   }
        //   break;
      }
    }
    for (i = 1; i <= FACES; i++) {
      printf("%i%c", i, face[i]);
      if (!(i % 3)) {
        printf("\n");
      }
    }
    printf("\n");
    n /= 10;
  }
  return 0;
}
