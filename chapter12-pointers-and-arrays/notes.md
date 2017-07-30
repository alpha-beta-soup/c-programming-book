# Chapter 12: Pointers and Arrays

See also chapter 11, 13 (strings) and 17.

Am alternative way of processing arrays in which pointers take the place of array subscripts

### Contents

- [Pointer arithmetic](#pointer-arithmetic): comparing pointers using relational and equality operators.
- [Using pointers for array processing](#array-processing): pointer arithmetic for processing array elements.
- [Using an array name as a pointer](#array-name-as-pointer)
- [Pointers and multidimensional arrays](#pointers-and-multidimensional-arrays)

## <a name="pointer-arithmetic"></a>Pointer arithmetic

Pointers can also point to array elements, not just ordinary variables.

```c
int a[10], *p;
p = &a[0]
// p now points to the first element of a
*p = 5; // equivalent to a[0] = 5
```

We can then apply *pointer arithmetic* to on pointers:
- Adding an integer to a pointer
- Subtracting an integer from a pointer
- Subtracting two pointers

### Adding an integer to a pointer

Adding an integer `j` to a pointer `p` yields a pointer to the element that is `j` elements after the one that `p` points to (provided that this other element exists).

```c
int a[10], *p, i, j;
p = &a[2]
// p now points to the first element of a
// p + 5 is equivalent to a[2+5] == a[7];
```

You can also define a pointer `q` that is defined relative to an existing pointer `p`:

```c
p = &a[2];
q = p + 3; // q points to element 3 elements after the element p is pointing at
p + 4; // This doesn't affect the definition of q
```

### Subtracting an integer from a pointer

Works similarly to addition.

```c
p = &a[8];
q = p - 3;
p -= 6;
```

### Subtracting pointers

When two pointers are subtracted, the result is the distance (measured in array elements) between the pointers.

```c
p = &a[5];
q = &a[1];

i = p - q; // i is 4
i = q - p; // i is -4
```

## <a name="array-processing"></a>Using pointers for array processing

Using pointer arithmetic we can iterate through an array by incrementing a pointer variable.

```c
// Sums an array
#define N 10

int a[N], sum, *p;

sum = 0;
for (p = &a[0]; p < &a[N]; p++)
  sum += *p;
```

### Combining `*` and `++` operators

```c
// Store value into an array element, and then advance to next element
a[i++] = j;
// is equivalent to
*p++ = j; // ++ (postfix) takes precedence over *, and the value of p++ is p because the increment only happens after the expression is validated
```

This is actually quite common, and we could re-write the summing function with it:

```c
p = &a[0];
while (p < &a[N])
  sum += *p++;
```

## <a name="array-name-as-pointer"></a>Using an array name as a pointer

## <a name="pointers-and-multidimensional-arrays"></a>Pointers and multidimensional arrays
