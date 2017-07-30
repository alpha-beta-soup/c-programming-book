void avg_sum(float a[], int n, float *avg, float *sum) {
  int i;

  *sum = a[0];
  for (i = 1; i < n; i++) {
    *sum += a[i];
  }
  *avg = *sum / n;
}
