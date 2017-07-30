# Chapter 11: Pointers

See also chapter 12 and 17.

To print the value of a pointer: `printf("%p", pointer_variable)`

### Contents

- [Pointer variables](#pointer-variables): machine addresses and their relationships to pointer variables
- [Address and indirection operators](#operators)
- [Pointer assignment](#pointer-assignment)
- [Passing pointers to functions](#pointers-as-arguments)
- [Returning pointers from functions](#pointers-as-return-values)

## <a name="pointer-variables"></a>Pointer variables

Memory is divided into *bytes*, with each byte capable of storing eight *bits* of information. Each byte has a unique **address** to distinguish it from other bytes in memory. Think of addresses as numbers ranging from 0 - *n*-1, where n is the number of bytes in memory.

Each variable occupies one or more bytes of memory: the address of the first byte is (said to be) the address of the variable.

Although we can think of addresses as integers, they can't be stored as integers. We can, however, store them as special *pointer variables.*

Given a variable *i*, we can store its address in the pointer variable *p*. Then we say that "p points to i". Therefore, **a pointer is simply an address**, and **a pointer variable is a variable that can store an address**.

### Declaring pointer variables

- The name of a pointer variable must be preceded with an asterisk: `int *p;` (a pointer variable capable of pointing to objects of type `int`.)
- There are no restrictions on what the referenced type may be:
  - `int *p;`
  - `float*q;`
  - `char *r;`

## <a name="operators"></a>The address and indirection operators

`*` is the inverse of `&`:
```c
j = *&i; // Same as j = i
```

### Address operator `&`

- To find the address of a variable in memory (e.g. if `x` is a variable: `&x`)
- To initialise a pointer before using it:
```c
int i, *p; // Points nowhere particular
p = &i; // Makes p point to i (doesn't affect i at all)
```
- This can be combined (as long as referenced variable exists first):
```c
int i, *p = &i;
```

### Indirection operator `*`

- To access the object that a pointer points to (e.g. if `p` is a pointer, then `*p` represents the object `p` is pointing to).

```c
// Print the *value* (not *address*) of a variable
// referenced by a pointer
printf("%d\n", *p);
```

- As long as `p` points to `i`, `*p` is an **alias** for i.
- **Changing the value of `*p` also changes the value of `i`.**
- `*p` is an lvalue (can be assigned to).

## <a name="pointer-assignment"></a>Pointer assignment

You can use the assignment operator `=` to copy pointers, provided that they have the same type.

```c
int i, j, *p, *q;
p = &i; // Copy the address of i into p
q = p; // Copy the contents of p (the address of i) into q
// Now q and p point to the same place
// So we can change i by assigning a new value to either *p or *q
*p = 1;
// Now *p == *q == 1
*q = 2;
// Now *p == *q == 2
```

Be careful not to confuse `q = p` and `*q = *p`: the first is pointer assignment, but the second copies the value that p points to, into the location that q points to (rather than referring to the same place, the two variables are different places in memory that have been made to store the same value).

## <a name="pointers-as-arguments"></a>Pointers as arguments

By passing a pointer to an argument when calling a function, the function can change the variable's value.

Because C passes arguments by value, without pointers it is not possible for a function to modify variables passed to it.

Example:

```c
void decompose(float, int *, float*);

void decompose(float x, int *int_part, float *frac_part) {
  *int_part = (int) x;
  *frac_part = x - *int_part
}

// Calling decompose (pointers to i and f, not their values)
decompose(3.14159, &i, &f);
```

The call to `decompose` first puts the value 3 into i, and 0.14159 into f. The function has mutated the values at the addresses of the pointers, so does not need to return any value.

Compare this to the way `scanf` takes arguments (hint: it's the same):

```c
int i;
// Give scanf a pointer to i so that it can put the
// value it reads there
scanf("%d", &i);
```

You could also do:

```c
int i, *p;
p = &i;
scanf("%d", p);
```

**Be very careful with functions that take pointers as arguments, because the function cannot tell if it has been passed a pointer or a value. Accidentally passing a value where a pointer is expected can have dire consequences: writing to unknown memory locations (perhaps used by the OS leading to a system crash).** This can be avoided by strictly using function prototypes so that the compiler will issue a warning. However this cannot always e reliably detected (e.g. in a call to `scanf`).

In C++ it is possible for functions to modify arguments without passing pointers.

### Using `const` to protect arguments

A function may ask for a pointer argument not because it intends to modify it, but simply because it wants to examine the value at the address (this can be efficient for large values). A function call signature can use the `const` word to document that a function won't change the object whose pointer has been passed:

```c
void f(const int *p) {
  *p = 0; // This will provoke a compiler warning
}
```

## <a name="pointers-as-return-values"></a>Pointers as return values

Functions can not only accept pointers as function arguments, but also return pointers. (This is quite common.)

Example, a function that takes pointers to two integer variables, and returns a pointer to whichever is larger:

```c
int *max(int *a, int *b) {
  if (*a > *b) {
    return a;
  } else {
    return b;
  }
}

main() {
  int *p, x, y;
  p = max(&x, &y);
  // p now points to either x or y
}
```

Other possibilities:

- Returning a pointer to one element of an array passed as an argument
- Return a pointer to an external variable, or local variable that is `static`.
- Pointers can point to both *data* and *code* itself (e.g. a pointer to a function).
