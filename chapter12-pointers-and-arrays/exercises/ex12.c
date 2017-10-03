// #define N 10
//
// float ident[N][N];
// int row, col;
//
// for (row = 0; row < N; row++) {
//   for (col = 0; col < N; col++) {
//     if (row == col) {
//       ident[row][col] = 1.0;
//     } else {
//       ident[row][col] = 0.0;
//     }
//   }
// }

#define N 10

double ident[N][N];
double *e;
int zeroes = N;

int main(void) {
  for (e = &ident[0][0]; e <= &ident[N-1][N-1]; e++) {
    if (zeroes == N) {
      zeroes = 0;
      *e = 1.0;
    } else {
      zeroes++;
      *e = 0.0;
    }
  }
  return 0;
}
