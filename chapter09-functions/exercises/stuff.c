// Maximum value in an array
// Average of all elements in an array
// Number of positive elements in an array
// Does array contain zero
// Median of a triplet
// Factorial
// GCD (recursive)

#include <stdio.h>

#define N 12
#define TRUE 1
#define FALSE 0

typedef int Bool;

int max(int a[], int len);
int sum(int a[], int len);
double avg(int a[], int len);
int num_above_threshold(int a[], int len, int threshold);
int num_pos(int a[], int len);
Bool has_zero(int a[], int len);
float median(float x, float y, float z);
int fact(int n);
int gcd(int m, int n);

int main() {
  int a[N] = {1,-2,55,4,5,6,7,8,9,10,0,0};

  printf("maximum value of array: %d\n", max(a, N));
  printf("average of array: %g\n", avg(a, N));
  printf("number of positive values in array: %d\n", num_pos(a, N));
  printf("does the array have zero in it: %d\n", has_zero(a, N));
  printf("median of a triplet: %g\n", median(25.6, 2.6, 12.2));
  printf("10!: %d\n", fact(10));
  printf("GCD of 12 and 6: %d\n", gcd(12, 6));
  return 0;
}

int max(int a[], int n) {
  int i, max;
  max = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

int sum(int a[], int n) {
  int i, sum = 0;
  for (i = 0; i < N; i++) {
    sum += a[i];
  }
  return sum;
}

double avg(int a[], int n) {
  return sum(a, n) / (double) n;
}

int num_above_threshold(int a[], int n, int t) {
  int i, count = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > t) {
      count++;
    }
  }
  return count;
}

int num_pos(int a[], int n) {
  return num_above_threshold(a, n, 0);
}

Bool has_zero(int a[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (a[i] == 0) {
      return TRUE;
    }
  }
  return FALSE;
}

// Original
// float median(float x, float y, float z) {
//   if (x <= y) {
//     if (y <= z) return y;
//     else if (x <= z) return z;
//     else return x;
//   }
//   if (z <= y) return y;
//   if (x <= z) return x;
//   return z;
// }

float median(float x, float y, float z) {
  return ((x-y)*(y-z) > -1 ? y : ((x-y)*(x-z) < 1 ? x : z));
}

// Original
// int fact(int n) {
//   if (n <= 1) {
//     return 1;
//   } else {
//     return n * fact(n - 1);
//   }
// }

// Ternary & recursive
// int fact(int n) {
//   return n <= 1 ? 1 : n * fact(n - 1);
// }

// Non-recursive
int fact(int n) {
  int i, f = 1;
  for (i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

int gcd(int m, int n) {
  return n == 0 ? m : gcd(n, m % n);
}
