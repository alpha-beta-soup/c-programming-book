# Chapter 8: Arrays

Scalar vs aggregate variables:
- scalar: hold a single datum
- aggregate: collections of datums

C has two types of aggregates:
1. arrays
2. structures (records) — See Chapter 16

### One-dimensional arrays

- All data values must have the same type (any type).
- The length of the array must be declared (any integer constant expression), unless it is initialised with values (e.g. `int a[] = {1, 2, 3}` is valid).
  - So it's good practice to use a macro to define the length:

  ```
  #define N 10
  int a[N]
  ```

See program `reverse.c`

#### `sizeof` operator

Determining the size of an array, assuming `a` is an array of ten integers
- `sizeof(a)` is either 20 or 40 depending on whether integers are 16 or 32 bits long. To get the a more useful length, divide this number by the size of an array element: `sizeof(a) / sizeof(a[0])`.


### Multidimensional arrays (matrices)

Array of 5 rows and 9 columns: `int m[5][9]`.

C stores arrays in *row-major* order (`m[0][0] ... m[0,8], m[1][0] ... `).

Note that a more flexible way to store multidimensional data in C than multidimensional arrays is to use *arrays of pointers*.

See program `deal.c`.


### Tricky bits

- The assignment `a = b` where both `a` and `b` are arrays, is illegal. You'll need to loop that copies the elements of `a` into `b` one by one:
```
for (i = 0; i < N; i++) {
  a[i] = b[i];
}
```
- Alternatively, use `memcpy` (memory copy) from `string.h`: `memcpy(a, b, sizeof(a));`. This is potentially faster than an ordinary loop, and is preferred.
